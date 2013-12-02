#ifndef NOTIFICATION_PRODUCER_H__
#define NOTIFICATION_PRODUCER_H__
#include "pthread.h"
#include <algorithm>
#include "EventingClient.h"
#include "EventingServiceImpl.h"

// userEvents expects following messages
#define BUFFER_LEN 128
#define MSG_LEN 80
#define MSG_NAME "OnvifSDKMessage"

class NotificationProducer
{
public:
    NotificationProducer( BaseServer * pBaseServer, struct soap* pData );
    ~NotificationProducer();

    bool init();
    int dispatch();
    void destroy();
    bool addConsumer( const std::string& consumerEndpoint );
    void stop();
private:
    static void* notifyFunc(void* Producer);

    bool shutdownFlag_;
    int userEventsSocket_;
    std::vector<std::string> subscribers_;
    pthread_t thread_;
    pthread_mutex_t mutex_;
    soap* clientSoap_;
    EventingServiceImpl service_;
};

#endif // NOTIFICATION_PRODUCER_H__
