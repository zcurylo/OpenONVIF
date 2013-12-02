
#include <sys/stat.h>

#include "NotificationProducer.h"
#include "Web.nsmap"

NotificationProducer::NotificationProducer( BaseServer * pBaseServer, struct soap* pData ) :
    service_(this, pBaseServer, pData),
    clientSoap_(soap_new()),
    shutdownFlag_(false)
{
    pthread_mutex_init(&mutex_, NULL);
}

NotificationProducer::~NotificationProducer() {
    if( !clientSoap_ )
        return;
    soap_destroy( clientSoap_ );
    soap_end( clientSoap_ );
    soap_free( clientSoap_ );
}



int NotificationProducer::dispatch() {
    return service_.dispatch();
}

void NotificationProducer::destroy() {
    service_.destroy();
}

bool NotificationProducer::init() {
    if( pthread_create(&thread_, NULL, &NotificationProducer::notifyFunc, this ) != 0) {
        SIGRLOG (SIGRWARNING, "NotificationProducer::Init failed to create serv" );
        return false;
    }
    return true;
}

bool NotificationProducer::addConsumer( const std::string& consumerEndpoint ) {
    bool bRet = false;
    pthread_mutex_lock( &mutex_ );
    if( std::find( subscribers_.begin(), subscribers_.end(), consumerEndpoint ) == subscribers_.end() ) {
        subscribers_.push_back( consumerEndpoint );
        bRet = true;
    }

    pthread_mutex_unlock( &mutex_ );
    return bRet;
}

void NotificationProducer::stop() {
    SIGRLOG (SIGRDEBUG2, "NotificationProducer::stop enter" );
    pthread_mutex_lock( &mutex_ );
    shutdownFlag_ = true;
    pthread_mutex_unlock( &mutex_ );
    pthread_join(thread_, NULL);
    SIGRLOG (SIGRDEBUG2, "NotificationProducer::stop thread exited" );
}

void*
NotificationProducer::notifyFunc(void* ptr) {
    int fd;
    char buffer[BUFFER_LEN];
    NotificationProducer* prod = static_cast<NotificationProducer*>(ptr);
    if(!prod) {
        SIGRLOG (SIGRWARNING, "NotificationProducer::notifyFunc Erroneous arg");
        return NULL;
    }

    if( (fd = open (USER_EVENT_FIFO, O_RDONLY)) < 0 ) {
        SIGRLOG (SIGRWARNING, "NotificationProducer::notifyFunc Could not open named pipe.");
        return NULL;
    }

    EventingClient client("", prod->clientSoap_);
    pthread_mutex_t* pMutex = &prod->mutex_;
    soap_header(client.getProxySoap());
    client.getProxySoap()->header->wsa5__Action = (char *) soap_malloc( client.getProxySoap(), 1024 );
    strcpy(client.getProxySoap()->header->wsa5__Action, "http://docs.oasis-open.org/wsn/bw-2/NotificationConsumer/Notify");
    client.getProxySoap()->header->wsa__MessageID = NULL;
    client.getProxySoap()->header->wsa__To = NULL;
    client.getProxySoap()->header->wsa__Action = NULL;
    soap_set_namespaces(client.getProxySoap(), Web_namespaces);

    while(1) {
        bzero(buffer, BUFFER_LEN);
        int amount;
        if (( amount = read( fd, buffer, MSG_LEN) ) < 0 ) {
            SIGRLOG (SIGRWARNING, "NotificationProducer::notifyFunc Error reading pipe.");
            unlink(USER_EVENT_FIFO);
            return NULL;
        }
        SIGRLOG (SIGRDEBUG2, "NotificationProducer::notifyFunc readed [%s]", buffer);

        if(amount == 0)
            break;

        bool bCont = false;
        bool bBreak = false;
        pthread_mutex_lock( pMutex );
            if( prod->subscribers_.size() == 0 ) bCont = true;
            if( prod->shutdownFlag_ ) { bBreak = true;
            SIGRLOG (SIGRDEBUG2, "NotificationProducer::notifyFunc break");}
        pthread_mutex_unlock( pMutex );
        if(bBreak) break;
        if(bCont) continue;


        if( NULL != strstr(buffer, MSG_NAME) ) {
            SIGRLOG (SIGRDEBUG2, "NotificationProducer::notifyFunc match");

            EvntNotify req(client.getProxySoap());
            wsnt__NotificationMessageHolderType *holder = soap_instantiate_wsnt__NotificationMessageHolderType(client.getProxySoap(), -1, "", "", NULL);
            wsnt__TopicExpressionType * topic = soap_instantiate_wsnt__TopicExpressionType( client.getProxySoap(), -1, "", "", NULL );
            topic->Dialect = "http://docs.oasis-open.org/wsn/t-1/TopicExpression/Concrete";
            holder->Topic = topic;
            holder->SubscriptionReference = NULL;
            holder->ProducerReference = NULL;
            req.d->NotificationMessage.push_back(holder);

            pthread_mutex_lock( pMutex );
            std::vector<std::string> localSubs =  prod->subscribers_;
            pthread_mutex_unlock( pMutex );

            for( std::vector<std::string>::const_iterator it = localSubs.begin();
                 it != localSubs.end(); ++it ) {
                SIGRLOG (SIGRDEBUG2, "NotificationProducer::notifyFunc send it %s", it->c_str());
                client.setEndpoint( *it );
                client.Notify(req);
            }
        }
    }
    close(fd);
}
