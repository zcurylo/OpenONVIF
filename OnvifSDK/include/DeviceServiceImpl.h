#ifndef WebDeviceBindingServiceImpl_H
#define WebDeviceBindingServiceImpl_H

#include "OnvifSDK.h"

#ifdef DEV_S
#include "WebDeviceBindingService.h"
#include "onvifService.h"

class BaseServer;

class DeviceServiceImpl:
        public IOnvifService,
        public DeviceBindingService
{
private:
    IOnvifDevMgmt * handler_;
    BaseServer * baseServer_;
public:
    DeviceServiceImpl( BaseServer * baseServer,
                       IOnvifDevMgmt * handler,
                       struct soap * pData):
        DeviceBindingService(pData),
        handler_(handler),
        baseServer_(baseServer)	{
    }

	virtual DeviceBindingService* copy();

    virtual int dispatch() {
        return DeviceBindingService::dispatch();
    }

    virtual void destroy() {
        DeviceBindingService::destroy();
    }

	/// Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
	virtual	int GetServiceCapabilities(_trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse);
	/// Web service operation 'GetVideoSources' (returns error code or SOAP_OK)
	virtual	int GetVideoSources(_trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse) ;

	/// Web service operation 'GetAudioSources' (returns error code or SOAP_OK)
	virtual	int GetAudioSources(_trt__GetAudioSources *trt__GetAudioSources, _trt__GetAudioSourcesResponse &trt__GetAudioSourcesResponse) ;

	/// Web service operation 'GetAudioOutputs' (returns error code or SOAP_OK)
	virtual	int GetAudioOutputs(_trt__GetAudioOutputs *trt__GetAudioOutputs, _trt__GetAudioOutputsResponse &trt__GetAudioOutputsResponse) ;

	/// Web service operation 'CreateProfile' (returns error code or SOAP_OK)
	virtual	int CreateProfile(_trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse) ;

	/// Web service operation 'GetProfile' (returns error code or SOAP_OK)
	virtual	int GetProfile(_trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse) ;

	/// Web service operation 'GetProfiles' (returns error code or SOAP_OK)
	virtual	int GetProfiles(_trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse) ;

	/// Web service operation 'AddVideoEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int AddVideoEncoderConfiguration(_trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, _trt__AddVideoEncoderConfigurationResponse &trt__AddVideoEncoderConfigurationResponse) ;

	/// Web service operation 'AddVideoSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int AddVideoSourceConfiguration(_trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, _trt__AddVideoSourceConfigurationResponse &trt__AddVideoSourceConfigurationResponse) ;

	/// Web service operation 'AddAudioEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int AddAudioEncoderConfiguration(_trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, _trt__AddAudioEncoderConfigurationResponse &trt__AddAudioEncoderConfigurationResponse) ;

	/// Web service operation 'AddAudioSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int AddAudioSourceConfiguration(_trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, _trt__AddAudioSourceConfigurationResponse &trt__AddAudioSourceConfigurationResponse) ;

	/// Web service operation 'AddPTZConfiguration' (returns error code or SOAP_OK)
	virtual	int AddPTZConfiguration(_trt__AddPTZConfiguration *trt__AddPTZConfiguration, _trt__AddPTZConfigurationResponse &trt__AddPTZConfigurationResponse) ;

	/// Web service operation 'AddVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	virtual	int AddVideoAnalyticsConfiguration(_trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, _trt__AddVideoAnalyticsConfigurationResponse &trt__AddVideoAnalyticsConfigurationResponse) ;

	/// Web service operation 'AddMetadataConfiguration' (returns error code or SOAP_OK)
	virtual	int AddMetadataConfiguration(_trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, _trt__AddMetadataConfigurationResponse &trt__AddMetadataConfigurationResponse) ;

	/// Web service operation 'AddAudioOutputConfiguration' (returns error code or SOAP_OK)
	virtual	int AddAudioOutputConfiguration(_trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, _trt__AddAudioOutputConfigurationResponse &trt__AddAudioOutputConfigurationResponse) ;

	/// Web service operation 'AddAudioDecoderConfiguration' (returns error code or SOAP_OK)
	virtual	int AddAudioDecoderConfiguration(_trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, _trt__AddAudioDecoderConfigurationResponse &trt__AddAudioDecoderConfigurationResponse) ;

	/// Web service operation 'RemoveVideoEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveVideoEncoderConfiguration(_trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, _trt__RemoveVideoEncoderConfigurationResponse &trt__RemoveVideoEncoderConfigurationResponse) ;

	/// Web service operation 'RemoveVideoSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveVideoSourceConfiguration(_trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, _trt__RemoveVideoSourceConfigurationResponse &trt__RemoveVideoSourceConfigurationResponse) ;

	/// Web service operation 'RemoveAudioEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveAudioEncoderConfiguration(_trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, _trt__RemoveAudioEncoderConfigurationResponse &trt__RemoveAudioEncoderConfigurationResponse) ;

	/// Web service operation 'RemoveAudioSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveAudioSourceConfiguration(_trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, _trt__RemoveAudioSourceConfigurationResponse &trt__RemoveAudioSourceConfigurationResponse) ;

	/// Web service operation 'RemovePTZConfiguration' (returns error code or SOAP_OK)
	virtual	int RemovePTZConfiguration(_trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, _trt__RemovePTZConfigurationResponse &trt__RemovePTZConfigurationResponse) ;

	/// Web service operation 'RemoveVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveVideoAnalyticsConfiguration(_trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, _trt__RemoveVideoAnalyticsConfigurationResponse &trt__RemoveVideoAnalyticsConfigurationResponse) ;

	/// Web service operation 'RemoveMetadataConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveMetadataConfiguration(_trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, _trt__RemoveMetadataConfigurationResponse &trt__RemoveMetadataConfigurationResponse) ;

	/// Web service operation 'RemoveAudioOutputConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveAudioOutputConfiguration(_trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, _trt__RemoveAudioOutputConfigurationResponse &trt__RemoveAudioOutputConfigurationResponse) ;

	/// Web service operation 'RemoveAudioDecoderConfiguration' (returns error code or SOAP_OK)
	virtual	int RemoveAudioDecoderConfiguration(_trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, _trt__RemoveAudioDecoderConfigurationResponse &trt__RemoveAudioDecoderConfigurationResponse) ;

	/// Web service operation 'DeleteProfile' (returns error code or SOAP_OK)
	virtual	int DeleteProfile(_trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse) ;

	/// Web service operation 'GetVideoSourceConfigurations' (returns error code or SOAP_OK)
	virtual	int GetVideoSourceConfigurations(_trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse) ;

	/// Web service operation 'GetVideoEncoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetVideoEncoderConfigurations(_trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse) ;

	/// Web service operation 'GetAudioSourceConfigurations' (returns error code or SOAP_OK)
	virtual	int GetAudioSourceConfigurations(_trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, _trt__GetAudioSourceConfigurationsResponse &trt__GetAudioSourceConfigurationsResponse) ;

	/// Web service operation 'GetAudioEncoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetAudioEncoderConfigurations(_trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, _trt__GetAudioEncoderConfigurationsResponse &trt__GetAudioEncoderConfigurationsResponse) ;

	/// Web service operation 'GetVideoAnalyticsConfigurations' (returns error code or SOAP_OK)
	virtual	int GetVideoAnalyticsConfigurations(_trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse) ;

	/// Web service operation 'GetMetadataConfigurations' (returns error code or SOAP_OK)
	virtual	int GetMetadataConfigurations(_trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse) ;

	/// Web service operation 'GetAudioOutputConfigurations' (returns error code or SOAP_OK)
	virtual	int GetAudioOutputConfigurations(_trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, _trt__GetAudioOutputConfigurationsResponse &trt__GetAudioOutputConfigurationsResponse) ;

	/// Web service operation 'GetAudioDecoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetAudioDecoderConfigurations(_trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, _trt__GetAudioDecoderConfigurationsResponse &trt__GetAudioDecoderConfigurationsResponse) ;

	/// Web service operation 'GetVideoSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int GetVideoSourceConfiguration(_trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse) ;

	/// Web service operation 'GetVideoEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int GetVideoEncoderConfiguration(_trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse) ;

	/// Web service operation 'GetAudioSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int GetAudioSourceConfiguration(_trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, _trt__GetAudioSourceConfigurationResponse &trt__GetAudioSourceConfigurationResponse) ;

	/// Web service operation 'GetAudioEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int GetAudioEncoderConfiguration(_trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, _trt__GetAudioEncoderConfigurationResponse &trt__GetAudioEncoderConfigurationResponse) ;

	/// Web service operation 'GetVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	virtual	int GetVideoAnalyticsConfiguration(_trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse) ;

	/// Web service operation 'GetMetadataConfiguration' (returns error code or SOAP_OK)
	virtual	int GetMetadataConfiguration(_trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse) ;

	/// Web service operation 'GetAudioOutputConfiguration' (returns error code or SOAP_OK)
	virtual	int GetAudioOutputConfiguration(_trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, _trt__GetAudioOutputConfigurationResponse &trt__GetAudioOutputConfigurationResponse) ;

	/// Web service operation 'GetAudioDecoderConfiguration' (returns error code or SOAP_OK)
	virtual	int GetAudioDecoderConfiguration(_trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, _trt__GetAudioDecoderConfigurationResponse &trt__GetAudioDecoderConfigurationResponse) ;

	/// Web service operation 'GetCompatibleVideoEncoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleVideoEncoderConfigurations(_trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleVideoSourceConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleVideoSourceConfigurations(_trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleAudioEncoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleAudioEncoderConfigurations(_trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, _trt__GetCompatibleAudioEncoderConfigurationsResponse &trt__GetCompatibleAudioEncoderConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleAudioSourceConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleAudioSourceConfigurations(_trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, _trt__GetCompatibleAudioSourceConfigurationsResponse &trt__GetCompatibleAudioSourceConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleVideoAnalyticsConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleVideoAnalyticsConfigurations(_trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleMetadataConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleMetadataConfigurations(_trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleAudioOutputConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleAudioOutputConfigurations(_trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, _trt__GetCompatibleAudioOutputConfigurationsResponse &trt__GetCompatibleAudioOutputConfigurationsResponse) ;

	/// Web service operation 'GetCompatibleAudioDecoderConfigurations' (returns error code or SOAP_OK)
	virtual	int GetCompatibleAudioDecoderConfigurations(_trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, _trt__GetCompatibleAudioDecoderConfigurationsResponse &trt__GetCompatibleAudioDecoderConfigurationsResponse) ;

	/// Web service operation 'SetVideoSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int SetVideoSourceConfiguration(_trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse) ;

	/// Web service operation 'SetVideoEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int SetVideoEncoderConfiguration(_trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse) ;

	/// Web service operation 'SetAudioSourceConfiguration' (returns error code or SOAP_OK)
	virtual	int SetAudioSourceConfiguration(_trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, _trt__SetAudioSourceConfigurationResponse &trt__SetAudioSourceConfigurationResponse) ;

	/// Web service operation 'SetAudioEncoderConfiguration' (returns error code or SOAP_OK)
	virtual	int SetAudioEncoderConfiguration(_trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, _trt__SetAudioEncoderConfigurationResponse &trt__SetAudioEncoderConfigurationResponse) ;

	/// Web service operation 'SetVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	virtual	int SetVideoAnalyticsConfiguration(_trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse) ;

	/// Web service operation 'SetMetadataConfiguration' (returns error code or SOAP_OK)
	virtual	int SetMetadataConfiguration(_trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse) ;

	/// Web service operation 'SetAudioOutputConfiguration' (returns error code or SOAP_OK)
	virtual	int SetAudioOutputConfiguration(_trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, _trt__SetAudioOutputConfigurationResponse &trt__SetAudioOutputConfigurationResponse) ;

	/// Web service operation 'SetAudioDecoderConfiguration' (returns error code or SOAP_OK)
	virtual	int SetAudioDecoderConfiguration(_trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, _trt__SetAudioDecoderConfigurationResponse &trt__SetAudioDecoderConfigurationResponse) ;

	/// Web service operation 'GetVideoSourceConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetVideoSourceConfigurationOptions(_trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse) ;

	/// Web service operation 'GetVideoEncoderConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetVideoEncoderConfigurationOptions(_trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse) ;

	/// Web service operation 'GetAudioSourceConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetAudioSourceConfigurationOptions(_trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, _trt__GetAudioSourceConfigurationOptionsResponse &trt__GetAudioSourceConfigurationOptionsResponse) ;

	/// Web service operation 'GetAudioEncoderConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetAudioEncoderConfigurationOptions(_trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, _trt__GetAudioEncoderConfigurationOptionsResponse &trt__GetAudioEncoderConfigurationOptionsResponse) ;

	/// Web service operation 'GetMetadataConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetMetadataConfigurationOptions(_trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse) ;

	/// Web service operation 'GetAudioOutputConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetAudioOutputConfigurationOptions(_trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, _trt__GetAudioOutputConfigurationOptionsResponse &trt__GetAudioOutputConfigurationOptionsResponse) ;

	/// Web service operation 'GetAudioDecoderConfigurationOptions' (returns error code or SOAP_OK)
	virtual	int GetAudioDecoderConfigurationOptions(_trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, _trt__GetAudioDecoderConfigurationOptionsResponse &trt__GetAudioDecoderConfigurationOptionsResponse) ;

	/// Web service operation 'GetGuaranteedNumberOfVideoEncoderInstances' (returns error code or SOAP_OK)
	virtual	int GetGuaranteedNumberOfVideoEncoderInstances(_trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse &trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) ;

	/// Web service operation 'GetStreamUri' (returns error code or SOAP_OK)
	virtual	int GetStreamUri(_trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse) ;

	/// Web service operation 'StartMulticastStreaming' (returns error code or SOAP_OK)
	virtual	int StartMulticastStreaming(_trt__StartMulticastStreaming *trt__StartMulticastStreaming, _trt__StartMulticastStreamingResponse &trt__StartMulticastStreamingResponse) ;

	/// Web service operation 'StopMulticastStreaming' (returns error code or SOAP_OK)
	virtual	int StopMulticastStreaming(_trt__StopMulticastStreaming *trt__StopMulticastStreaming, _trt__StopMulticastStreamingResponse &trt__StopMulticastStreamingResponse) ;

	/// Web service operation 'SetSynchronizationPoint' (returns error code or SOAP_OK)
	virtual	int SetSynchronizationPoint(_trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse) ;

	/// Web service operation 'GetSnapshotUri' (returns error code or SOAP_OK)
	virtual	int GetSnapshotUri(_trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) ;

/******* old version ZCU
	/// Web service operation 'GetServices' (returns error code or SOAP_OK)
	virtual	int GetServices(_tds__GetServices *tds__GetServices, _tds__GetServicesResponse *tds__GetServicesResponse);

	/// Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
	virtual	int GetServiceCapabilities(_tds__GetServiceCapabilities *tds__GetServiceCapabilities, _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse) {return SOAP_OK;}

	/// Web service operation 'GetDeviceInformation' (returns error code or SOAP_OK)
	virtual	int GetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse);
	/// Web service operation 'SetSystemDateAndTime' (returns error code or SOAP_OK)
	virtual	int SetSystemDateAndTime(_tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse);
	/// Web service operation 'GetSystemDateAndTime' (returns error code or SOAP_OK)
	virtual	int GetSystemDateAndTime(_tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse);

	/// Web service operation 'SetSystemFactoryDefault' (returns error code or SOAP_OK)
	virtual	int SetSystemFactoryDefault(_tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse) {return SOAP_OK;}

	/// Web service operation 'UpgradeSystemFirmware' (returns error code or SOAP_OK)
	virtual	int UpgradeSystemFirmware(_tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse) {return SOAP_OK;}

	/// Web service operation 'SystemReboot' (returns error code or SOAP_OK)
	virtual	int SystemReboot(_tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse *tds__SystemRebootResponse) {return SOAP_OK;}

	/// Web service operation 'RestoreSystem' (returns error code or SOAP_OK)
	virtual	int RestoreSystem(_tds__RestoreSystem *tds__RestoreSystem, _tds__RestoreSystemResponse *tds__RestoreSystemResponse) {return SOAP_OK;}

	/// Web service operation 'GetSystemBackup' (returns error code or SOAP_OK)
	virtual	int GetSystemBackup(_tds__GetSystemBackup *tds__GetSystemBackup, _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse) {return SOAP_OK;}

	/// Web service operation 'GetSystemLog' (returns error code or SOAP_OK)
	virtual	int GetSystemLog(_tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse *tds__GetSystemLogResponse) {return SOAP_OK;}

	/// Web service operation 'GetSystemSupportInformation' (returns error code or SOAP_OK)
	virtual	int GetSystemSupportInformation(_tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse) {return SOAP_OK;}

	/// Web service operation 'GetScopes' (returns error code or SOAP_OK)
    virtual	int GetScopes(_tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse *tds__GetScopesResponse);

	/// Web service operation 'SetScopes' (returns error code or SOAP_OK)
	virtual	int SetScopes(_tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse *tds__SetScopesResponse) {return SOAP_OK;}

	/// Web service operation 'AddScopes' (returns error code or SOAP_OK)
	virtual	int AddScopes(_tds__AddScopes *tds__AddScopes, _tds__AddScopesResponse *tds__AddScopesResponse) {return SOAP_OK;}

	/// Web service operation 'RemoveScopes' (returns error code or SOAP_OK)
	virtual	int RemoveScopes(_tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse *tds__RemoveScopesResponse) {return SOAP_OK;}

	/// Web service operation 'GetDiscoveryMode' (returns error code or SOAP_OK)
	virtual	int GetDiscoveryMode(_tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse) {return SOAP_OK;}

	/// Web service operation 'SetDiscoveryMode' (returns error code or SOAP_OK)
	virtual	int SetDiscoveryMode(_tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse) {return SOAP_OK;}

	/// Web service operation 'GetRemoteDiscoveryMode' (returns error code or SOAP_OK)
	virtual	int GetRemoteDiscoveryMode(_tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse) {return SOAP_OK;}

	/// Web service operation 'SetRemoteDiscoveryMode' (returns error code or SOAP_OK)
	virtual	int SetRemoteDiscoveryMode(_tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse) {return SOAP_OK;}

	/// Web service operation 'GetDPAddresses' (returns error code or SOAP_OK)
	virtual	int GetDPAddresses(_tds__GetDPAddresses *tds__GetDPAddresses, _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse) {return SOAP_OK;}

	/// Web service operation 'GetEndpointReference' (returns error code or SOAP_OK)
	virtual	int GetEndpointReference(_tds__GetEndpointReference *tds__GetEndpointReference, _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse) {return SOAP_OK;}

	/// Web service operation 'GetRemoteUser' (returns error code or SOAP_OK)
	virtual	int GetRemoteUser(_tds__GetRemoteUser *tds__GetRemoteUser, _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse) {return SOAP_OK;}

	/// Web service operation 'SetRemoteUser' (returns error code or SOAP_OK)
	virtual	int SetRemoteUser(_tds__SetRemoteUser *tds__SetRemoteUser, _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse) {return SOAP_OK;}

	/// Web service operation 'GetUsers' (returns error code or SOAP_OK)
	virtual	int GetUsers(_tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse *tds__GetUsersResponse);

	/// Web service operation 'CreateUsers' (returns error code or SOAP_OK)
	virtual	int CreateUsers(_tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse *tds__CreateUsersResponse) {return SOAP_OK;}

	/// Web service operation 'DeleteUsers' (returns error code or SOAP_OK)
	virtual	int DeleteUsers(_tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse *tds__DeleteUsersResponse) {return SOAP_OK;}

	/// Web service operation 'SetUser' (returns error code or SOAP_OK)
	virtual	int SetUser(_tds__SetUser *tds__SetUser, _tds__SetUserResponse *tds__SetUserResponse) {return SOAP_OK;}

	/// Web service operation 'GetWsdlUrl' (returns error code or SOAP_OK)
	virtual	int GetWsdlUrl(_tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse) {return SOAP_OK;}

	/// Web service operation 'GetCapabilities' (returns error code or SOAP_OK)
	virtual	int GetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse);
	/// Web service operation 'SetDPAddresses' (returns error code or SOAP_OK)
	virtual	int SetDPAddresses(_tds__SetDPAddresses *tds__SetDPAddresses, _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse) {return SOAP_OK;}

	/// Web service operation 'GetHostname' (returns error code or SOAP_OK)
	virtual	int GetHostname(_tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse *tds__GetHostnameResponse) {return SOAP_OK;}

	/// Web service operation 'SetHostname' (returns error code or SOAP_OK)
	virtual	int SetHostname(_tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse *tds__SetHostnameResponse) {return SOAP_OK;}

	/// Web service operation 'SetHostnameFromDHCP' (returns error code or SOAP_OK)
	virtual	int SetHostnameFromDHCP(_tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse) {return SOAP_OK;}

	/// Web service operation 'GetDNS' (returns error code or SOAP_OK)
	virtual	int GetDNS(_tds__GetDNS *tds__GetDNS, _tds__GetDNSResponse *tds__GetDNSResponse) {return SOAP_OK;}

	/// Web service operation 'SetDNS' (returns error code or SOAP_OK)
	virtual	int SetDNS(_tds__SetDNS *tds__SetDNS, _tds__SetDNSResponse *tds__SetDNSResponse) {return SOAP_OK;}

	/// Web service operation 'GetNTP' (returns error code or SOAP_OK)
	virtual	int GetNTP(_tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse *tds__GetNTPResponse) {return SOAP_OK;}

	/// Web service operation 'SetNTP' (returns error code or SOAP_OK)
	virtual	int SetNTP(_tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse *tds__SetNTPResponse) {return SOAP_OK;}

	/// Web service operation 'GetDynamicDNS' (returns error code or SOAP_OK)
	virtual	int GetDynamicDNS(_tds__GetDynamicDNS *tds__GetDynamicDNS, _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse) {return SOAP_OK;}

	/// Web service operation 'SetDynamicDNS' (returns error code or SOAP_OK)
	virtual	int SetDynamicDNS(_tds__SetDynamicDNS *tds__SetDynamicDNS, _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse) {return SOAP_OK;}

	/// Web service operation 'GetNetworkInterfaces' (returns error code or SOAP_OK)
	virtual	int GetNetworkInterfaces(_tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse) {return SOAP_OK;}

	/// Web service operation 'SetNetworkInterfaces' (returns error code or SOAP_OK)
	virtual	int SetNetworkInterfaces(_tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse) {return SOAP_OK;}

	/// Web service operation 'GetNetworkProtocols' (returns error code or SOAP_OK)
	virtual	int GetNetworkProtocols(_tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse) {return SOAP_OK;}

	/// Web service operation 'SetNetworkProtocols' (returns error code or SOAP_OK)
	virtual	int SetNetworkProtocols(_tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse) {return SOAP_OK;}

	/// Web service operation 'GetNetworkDefaultGateway' (returns error code or SOAP_OK)
	virtual	int GetNetworkDefaultGateway(_tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse) {return SOAP_OK;}

	/// Web service operation 'SetNetworkDefaultGateway' (returns error code or SOAP_OK)
	virtual	int SetNetworkDefaultGateway(_tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse) {return SOAP_OK;}

	/// Web service operation 'GetZeroConfiguration' (returns error code or SOAP_OK)
	virtual	int GetZeroConfiguration(_tds__GetZeroConfiguration *tds__GetZeroConfiguration, _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'SetZeroConfiguration' (returns error code or SOAP_OK)
	virtual	int SetZeroConfiguration(_tds__SetZeroConfiguration *tds__SetZeroConfiguration, _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'GetIPAddressFilter' (returns error code or SOAP_OK)
	virtual	int GetIPAddressFilter(_tds__GetIPAddressFilter *tds__GetIPAddressFilter, _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse) {return SOAP_OK;}

	/// Web service operation 'SetIPAddressFilter' (returns error code or SOAP_OK)
	virtual	int SetIPAddressFilter(_tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse) {return SOAP_OK;}

	/// Web service operation 'AddIPAddressFilter' (returns error code or SOAP_OK)
	virtual	int AddIPAddressFilter(_tds__AddIPAddressFilter *tds__AddIPAddressFilter, _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse) {return SOAP_OK;}

	/// Web service operation 'RemoveIPAddressFilter' (returns error code or SOAP_OK)
	virtual	int RemoveIPAddressFilter(_tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse) {return SOAP_OK;}

	/// Web service operation 'GetAccessPolicy' (returns error code or SOAP_OK)
	virtual	int GetAccessPolicy(_tds__GetAccessPolicy *tds__GetAccessPolicy, _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse) {return SOAP_OK;}

	/// Web service operation 'SetAccessPolicy' (returns error code or SOAP_OK)
	virtual	int SetAccessPolicy(_tds__SetAccessPolicy *tds__SetAccessPolicy, _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse) {return SOAP_OK;}

	/// Web service operation 'CreateCertificate' (returns error code or SOAP_OK)
	virtual	int CreateCertificate(_tds__CreateCertificate *tds__CreateCertificate, _tds__CreateCertificateResponse *tds__CreateCertificateResponse) {return SOAP_OK;}

	/// Web service operation 'GetCertificates' (returns error code or SOAP_OK)
	virtual	int GetCertificates(_tds__GetCertificates *tds__GetCertificates, _tds__GetCertificatesResponse *tds__GetCertificatesResponse) {return SOAP_OK;}

	/// Web service operation 'GetCertificatesStatus' (returns error code or SOAP_OK)
	virtual	int GetCertificatesStatus(_tds__GetCertificatesStatus *tds__GetCertificatesStatus, _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse) {return SOAP_OK;}

	/// Web service operation 'SetCertificatesStatus' (returns error code or SOAP_OK)
	virtual	int SetCertificatesStatus(_tds__SetCertificatesStatus *tds__SetCertificatesStatus, _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse) {return SOAP_OK;}

	/// Web service operation 'DeleteCertificates' (returns error code or SOAP_OK)
	virtual	int DeleteCertificates(_tds__DeleteCertificates *tds__DeleteCertificates, _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse) {return SOAP_OK;}

	/// Web service operation 'GetPkcs10Request' (returns error code or SOAP_OK)
	virtual	int GetPkcs10Request(_tds__GetPkcs10Request *tds__GetPkcs10Request, _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse) {return SOAP_OK;}

	/// Web service operation 'LoadCertificates' (returns error code or SOAP_OK)
	virtual	int LoadCertificates(_tds__LoadCertificates *tds__LoadCertificates, _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse) {return SOAP_OK;}

	/// Web service operation 'GetClientCertificateMode' (returns error code or SOAP_OK)
	virtual	int GetClientCertificateMode(_tds__GetClientCertificateMode *tds__GetClientCertificateMode, _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse) {return SOAP_OK;}

	/// Web service operation 'SetClientCertificateMode' (returns error code or SOAP_OK)
	virtual	int SetClientCertificateMode(_tds__SetClientCertificateMode *tds__SetClientCertificateMode, _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse) {return SOAP_OK;}

	/// Web service operation 'GetRelayOutputs' (returns error code or SOAP_OK)
	virtual	int GetRelayOutputs(_tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) {return SOAP_OK;}

	/// Web service operation 'SetRelayOutputSettings' (returns error code or SOAP_OK)
	virtual	int SetRelayOutputSettings(_tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse) {return SOAP_OK;}

	/// Web service operation 'SetRelayOutputState' (returns error code or SOAP_OK)
	virtual	int SetRelayOutputState(_tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) {return SOAP_OK;}

	/// Web service operation 'SendAuxiliaryCommand' (returns error code or SOAP_OK)
	virtual	int SendAuxiliaryCommand(_tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse) {return SOAP_OK;}

	/// Web service operation 'GetCACertificates' (returns error code or SOAP_OK)
	virtual	int GetCACertificates(_tds__GetCACertificates *tds__GetCACertificates, _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse) {return SOAP_OK;}

	/// Web service operation 'LoadCertificateWithPrivateKey' (returns error code or SOAP_OK)
	virtual	int LoadCertificateWithPrivateKey(_tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse) {return SOAP_OK;}

	/// Web service operation 'GetCertificateInformation' (returns error code or SOAP_OK)
	virtual	int GetCertificateInformation(_tds__GetCertificateInformation *tds__GetCertificateInformation, _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse) {return SOAP_OK;}

	/// Web service operation 'LoadCACertificates' (returns error code or SOAP_OK)
	virtual	int LoadCACertificates(_tds__LoadCACertificates *tds__LoadCACertificates, _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse) {return SOAP_OK;}

	/// Web service operation 'CreateDot1XConfiguration' (returns error code or SOAP_OK)
	virtual	int CreateDot1XConfiguration(_tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'SetDot1XConfiguration' (returns error code or SOAP_OK)
	virtual	int SetDot1XConfiguration(_tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'GetDot1XConfiguration' (returns error code or SOAP_OK)
	virtual	int GetDot1XConfiguration(_tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'GetDot1XConfigurations' (returns error code or SOAP_OK)
	virtual	int GetDot1XConfigurations(_tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse) {return SOAP_OK;}

	/// Web service operation 'DeleteDot1XConfiguration' (returns error code or SOAP_OK)
	virtual	int DeleteDot1XConfiguration(_tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse) {return SOAP_OK;}

	/// Web service operation 'GetDot11Capabilities' (returns error code or SOAP_OK)
	virtual	int GetDot11Capabilities(_tds__GetDot11Capabilities *tds__GetDot11Capabilities, _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse) {return SOAP_OK;}

	/// Web service operation 'GetDot11Status' (returns error code or SOAP_OK)
	virtual	int GetDot11Status(_tds__GetDot11Status *tds__GetDot11Status, _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse) {return SOAP_OK;}

	/// Web service operation 'ScanAvailableDot11Networks' (returns error code or SOAP_OK)
	virtual	int ScanAvailableDot11Networks(_tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse) {return SOAP_OK;}

	/// Web service operation 'GetSystemUris' (returns error code or SOAP_OK)
	virtual	int GetSystemUris(_tds__GetSystemUris *tds__GetSystemUris, _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse) {return SOAP_OK;}

	/// Web service operation 'StartFirmwareUpgrade' (returns error code or SOAP_OK)
	virtual	int StartFirmwareUpgrade(_tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse) {return SOAP_OK;}

	/// Web service operation 'StartSystemRestore' (returns error code or SOAP_OK)
	virtual	int StartSystemRestore(_tds__StartSystemRestore *tds__StartSystemRestore, _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse) {return SOAP_OK;}

#warning HACK placed here to override gsoap buggy behaviour
    /// Web service operation 'GetServices' (returns error code or SOAP_OK)
    virtual	int GetServices_(_tds__GetServices *tds__GetServices, _tds__GetServicesResponse *tds__GetServicesResponse) {return SOAP_OK;}

    /// Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
    virtual	int GetServiceCapabilities_(_tds__GetServiceCapabilities *tds__GetServiceCapabilities, _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse) {return SOAP_OK;}

    /// Web service operation 'GetDeviceInformation' (returns error code or SOAP_OK)
    virtual	int GetDeviceInformation_(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse) {return SOAP_OK;}

    /// Web service operation 'SetSystemDateAndTime' (returns error code or SOAP_OK)
    virtual	int SetSystemDateAndTime_(_tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse) {return SOAP_OK;}

    /// Web service operation 'GetSystemDateAndTime' (returns error code or SOAP_OK)
    virtual	int GetSystemDateAndTime_(_tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse) {return SOAP_OK;}

    /// Web service operation 'SetSystemFactoryDefault' (returns error code or SOAP_OK)
    virtual	int SetSystemFactoryDefault_(_tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse) {return SOAP_OK;}

    /// Web service operation 'UpgradeSystemFirmware' (returns error code or SOAP_OK)
    virtual	int UpgradeSystemFirmware_(_tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse) {return SOAP_OK;}

    /// Web service operation 'SystemReboot' (returns error code or SOAP_OK)
    virtual	int SystemReboot_(_tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse *tds__SystemRebootResponse) {return SOAP_OK;}

    /// Web service operation 'RestoreSystem' (returns error code or SOAP_OK)
    virtual	int RestoreSystem_(_tds__RestoreSystem *tds__RestoreSystem, _tds__RestoreSystemResponse *tds__RestoreSystemResponse) {return SOAP_OK;}

    /// Web service operation 'GetSystemBackup' (returns error code or SOAP_OK)
    virtual	int GetSystemBackup_(_tds__GetSystemBackup *tds__GetSystemBackup, _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse) {return SOAP_OK;}

    /// Web service operation 'GetSystemLog' (returns error code or SOAP_OK)
    virtual	int GetSystemLog_(_tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse *tds__GetSystemLogResponse) {return SOAP_OK;}

    /// Web service operation 'GetSystemSupportInformation' (returns error code or SOAP_OK)
    virtual	int GetSystemSupportInformation_(_tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse) {return SOAP_OK;}

    /// Web service operation 'GetScopes' (returns error code or SOAP_OK)
    virtual	int GetScopes_(_tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse *tds__GetScopesResponse) {return SOAP_OK;}

    /// Web service operation 'SetScopes' (returns error code or SOAP_OK)
    virtual	int SetScopes_(_tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse *tds__SetScopesResponse) {return SOAP_OK;}

    /// Web service operation 'AddScopes' (returns error code or SOAP_OK)
    virtual	int AddScopes_(_tds__AddScopes *tds__AddScopes, _tds__AddScopesResponse *tds__AddScopesResponse) {return SOAP_OK;}

    /// Web service operation 'RemoveScopes' (returns error code or SOAP_OK)
    virtual	int RemoveScopes_(_tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse *tds__RemoveScopesResponse) {return SOAP_OK;}

    /// Web service operation 'GetDiscoveryMode' (returns error code or SOAP_OK)
    virtual	int GetDiscoveryMode_(_tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse) {return SOAP_OK;}

    /// Web service operation 'SetDiscoveryMode' (returns error code or SOAP_OK)
    virtual	int SetDiscoveryMode_(_tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse) {return SOAP_OK;}

    /// Web service operation 'GetRemoteDiscoveryMode' (returns error code or SOAP_OK)
    virtual	int GetRemoteDiscoveryMode_(_tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse) {return SOAP_OK;}

    /// Web service operation 'SetRemoteDiscoveryMode' (returns error code or SOAP_OK)
    virtual	int SetRemoteDiscoveryMode_(_tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse) {return SOAP_OK;}

    /// Web service operation 'GetDPAddresses' (returns error code or SOAP_OK)
    virtual	int GetDPAddresses_(_tds__GetDPAddresses *tds__GetDPAddresses, _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse) {return SOAP_OK;}

    /// Web service operation 'GetEndpointReference' (returns error code or SOAP_OK)
    virtual	int GetEndpointReference_(_tds__GetEndpointReference *tds__GetEndpointReference, _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse) {return SOAP_OK;}

    /// Web service operation 'GetRemoteUser' (returns error code or SOAP_OK)
    virtual	int GetRemoteUser_(_tds__GetRemoteUser *tds__GetRemoteUser, _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse) {return SOAP_OK;}

    /// Web service operation 'SetRemoteUser' (returns error code or SOAP_OK)
    virtual	int SetRemoteUser_(_tds__SetRemoteUser *tds__SetRemoteUser, _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse) {return SOAP_OK;}

    /// Web service operation 'GetUsers' (returns error code or SOAP_OK)
    virtual	int GetUsers_(_tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse *tds__GetUsersResponse) {return SOAP_OK;}

    /// Web service operation 'CreateUsers' (returns error code or SOAP_OK)
    virtual	int CreateUsers_(_tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse *tds__CreateUsersResponse) {return SOAP_OK;}

    /// Web service operation 'DeleteUsers' (returns error code or SOAP_OK)
    virtual	int DeleteUsers_(_tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse *tds__DeleteUsersResponse) {return SOAP_OK;}

    /// Web service operation 'SetUser' (returns error code or SOAP_OK)
    virtual	int SetUser_(_tds__SetUser *tds__SetUser, _tds__SetUserResponse *tds__SetUserResponse) {return SOAP_OK;}

    /// Web service operation 'GetWsdlUrl' (returns error code or SOAP_OK)
    virtual	int GetWsdlUrl_(_tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse) {return SOAP_OK;}

    /// Web service operation 'GetCapabilities' (returns error code or SOAP_OK)
    virtual	int GetCapabilities_(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse) {return SOAP_OK;}

    /// Web service operation 'SetDPAddresses' (returns error code or SOAP_OK)
    virtual	int SetDPAddresses_(_tds__SetDPAddresses *tds__SetDPAddresses, _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse) {return SOAP_OK;}

    /// Web service operation 'GetHostname' (returns error code or SOAP_OK)
    virtual	int GetHostname_(_tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse *tds__GetHostnameResponse) {return SOAP_OK;}

    /// Web service operation 'SetHostname' (returns error code or SOAP_OK)
    virtual	int SetHostname_(_tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse *tds__SetHostnameResponse) {return SOAP_OK;}

    /// Web service operation 'SetHostnameFromDHCP' (returns error code or SOAP_OK)
    virtual	int SetHostnameFromDHCP_(_tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse) {return SOAP_OK;}

    /// Web service operation 'GetDNS' (returns error code or SOAP_OK)
    virtual	int GetDNS_(_tds__GetDNS *tds__GetDNS, _tds__GetDNSResponse *tds__GetDNSResponse) {return SOAP_OK;}

    /// Web service operation 'SetDNS' (returns error code or SOAP_OK)
    virtual	int SetDNS_(_tds__SetDNS *tds__SetDNS, _tds__SetDNSResponse *tds__SetDNSResponse) {return SOAP_OK;}

    /// Web service operation 'GetNTP' (returns error code or SOAP_OK)
    virtual	int GetNTP_(_tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse *tds__GetNTPResponse) {return SOAP_OK;}

    /// Web service operation 'SetNTP' (returns error code or SOAP_OK)
    virtual	int SetNTP_(_tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse *tds__SetNTPResponse) {return SOAP_OK;}

    /// Web service operation 'GetDynamicDNS' (returns error code or SOAP_OK)
    virtual	int GetDynamicDNS_(_tds__GetDynamicDNS *tds__GetDynamicDNS, _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse) {return SOAP_OK;}

    /// Web service operation 'SetDynamicDNS' (returns error code or SOAP_OK)
    virtual	int SetDynamicDNS_(_tds__SetDynamicDNS *tds__SetDynamicDNS, _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse) {return SOAP_OK;}

    /// Web service operation 'GetNetworkInterfaces' (returns error code or SOAP_OK)
    virtual	int GetNetworkInterfaces_(_tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse) {return SOAP_OK;}

    /// Web service operation 'SetNetworkInterfaces' (returns error code or SOAP_OK)
    virtual	int SetNetworkInterfaces_(_tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse) {return SOAP_OK;}

    /// Web service operation 'GetNetworkProtocols' (returns error code or SOAP_OK)
    virtual	int GetNetworkProtocols_(_tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse) {return SOAP_OK;}

    /// Web service operation 'SetNetworkProtocols' (returns error code or SOAP_OK)
    virtual	int SetNetworkProtocols_(_tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse) {return SOAP_OK;}

    /// Web service operation 'GetNetworkDefaultGateway' (returns error code or SOAP_OK)
    virtual	int GetNetworkDefaultGateway_(_tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse) {return SOAP_OK;}

    /// Web service operation 'SetNetworkDefaultGateway' (returns error code or SOAP_OK)
    virtual	int SetNetworkDefaultGateway_(_tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse) {return SOAP_OK;}
    /// Web service operation 'GetZeroConfiguration' (returns error code or SOAP_OK)
    virtual	int GetZeroConfiguration_(_tds__GetZeroConfiguration *tds__GetZeroConfiguration, _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'SetZeroConfiguration' (returns error code or SOAP_OK)
    virtual	int SetZeroConfiguration_(_tds__SetZeroConfiguration *tds__SetZeroConfiguration, _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'GetIPAddressFilter' (returns error code or SOAP_OK)
    virtual	int GetIPAddressFilter_(_tds__GetIPAddressFilter *tds__GetIPAddressFilter, _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse) {return SOAP_OK;}
    /// Web service operation 'SetIPAddressFilter' (returns error code or SOAP_OK)
    virtual	int SetIPAddressFilter_(_tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse) {return SOAP_OK;}
    /// Web service operation 'AddIPAddressFilter' (returns error code or SOAP_OK)
    virtual	int AddIPAddressFilter_(_tds__AddIPAddressFilter *tds__AddIPAddressFilter, _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse) {return SOAP_OK;}
    /// Web service operation 'RemoveIPAddressFilter' (returns error code or SOAP_OK)
    virtual	int RemoveIPAddressFilter_(_tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse) {return SOAP_OK;}

    /// Web service operation 'GetAccessPolicy' (returns error code or SOAP_OK)
    virtual	int GetAccessPolicy_(_tds__GetAccessPolicy *tds__GetAccessPolicy, _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse) {return SOAP_OK;}

    /// Web service operation 'SetAccessPolicy' (returns error code or SOAP_OK)
    virtual	int SetAccessPolicy_(_tds__SetAccessPolicy *tds__SetAccessPolicy, _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse) {return SOAP_OK;}
    /// Web service operation 'CreateCertificate' (returns error code or SOAP_OK)
    virtual	int CreateCertificate_(_tds__CreateCertificate *tds__CreateCertificate, _tds__CreateCertificateResponse *tds__CreateCertificateResponse) {return SOAP_OK;}

    /// Web service operation 'GetCertificates' (returns error code or SOAP_OK)
    virtual	int GetCertificates_(_tds__GetCertificates *tds__GetCertificates, _tds__GetCertificatesResponse *tds__GetCertificatesResponse) {return SOAP_OK;}

    /// Web service operation 'GetCertificatesStatus' (returns error code or SOAP_OK)
    virtual	int GetCertificatesStatus_(_tds__GetCertificatesStatus *tds__GetCertificatesStatus, _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse) {return SOAP_OK;}

    /// Web service operation 'SetCertificatesStatus' (returns error code or SOAP_OK)
    virtual	int SetCertificatesStatus_(_tds__SetCertificatesStatus *tds__SetCertificatesStatus, _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse) {return SOAP_OK;}

    /// Web service operation 'DeleteCertificates' (returns error code or SOAP_OK)
    virtual	int DeleteCertificates_(_tds__DeleteCertificates *tds__DeleteCertificates, _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse) {return SOAP_OK;}

    /// Web service operation 'GetPkcs10Request' (returns error code or SOAP_OK)
    virtual	int GetPkcs10Request_(_tds__GetPkcs10Request *tds__GetPkcs10Request, _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse) {return SOAP_OK;}

    /// Web service operation 'LoadCertificates' (returns error code or SOAP_OK)
    virtual	int LoadCertificates_(_tds__LoadCertificates *tds__LoadCertificates, _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse) {return SOAP_OK;}

    /// Web service operation 'GetClientCertificateMode' (returns error code or SOAP_OK)
    virtual	int GetClientCertificateMode_(_tds__GetClientCertificateMode *tds__GetClientCertificateMode, _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse) {return SOAP_OK;}

    /// Web service operation 'SetClientCertificateMode' (returns error code or SOAP_OK)
    virtual	int SetClientCertificateMode_(_tds__SetClientCertificateMode *tds__SetClientCertificateMode, _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse) {return SOAP_OK;}

    /// Web service operation 'GetRelayOutputs' (returns error code or SOAP_OK)
    virtual	int GetRelayOutputs_(_tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) {return SOAP_OK;}

    /// Web service operation 'SetRelayOutputSettings' (returns error code or SOAP_OK)
    virtual	int SetRelayOutputSettings_(_tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse) {return SOAP_OK;}

    /// Web service operation 'SetRelayOutputState' (returns error code or SOAP_OK)
    virtual	int SetRelayOutputState_(_tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) {return SOAP_OK;}

    /// Web service operation 'SendAuxiliaryCommand' (returns error code or SOAP_OK)
    virtual	int SendAuxiliaryCommand_(_tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse) {return SOAP_OK;}

    /// Web service operation 'GetCACertificates' (returns error code or SOAP_OK)
    virtual	int GetCACertificates_(_tds__GetCACertificates *tds__GetCACertificates, _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse) {return SOAP_OK;}

    /// Web service operation 'LoadCertificateWithPrivateKey' (returns error code or SOAP_OK)
    virtual	int LoadCertificateWithPrivateKey_(_tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse) {return SOAP_OK;}

    /// Web service operation 'GetCertificateInformation' (returns error code or SOAP_OK)
    virtual	int GetCertificateInformation_(_tds__GetCertificateInformation *tds__GetCertificateInformation, _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse) {return SOAP_OK;}

    /// Web service operation 'LoadCACertificates' (returns error code or SOAP_OK)
    virtual	int LoadCACertificates_(_tds__LoadCACertificates *tds__LoadCACertificates, _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse) {return SOAP_OK;}

    /// Web service operation 'CreateDot1XConfiguration' (returns error code or SOAP_OK)
    virtual	int CreateDot1XConfiguration_(_tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'SetDot1XConfiguration' (returns error code or SOAP_OK)
    virtual	int SetDot1XConfiguration_(_tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'GetDot1XConfiguration' (returns error code or SOAP_OK)
    virtual	int GetDot1XConfiguration_(_tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'GetDot1XConfigurations' (returns error code or SOAP_OK)
    virtual	int GetDot1XConfigurations_(_tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse) {return SOAP_OK;}

    /// Web service operation 'DeleteDot1XConfiguration' (returns error code or SOAP_OK)
    virtual	int DeleteDot1XConfiguration_(_tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse) {return SOAP_OK;}

    /// Web service operation 'GetDot11Capabilities' (returns error code or SOAP_OK)
    virtual	int GetDot11Capabilities_(_tds__GetDot11Capabilities *tds__GetDot11Capabilities, _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse) {return SOAP_OK;}

    /// Web service operation 'GetDot11Status' (returns error code or SOAP_OK)
    virtual	int GetDot11Status_(_tds__GetDot11Status *tds__GetDot11Status, _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse) {return SOAP_OK;}

    /// Web service operation 'ScanAvailableDot11Networks' (returns error code or SOAP_OK)
    virtual	int ScanAvailableDot11Networks_(_tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse) {return SOAP_OK;};

    /// Web service operation 'GetSystemUris' (returns error code or SOAP_OK)
    virtual	int GetSystemUris_(_tds__GetSystemUris *tds__GetSystemUris, _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse) {return SOAP_OK;}

    /// Web service operation 'StartFirmwareUpgrade' (returns error code or SOAP_OK)
    virtual	int StartFirmwareUpgrade_(_tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse) {return SOAP_OK;}

    /// Web service operation 'StartSystemRestore' (returns error code or SOAP_OK)
    virtual	int StartSystemRestore_(_tds__StartSystemRestore *tds__StartSystemRestore, _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse) {return SOAP_OK;}
*/

};

#endif //DEV_S
#endif // WebDeviceBindingServiceImpl_H
