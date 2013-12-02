
#include "BaseServer.h"

static GeneratorInitializer generatorInitializer;

std::string GenerateToken()
{
    std::string str;

    for(unsigned int i = 0; i < TOKEN_LEN; ++i)
        str += alphanum[rand() % stringLength];

    return str;
};

IOnvifServer* getOnvifServer()
{
    return static_cast<IOnvifServer*>( new BaseServer() );
}

void deleteOnvifServer(IOnvifServer* obj) {
    BaseServer::deleteObject(obj);
}

BaseServer::BaseServer():
    m_pSoap(soap_new())
{
}

MedProfile
BaseServer::CreateMediaProfile(const std::string& name, const std::string& token) {
    return MedProfile(m_pSoap, name , token);
}

MedVideoSource
BaseServer::CreateVideoSource(const std::string &token, int w, int h, double frmRate) {
    return MedVideoSource(m_pSoap, token, w, h, frmRate);
}


int BaseServer::Init(int iServicesToHost, IOnvif *pHandler)
{
    m_pHandler = pHandler;
    m_DevService     = (iServicesToHost & DEV_S)    ? new DeviceServiceImpl(this, m_pSoap)   : NULL;
    m_DevIOService   = (iServicesToHost & DEVIO_S)  ? new DeviceIOServiceImpl(this, m_pSoap) : NULL;
    m_DispService    = (iServicesToHost & DISP_S)   ? new DisplayServiceImpl(this, m_pSoap)  : NULL;
    m_RecvService    = (iServicesToHost & RECV_S)   ? new ReceiverServiceImpl(this, m_pSoap) : NULL;
    m_ReplayService  = (iServicesToHost & REPLAY_S) ? new ReplayServiceImpl(this, m_pSoap)   : NULL;
    m_RecordService  = (iServicesToHost & RECORD_S) ? new RecordingServiceImpl(this, m_pSoap): NULL;
    m_SearchService  = (iServicesToHost & SEARCH_S) ? new SearchServiceImpl(this, m_pSoap)   : NULL;
    m_MediaService   = (iServicesToHost & MEDIA_S)  ? new MediaServiceImpl(this, m_pSoap)    : NULL;
    m_AnService      = (iServicesToHost & ANALY_S)  ? new AnalyticsServiceImpl(this, m_pSoap): NULL;
    m_NotsProducer   = (iServicesToHost & EVNT_S)   ? new NotificationProducer(this, m_pSoap): NULL;
    m_pWsdd = new Discoverable();

    int iRet = RunWsDiscovery();
    if(iRet != 0) {
        SIGRLOG (SIGRWARNING, "BaseServer::Run RunWsDiscovery failed");
        return -1;
    }

    if(m_NotsProducer && (! m_NotsProducer->init()) ) {
        SIGRLOG (SIGRWARNING, "BaseServer::Run NotificationProducer init failed");
        return -1;
    }

    m_bCreated = m_pSoap && m_DevService && m_pHandler && (iRet == 0);
    return m_bCreated ? 0 : -1;
}

BaseServer::~BaseServer()
{
    if(m_NotsProducer)
        m_NotsProducer->stop();
    if(m_pWsdd) {
        m_pWsdd->stop();
        delete  m_pWsdd;
        m_pWsdd = NULL;
    }

    deleteService(m_RecvService);
    deleteService(m_DispService);
    deleteService(m_DevIOService);
    deleteService(m_DevService);
    deleteService(m_ReplayService);
    deleteService(m_RecordService);
    deleteService(m_SearchService);
    deleteService(m_MediaService);
    deleteService(m_AnService);
    deleteService(m_NotsProducer);
    if(m_pSoap) {
        soap_destroy(m_pSoap);
        soap_end(m_pSoap);
        soap_free(m_pSoap);
    }
}

int BaseServer::Run() {
    if(!m_bCreated) {
        SIGRLOG(SIGRCRITICAL, "BaseServer::Run Services were not created");
        return -1;
    }

    int iRet = soap_bind(m_pSoap, NULL, m_webservicePort, 100);

    if (iRet == SOAP_INVALID_SOCKET) {
        SIGRLOG(SIGRCRITICAL, "BaseServer::Run Binding on %d port failed", m_webservicePort);
        return -1;
    }

    while(1)
    {
        iRet = soap_accept(m_pSoap);
        if (iRet == SOAP_INVALID_SOCKET) {
            SIGRLOG(SIGRCRITICAL, "BaseServer::Run accepting failed");
            return -1;
        }

        iRet = soap_begin_serve(m_pSoap);
        if ( iRet != SOAP_OK) {
            SIGRLOG(SIGRWARNING, "BaseServer::Run serve %d failed", iRet);
            continue;
        }

        if (m_DevService)
            iRet = m_DevService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_DevIOService)
            iRet = m_DevIOService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_DispService)
            iRet = m_DispService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_RecvService)
            iRet = m_RecvService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_ReplayService)
            iRet = m_ReplayService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_RecordService)
            iRet = m_RecordService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_MediaService)
            iRet = m_MediaService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_SearchService)
            iRet = m_SearchService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_AnService)
            iRet = m_AnService->dispatch();

        if (iRet == SOAP_OK)
            continue;

        if (m_NotsProducer)
            iRet = m_NotsProducer->dispatch();

        if(iRet != SOAP_OK)
            SIGRLOG(SIGRWARNING, "BaseServer::Run SOAP_Error= %d at %s", iRet, m_pSoap->action);
    }

    return 0;
}

int BaseServer::SetDeviceInfo( OnvifDevice::Type type,
                               const std::string & manufacturer,
                               const std::string & model,
                               const std::string & firmwareVersion,
                               const std::string & serialNumber,
                               const std::string & hardwareId,
                               const std::string & scopes,
                               const std::string & interface,
                               int webservicePort ) {
    return DeviceInfoStorage::SetDeviceInfo( type, manufacturer, model,
                                             firmwareVersion, serialNumber, hardwareId,
                                             scopes, interface, webservicePort );
}

int BaseServer::RunWsDiscovery()
{
	if(!m_pWsdd)
		return -1;
    return m_pWsdd->start(true, this);
}

std::string
BaseServer::GetIp() {
    return DeviceInfoStorage::getInterfaceIp("eth0");
}

int BaseServer::GetDateAndTime( DevGetSystemDateAndTimeResponse & r)
{
    return m_pHandler->GetDateAndTime(r);
}

int BaseServer::SetDateAndTime( DevSetSystemDateAndTime & r)
{
    return m_pHandler->SetDateAndTime(r);
}

int BaseServer::GetUsers( /*out*/ DevGetUsersResponse & r)
{
    return m_pHandler->GetUsers(r);
}

//===DEVIO============================
int BaseServer::GetVideoOutputs( /*out*/ DevIOGetVideoOutputsResponse & r)
{
    return m_pHandler->GetVideoOutputs(r);
}

//===DISP=============================
int BaseServer::GetLayout( std::string & token, /*out*/ DispGetLayoutResponse & resp)
{
    return m_pHandler->GetLayout(token, resp);
}

int BaseServer::GetDisplayOptions( const std::string & token, DispGetDisplayOptionsResponse & resp)
{
    return m_pHandler->GetDisplayOptions(token, resp);
}

int BaseServer::SetLayout(DispSetLayout &r)
{
    return m_pHandler->SetLayout(r);
}

int BaseServer::CreatePaneConfiguration( DispCreatePaneConfiguration & req, /*out*/ DispCreatePaneConfigurationResponse & resp)
{
    return m_pHandler->CreatePaneConfiguration(req, resp);
}

//===RECV=============================
int BaseServer::GetReceivers( RecvGetReceiversResponse & r)
{
    return m_pHandler->GetReceivers(r);
}

int BaseServer::CreateReceiver( const std::string & uri, /*out*/ std::string & recvToken )
{
    return m_pHandler->CreateReceiver(uri, recvToken);
}

int BaseServer::SetReceiverMode( const std::string & recvToken, bool bMode )
{
    return m_pHandler->SetReceiverMode(recvToken, bMode);
}

//===RECORDING=========================
int BaseServer::CreateRecording (RecCreateRecording & req, RecCreateRecordingResponse & resp)
{
    return m_pHandler->CreateRecording(req, resp);
}

int BaseServer::CreateRecordingJob (RecCreateRecordingJob & req, RecCreateRecordingJobResponse & resp)
{
    return m_pHandler->CreateRecordingJob(req, resp);
}

int BaseServer::DeleteRecording (const std::string & str)
{
    return m_pHandler->DeleteRecording(str);
}

int BaseServer::DeleteRecordingJob (const std::string &str)
{
    return m_pHandler->DeleteRecordingJob(str);
}

//===MEDIA=============================
int
BaseServer::GetProfile( const std::string & profileToken,
                        MedGetProfileResponse & resp) {
    return m_pHandler->GetProfile(profileToken, resp);
}

int
BaseServer::GetProfiles( MedGetProfilesResponse & r) {
    return m_pHandler->GetProfiles(r);
}

int
BaseServer::GetVideoSources( MedGetVideoSourcesResponse & r) {
    return m_pHandler->GetVideoSources(r);
}

int
BaseServer::GetStreamUri( const std::string& token,
                          std::string & uri) {
    return m_pHandler->GetStreamUri(token, uri);
}

int
BaseServer::GetCompatibleVideoEncoderConfigurations(MedGetCompatibleVideoEncoderConfigurationsResponse& resp) {
    return m_pHandler->GetCompatibleVideoEncoderConfigurations(resp);
}

int
BaseServer::GetCompatibleVideoAnalyticsConfigurations(MedGetCompatibleVideoAnalyticsConfigurationsResponse& resp) {
    return m_pHandler->GetCompatibleVideoAnalyticsConfigurations(resp);
}
