#ifndef BASESERVER_H
#define BASESERVER_H

#include "sigrlog.h"
#include "OnvifSDK.h"
#include "stringGenerator.h"
#include "DeviceInfoStorage.h"
#include "discoverable.h"

#include "DeviceServiceImpl.h"
#include "DeviceIOServiceImpl.h"
#include "DisplayServiceImpl.h"
#include "ReceiverServiceImpl.h"
#include "ReplayServiceImpl.h"
#include "MediaServiceImpl.h"
#include "RecordingServiceImpl.h"
#include "SearchServiceImpl.h"
#include "AnalyticsServiceImpl.h"
#include "NotificationProducer.h"

class BaseServer : public DeviceInfoStorage,
                   public IOnvifServer,
                   public IOnvif
{
public:
    BaseServer();
    static void deleteObject(IOnvifServer* obj) {
        BaseServer* servObj = static_cast<BaseServer*> (obj);
        if(servObj)
            delete servObj;
    }

	virtual ~BaseServer();
    virtual int Init(int iServicesToHost, IOnvif* pHandler);
	virtual int Run();
    virtual MedProfile CreateMediaProfile(const std::string &name, const std::string &token);
    virtual MedVideoSource CreateVideoSource(const std::string &token, int w, int h, double frmRate);
    virtual std::string GetIp();

    int SetDeviceInfo( OnvifDevice::Type type,
                       const std::string & manufacturer,
                       const std::string & model,
                       const std::string & firmwareVersion,
                       const std::string & serialNumber,
                       const std::string & hardwareId,
                       const std::string & scopes,
                       const std::string & interface,
                       int webservicePort );

	//===DEV==============================
    virtual int GetDateAndTime( /*out*/ DevGetSystemDateAndTimeResponse & );
    virtual int SetDateAndTime( DevSetSystemDateAndTime & );
    virtual int GetUsers( /*out*/ DevGetUsersResponse & );

    //===DEVIO============================
    virtual int GetVideoOutputs( /*out*/ DevIOGetVideoOutputsResponse & );

    //===DISP=============================
    virtual int GetLayout( std::string &, /*out*/ DispGetLayoutResponse & );
    virtual int GetDisplayOptions( const std::string &, /*out*/ DispGetDisplayOptionsResponse & );
    virtual int SetLayout( DispSetLayout &);
    virtual int CreatePaneConfiguration( DispCreatePaneConfiguration &, /*out*/ DispCreatePaneConfigurationResponse & );

    //===RECV=============================
    virtual int GetReceivers( RecvGetReceiversResponse & );
    virtual int CreateReceiver( const std::string & uri, /*out*/ std::string & recvToken );
    virtual int SetReceiverMode( const std::string & recvToken, bool bMode );

    //===RECORDING=========================
    virtual int CreateRecording (RecCreateRecording &, RecCreateRecordingResponse &);
    virtual int CreateRecordingJob (RecCreateRecordingJob &, RecCreateRecordingJobResponse &);
    virtual int DeleteRecording (const std::string &);
    virtual int DeleteRecordingJob (const std::string &);

    //===MEDIA==============================
    virtual int GetProfile(const std::string & profileToken, MedGetProfileResponse & resp);
    virtual int GetProfiles(MedGetProfilesResponse &);
    virtual int GetVideoSources(MedGetVideoSourcesResponse &);
    virtual int GetStreamUri( const std::string& token, std::string & uri);
    virtual int GetCompatibleVideoEncoderConfigurations(MedGetCompatibleVideoEncoderConfigurationsResponse& resp);
    virtual int GetCompatibleVideoAnalyticsConfigurations(MedGetCompatibleVideoAnalyticsConfigurationsResponse& resp);

private:
    BaseServer(const BaseServer&);
    BaseServer& operator=(const BaseServer&);
    virtual int RunWsDiscovery();

    template<typename T> void deleteService(T* service) {
        if(!service)
            return;
        service->destroy();
        delete service;
        service = NULL;
    }

	bool m_bCreated;
	struct soap * m_pSoap;
	DeviceServiceImpl * m_DevService;
	DeviceIOServiceImpl * m_DevIOService;
	DisplayServiceImpl * m_DispService;
	ReceiverServiceImpl * m_RecvService;
    ReplayServiceImpl * m_ReplayService;
    RecordingServiceImpl * m_RecordService;
    SearchServiceImpl * m_SearchService;
    MediaServiceImpl * m_MediaService;
    NotificationProducer * m_NotsProducer;
    AnalyticsServiceImpl * m_AnService;
    Discoverable * m_pWsdd;
    IOnvif* m_pHandler;
};

#endif	// BASESERVER_H
