#ifndef ONVIF_SDK__H
#define ONVIF_SDK__H

#include <string>
#include <vector>

#define CLASS_DEFINITION_BEGIN(gSoapPrefix, servicePrefix, classname) \
    class _ ## gSoapPrefix ## __ ## classname; \
	class servicePrefix ## classname \
    { \
    public: \
        servicePrefix ## classname ( soap * ); \
        servicePrefix ## classname ( _ ## gSoapPrefix ## __ ## classname * ); \
        _ ## gSoapPrefix ## __ ## classname * d;

#define CLASS_DEFINITION_END() \
	};

class soap;

/////////////////////////////////////////////////////////////////////////////////////
// DeviceMgmt ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(tds, Dev, SetSystemDateAndTime)
    int GetUTCDateAndTime(int & year, int & month, int & day, int & hour, int & min, int & sec) const;
    int SetUTCDateAndTime(int year, int month, int day, int hour, int min, int sec);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, SetSystemDateAndTimeResponse)
CLASS_DEFINITION_END()


/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetSystemDateAndTime)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, GetSystemDateAndTimeResponse)
    int SetUTCDateAndTime(int year, int month, int day, int hour, int min, int sec);
    int GetUTCDateAndTime(int & year, int & month, int & day, int & hour, int & min, int & sec) const;
CLASS_DEFINITION_END()


/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetUsers)
CLASS_DEFINITION_END()


CLASS_DEFINITION_BEGIN(tds, Dev, GetUsersResponse)
    int AddUser(std::vector<std::string> user);
    int GetUsers(std::vector<std::string> & users) const;
CLASS_DEFINITION_END()


/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetDeviceInformation)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, GetDeviceInformationResponse)
    int SetDeviceInfo(std::string strManufacturer, std::string strModel,
                      std::string strFirmwareVersion, std::string strSerialNumber,
                      std::string strHardwareId);
    int GetDeviceInfo(std::string & strManufacturer, std::string & strModel,
                      std::string & strFirmwareVersion, std::string & strSerialNumber,
                      std::string & strHardwareId) const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetCapabilities)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, GetCapabilitiesResponse)
    int SetDeviceCapabilities(const std::string & xaddr);
    int SetEventsCapabilities(const std::string & xaddr);
    int SetMediaCapabilities(const std::string & xaddr);
    int SetAnalyticsCapabilities(const std::string & xaddr);
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetServices)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, GetServicesResponse)
    int AddService(const std::string &nameSpace, const std::string &xaddr);
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tds, Dev, GetScopes)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tds, Dev, GetScopesResponse)
    int AddItems( const std::vector<std::string> & scopes );
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// DeviceIO /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tmd, DevIO, GetVideoOutputs)
CLASS_DEFINITION_END()


CLASS_DEFINITION_BEGIN(tmd, DevIO, GetVideoOutputsResponse)
    int SetVideoOutputs(const std::string & videoOutput);
    int GetVideoOutputs(std::string & videoOutput) const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// Display //////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

struct DispRectangle
{
    float bot;
    float top;
    float left;
    float right;
};

CLASS_DEFINITION_BEGIN(tls, Disp, GetLayout)
    int GetLayout(std::string & str) const;
    int SetLayout(const std::string & str);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tls, Disp, GetLayoutResponse)
    int SetLayout(const std::string & str);
    int GetLayout(std::string & str) const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tls, Disp, GetDisplayOptions)
    int GetVO(std::string & str) const;
    int SetVO(const std::string & str);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tls, Disp, GetDisplayOptionsResponse)
    int Set4FixedLayouts(const float flayout1[1*4], const float flayout4[4*4],
                         const float flayout9[9*4], const float flayout16[16*4]);
    int GetLayoutOptions(std::vector< std::vector<DispRectangle> > & layoutOptions) const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tls, Disp, SetLayout)
    int GetVO(std::string & vo);
    int GetLayout(std::vector<std::pair<std::string, DispRectangle > > & panelayouts);
    int SetVO(const std::string & vo);
    int SetLayout(const std::vector< std::pair<std::string, DispRectangle > > & panelayouts);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tls, Disp, SetLayoutResponse)
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(tls, Disp, CreatePaneConfiguration)
    int GetPaneConfig(std::string & videoOutput,
                      std::string & paneToken,
                      std::string & receiverToken) const;
    int SetPaneConfig(const std::string & videoOutput,
                      const std::string & paneToken,
                      const std::string & receiverToken);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(tls, Disp, CreatePaneConfigurationResponse)
    int SetPaneConfigToken(const std::string & paneConfigToken);
    int GetPaneConfigToken(std::string & paneConfigToken) const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// Receiver /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(trv, Recv, GetReceivers)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trv, Recv, GetReceiversResponse)
    int SetReceivers(std::string & str);
    int GetReceivers(std::string & str) const;
CLASS_DEFINITION_END()
/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(trv, Recv, CreateReceiver)
    bool getMode() const;
    void setMode( const bool );
    std::string getUri() const;
    void setUri( const std::string & );
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trv, Recv, CreateReceiverResponse)
    void setToken( const std::string & str );
    std::string getToken() const;
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

CLASS_DEFINITION_BEGIN(trv, Recv, SetReceiverMode)
    bool getMode() const;
    void setMode( bool );
    std::string getToken() const;
    void setToken( const std::string & );
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trv, Recv, SetReceiverModeResponse)
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// RecordingControl /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(trc, Rec, CreateRecording)
    void setSource (const std::string & id, const std::string & address);
    void getSource (std::string & id, std::string & address) const;
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trc, Rec, CreateRecordingResponse)
    const std::string & getToken() const;
    void setToken(const std::string &);
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(trc, Rec, DeleteRecording)
    const std::string & getToken() const;
    void setToken(const std::string &);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trc, Rec, DeleteRecordingResponse)
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(trc, Rec, CreateRecordingJob)
    const std::string & getRecording() const;
    void setRecording(const std::string &);
    bool getMode() const;
    void setMode(bool);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trc, Rec, CreateRecordingJobResponse)
    const std::string & getToken() const;
    void setToken(const std::string &);
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(trc, Rec, DeleteRecordingJob)
    const std::string & getToken() const;
    void setToken(const std::string &);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trc, Rec, DeleteRecordingJobResponse)
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// Eventing /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
CLASS_DEFINITION_BEGIN(wsnt, Evnt, Subscribe)
    void setAddress(const std::string & address);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(wsnt, Evnt, SubscribeResponse)
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(wsnt, Evnt, Notify)
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////
// Media ////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
class tt__Profile;
class MedProfile {
    public:
    MedProfile():
        d(NULL) {
    }
    MedProfile(soap* pSoap, const std::string& name, const std::string& token);
    MedProfile(tt__Profile*);
    tt__Profile* d;
    void AddVideoSrc( const std::string & sourceToken, int w, int h );
    void AddVideoEnc( int w, int h );
    void AddVideoAnalytics();
    const std::string & getToken();
};

class tt__VideoSource;
class MedVideoSource {
    public:
    MedVideoSource():
        d(NULL) {
    }
    MedVideoSource(soap * pSoap, const std::string &token, int w, int h, double frmRate );
    const std::string & getToken();
    tt__VideoSource* d;
};


CLASS_DEFINITION_BEGIN(trt, Med, GetProfileResponse)
    void SetProfile( MedProfile&);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trt, Med, GetProfilesResponse)
    void AddProfile( MedProfile&);
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trt, Med, GetVideoSourcesResponse)
    void AddEntry( const std::string & sourceToken,
                   int w, int h, float frmRate );
    void AddEntry( const MedVideoSource &  );
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trt, Med, GetCompatibleVideoEncoderConfigurationsResponse)
    void AddVideoEnc(  int w, int h );
CLASS_DEFINITION_END()

CLASS_DEFINITION_BEGIN(trt, Med, GetCompatibleVideoAnalyticsConfigurationsResponse)
    void AddVideoAn();
CLASS_DEFINITION_END()

/////////////////////////////////////////////////////////////////////////////////////

#define USER_EVENT_FIFO "/tmp/userEventsFIFOOnvifSDK"
#define USER_EVENT_MESSAGE "<?xml version=\"1.0\" encoding=\"UTF-8\"?><OnvifSDKMessage>Motion</OnvifSDKMessage>"

class IOnvif
{
public:

    //===DEV==============================
    virtual int GetDateAndTime( /*out*/ DevGetSystemDateAndTimeResponse & ) = 0;
    virtual int SetDateAndTime( DevSetSystemDateAndTime & ) = 0;
    virtual int GetUsers( /*out*/ DevGetUsersResponse & ) = 0;

    //===DEVIO============================
    virtual int GetVideoOutputs( /*out*/ DevIOGetVideoOutputsResponse & ) = 0;

    //===DISP=============================
    virtual int GetLayout( std::string &, /*out*/ DispGetLayoutResponse & ) = 0;
    virtual int GetDisplayOptions( const std::string &, DispGetDisplayOptionsResponse & ) = 0;
    virtual int SetLayout( DispSetLayout &) = 0;
    virtual int CreatePaneConfiguration( DispCreatePaneConfiguration &, /*out*/ DispCreatePaneConfigurationResponse & ) = 0;

    //===RECV=============================
    virtual int GetReceivers( RecvGetReceiversResponse & ) = 0;
    virtual int CreateReceiver( const std::string & uri, /*out*/ std::string & recvToken ) = 0;
    virtual int SetReceiverMode( const std::string & recvToken, bool bMode ) = 0;

    //===RECORDING=========================
    virtual int CreateRecording (RecCreateRecording &, RecCreateRecordingResponse &) = 0;
    virtual int CreateRecordingJob (RecCreateRecordingJob &, RecCreateRecordingJobResponse &) = 0;
    virtual int DeleteRecording (const std::string &) = 0;
    virtual int DeleteRecordingJob (const std::string &) = 0;

    //===MEDIA==============================
    virtual int GetProfile(const std::string & profileToken, MedGetProfileResponse & resp) = 0;
    virtual int GetProfiles(MedGetProfilesResponse &) = 0;
    virtual int GetVideoSources(MedGetVideoSourcesResponse &) = 0;
    virtual int GetStreamUri( const std::string& token, std::string & uri) = 0;
    virtual int GetCompatibleVideoEncoderConfigurations(MedGetCompatibleVideoEncoderConfigurationsResponse& resp) = 0;
    virtual int GetCompatibleVideoAnalyticsConfigurations(MedGetCompatibleVideoAnalyticsConfigurationsResponse& resp) = 0;
};

typedef enum _Services
{
    DEV_S    = 2,
    DEVIO_S  = 4,
    DISP_S   = 8,
    RECV_S   = 16,
    REPLAY_S = 32,
    RECORD_S = 64,
    SEARCH_S = 128,
    EVNT_S   = 256,
    MEDIA_S  = 512,
    ANALY_S  = 1024
} Services;

namespace OnvifDevice {
    typedef enum _Type
    {
        Default = 0,
        NVT,
        NVD,
        NVR
    } Type;
}

class IOnvifServer
{
public:
    virtual int Init(int iServicesToHost, IOnvif* pHandler) = 0;
    virtual int SetDeviceInfo( OnvifDevice::Type type,
                               const std::string & manufacturer,
                               const std::string & model,
                               const std::string & firmwareVersion,
                               const std::string & serialNumber,
                               const std::string & hardwareId,
                               const std::string & scopes,
                               const std::string & interface,
                               int webservicePort ) = 0;
    virtual MedProfile CreateMediaProfile(const std::string &name, const std::string &token) = 0;
    virtual MedVideoSource CreateVideoSource(const std::string &token, int w, int h, double frmRate) = 0;
    virtual std::string GetIp() = 0;
    virtual int Run() = 0;
};

IOnvifServer* getOnvifServer();
void deleteOnvifServer(IOnvifServer*);

class DiscoveryMatch
{
public:
    DiscoveryMatch(){}
    DiscoveryMatch( const std::string & type,
                    const std::string & xaddr,
                    const std::string & scopes ):
        type_(type),
        xaddr_(xaddr),
        scopes_(scopes) {}

    std::string type_;
    std::string xaddr_;
    std::string scopes_;
};

typedef void (*notificationCatcherFunc)( const char * );

class IOnvifClient : public IOnvif
{
public:
    virtual int Init(const char* pchEndpoint) = 0;
    virtual std::vector<DiscoveryMatch> DiscoverDevices( OnvifDevice::Type type ) = 0;
    virtual void Subscribe() = 0;
    virtual bool SetNotificationCatcher(notificationCatcherFunc func) = 0;
    virtual soap* GetSoap() = 0;
};

IOnvifClient* getOnvifClient();

std::string GenerateToken();

#endif // ONVIF_SDK__H
