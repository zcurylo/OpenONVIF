#include "DeviceServiceImpl.h"

#ifdef DEV_S
#include "sigrlog.h"
#include "BaseServer.h"

int
DeviceServiceImpl::GetSystemDateAndTime( _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime,
                                         _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse ) {
	DevGetSystemDateAndTimeResponse dt(tds__GetSystemDateAndTimeResponse);
    int nRes = handler_->GetDateAndTime(dt);
	CHECKRETURN(nRes, "DeviceServiceImpl::GetSystemDateAndTime");
}

// for while not supporting copy
DeviceBindingService* DeviceServiceImpl::copy() {
	return NULL;
}

int
DeviceServiceImpl::SetSystemDateAndTime( _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime,
                                         _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse ) {
    if(tds__SetSystemDateAndTime->DateTimeType != tt__SetDateTimeType__Manual) {
		SIGRLOG(SIGRWARNING, "DeviceServiceImpl::SetSystemDateAndTime Time is not Manual");
		return SOAP_ERR;
	}

	DevSetSystemDateAndTime dt(tds__SetSystemDateAndTime);
    int nRes = handler_->SetDateAndTime(dt);
	CHECKRETURN(nRes, "DeviceServiceImpl::SetSystemDateAndTime");
}

int
DeviceServiceImpl::GetCapabilities( _tds__GetCapabilities *tds__GetCapabilities,
                                    _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse ) {
	DevGetCapabilitiesResponse resp(tds__GetCapabilitiesResponse);
    resp.SetDeviceCapabilities( baseServer_->m_endpoint );
    if( baseServer_->m_deviceType == OnvifDevice::NVT ) {
        resp.SetEventsCapabilities( baseServer_->m_endpoint );
        resp.SetMediaCapabilities( baseServer_->m_endpoint );
        resp.SetAnalyticsCapabilities( baseServer_->m_endpoint );
    }

	return SOAP_OK;
}

int
DeviceServiceImpl::GetDeviceInformation( _tds__GetDeviceInformation *tds__GetDeviceInformation,
                                         _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse ) {
	DevGetDeviceInformationResponse resp(tds__GetDeviceInformationResponse);
    resp.SetDeviceInfo( baseServer_->m_manufacturer, baseServer_->m_model,
                        baseServer_->m_firmwareVersion, baseServer_->m_serialNumber, baseServer_->m_hardwareId );

	return SOAP_OK;
}

int
DeviceServiceImpl::GetUsers( _tds__GetUsers *tds__GetUsers,
                             _tds__GetUsersResponse *tds__GetUsersResponse) {
	DevGetUsersResponse resp(tds__GetUsersResponse);
    int nRes = handler_->GetUsers(resp);
	CHECKRETURN(nRes, "DeviceServiceImpl::GetUsers");
}

int
DeviceServiceImpl::GetServices( _tds__GetServices *tds__GetServices,
                                _tds__GetServicesResponse *tds__GetServicesResponse ) {
	DevGetServices req(tds__GetServices);
    DevGetServicesResponse resp(tds__GetServicesResponse);
    if( req.d->IncludeCapability )
        SIGRLOG(SIGRWARNING, "DeviceServiceImpl::GetServices 'Including Capabilities' still not implemented");

    resp.AddService( "http://www.onvif.org/ver10/events/wsdl",  baseServer_->m_endpoint, 1 );
    resp.AddService( "http://www.onvif.org/ver20/analytics/wsdl",  baseServer_->m_endpoint, 2 );
	return 0;
}

int
DeviceServiceImpl::GetScopes( _tds__GetScopes *tds__GetScopes,
                              _tds__GetScopesResponse *tds__GetScopesResponse ) {
    DevGetScopesResponse resp(tds__GetScopesResponse);
    resp.AddItems( baseServer_->m_scopes );
    return SOAP_OK;
}



	/// Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetServiceCapabilities(_trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoSources' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoSources(_trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioSources' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioSources(_trt__GetAudioSources *trt__GetAudioSources, _trt__GetAudioSourcesResponse &trt__GetAudioSourcesResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioOutputs' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioOutputs(_trt__GetAudioOutputs *trt__GetAudioOutputs, _trt__GetAudioOutputsResponse &trt__GetAudioOutputsResponse) {return SOAP_ERR;}

	/// Web service operation 'CreateProfile' (returns error code or SOAP_OK)
	int DeviceServiceImpl::CreateProfile(_trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse) {return SOAP_ERR;}

	/// Web service operation 'GetProfile' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetProfile(_trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse) {return SOAP_ERR;}

	/// Web service operation 'GetProfiles' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetProfiles(_trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse) {return SOAP_ERR;}

	/// Web service operation 'AddVideoEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddVideoEncoderConfiguration(_trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, _trt__AddVideoEncoderConfigurationResponse &trt__AddVideoEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddVideoSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddVideoSourceConfiguration(_trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, _trt__AddVideoSourceConfigurationResponse &trt__AddVideoSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddAudioEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddAudioEncoderConfiguration(_trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, _trt__AddAudioEncoderConfigurationResponse &trt__AddAudioEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddAudioSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddAudioSourceConfiguration(_trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, _trt__AddAudioSourceConfigurationResponse &trt__AddAudioSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddPTZConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddPTZConfiguration(_trt__AddPTZConfiguration *trt__AddPTZConfiguration, _trt__AddPTZConfigurationResponse &trt__AddPTZConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddVideoAnalyticsConfiguration(_trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, _trt__AddVideoAnalyticsConfigurationResponse &trt__AddVideoAnalyticsConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddMetadataConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddMetadataConfiguration(_trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, _trt__AddMetadataConfigurationResponse &trt__AddMetadataConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddAudioOutputConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddAudioOutputConfiguration(_trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, _trt__AddAudioOutputConfigurationResponse &trt__AddAudioOutputConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'AddAudioDecoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::AddAudioDecoderConfiguration(_trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, _trt__AddAudioDecoderConfigurationResponse &trt__AddAudioDecoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveVideoEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveVideoEncoderConfiguration(_trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, _trt__RemoveVideoEncoderConfigurationResponse &trt__RemoveVideoEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveVideoSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveVideoSourceConfiguration(_trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, _trt__RemoveVideoSourceConfigurationResponse &trt__RemoveVideoSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveAudioEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveAudioEncoderConfiguration(_trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, _trt__RemoveAudioEncoderConfigurationResponse &trt__RemoveAudioEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveAudioSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveAudioSourceConfiguration(_trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, _trt__RemoveAudioSourceConfigurationResponse &trt__RemoveAudioSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemovePTZConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemovePTZConfiguration(_trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, _trt__RemovePTZConfigurationResponse &trt__RemovePTZConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveVideoAnalyticsConfiguration(_trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, _trt__RemoveVideoAnalyticsConfigurationResponse &trt__RemoveVideoAnalyticsConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveMetadataConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveMetadataConfiguration(_trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, _trt__RemoveMetadataConfigurationResponse &trt__RemoveMetadataConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveAudioOutputConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveAudioOutputConfiguration(_trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, _trt__RemoveAudioOutputConfigurationResponse &trt__RemoveAudioOutputConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'RemoveAudioDecoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::RemoveAudioDecoderConfiguration(_trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, _trt__RemoveAudioDecoderConfigurationResponse &trt__RemoveAudioDecoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'DeleteProfile' (returns error code or SOAP_OK)
	int DeviceServiceImpl::DeleteProfile(_trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoSourceConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoSourceConfigurations(_trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoEncoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoEncoderConfigurations(_trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioSourceConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioSourceConfigurations(_trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, _trt__GetAudioSourceConfigurationsResponse &trt__GetAudioSourceConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioEncoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioEncoderConfigurations(_trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, _trt__GetAudioEncoderConfigurationsResponse &trt__GetAudioEncoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoAnalyticsConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoAnalyticsConfigurations(_trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetMetadataConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetMetadataConfigurations(_trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioOutputConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioOutputConfigurations(_trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, _trt__GetAudioOutputConfigurationsResponse &trt__GetAudioOutputConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioDecoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioDecoderConfigurations(_trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, _trt__GetAudioDecoderConfigurationsResponse &trt__GetAudioDecoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoSourceConfiguration(_trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoEncoderConfiguration(_trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioSourceConfiguration(_trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, _trt__GetAudioSourceConfigurationResponse &trt__GetAudioSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioEncoderConfiguration(_trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, _trt__GetAudioEncoderConfigurationResponse &trt__GetAudioEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoAnalyticsConfiguration(_trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetMetadataConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetMetadataConfiguration(_trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioOutputConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioOutputConfiguration(_trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, _trt__GetAudioOutputConfigurationResponse &trt__GetAudioOutputConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioDecoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioDecoderConfiguration(_trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, _trt__GetAudioDecoderConfigurationResponse &trt__GetAudioDecoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleVideoEncoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleVideoEncoderConfigurations(_trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleVideoSourceConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleVideoSourceConfigurations(_trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleAudioEncoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleAudioEncoderConfigurations(_trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, _trt__GetCompatibleAudioEncoderConfigurationsResponse &trt__GetCompatibleAudioEncoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleAudioSourceConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleAudioSourceConfigurations(_trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, _trt__GetCompatibleAudioSourceConfigurationsResponse &trt__GetCompatibleAudioSourceConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleVideoAnalyticsConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleVideoAnalyticsConfigurations(_trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleMetadataConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleMetadataConfigurations(_trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleAudioOutputConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleAudioOutputConfigurations(_trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, _trt__GetCompatibleAudioOutputConfigurationsResponse &trt__GetCompatibleAudioOutputConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetCompatibleAudioDecoderConfigurations' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetCompatibleAudioDecoderConfigurations(_trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, _trt__GetCompatibleAudioDecoderConfigurationsResponse &trt__GetCompatibleAudioDecoderConfigurationsResponse) {return SOAP_ERR;}

	/// Web service operation 'SetVideoSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetVideoSourceConfiguration(_trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetVideoEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetVideoEncoderConfiguration(_trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetAudioSourceConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetAudioSourceConfiguration(_trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, _trt__SetAudioSourceConfigurationResponse &trt__SetAudioSourceConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetAudioEncoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetAudioEncoderConfiguration(_trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, _trt__SetAudioEncoderConfigurationResponse &trt__SetAudioEncoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetVideoAnalyticsConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetVideoAnalyticsConfiguration(_trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetMetadataConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetMetadataConfiguration(_trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetAudioOutputConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetAudioOutputConfiguration(_trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, _trt__SetAudioOutputConfigurationResponse &trt__SetAudioOutputConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'SetAudioDecoderConfiguration' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetAudioDecoderConfiguration(_trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, _trt__SetAudioDecoderConfigurationResponse &trt__SetAudioDecoderConfigurationResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoSourceConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoSourceConfigurationOptions(_trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetVideoEncoderConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetVideoEncoderConfigurationOptions(_trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioSourceConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioSourceConfigurationOptions(_trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, _trt__GetAudioSourceConfigurationOptionsResponse &trt__GetAudioSourceConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioEncoderConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioEncoderConfigurationOptions(_trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, _trt__GetAudioEncoderConfigurationOptionsResponse &trt__GetAudioEncoderConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetMetadataConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetMetadataConfigurationOptions(_trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioOutputConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioOutputConfigurationOptions(_trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, _trt__GetAudioOutputConfigurationOptionsResponse &trt__GetAudioOutputConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetAudioDecoderConfigurationOptions' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetAudioDecoderConfigurationOptions(_trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, _trt__GetAudioDecoderConfigurationOptionsResponse &trt__GetAudioDecoderConfigurationOptionsResponse) {return SOAP_ERR;}

	/// Web service operation 'GetGuaranteedNumberOfVideoEncoderInstances' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetGuaranteedNumberOfVideoEncoderInstances(_trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse &trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) {return SOAP_ERR;}

	/// Web service operation 'GetStreamUri' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetStreamUri(_trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse) {return SOAP_ERR;}

	/// Web service operation 'StartMulticastStreaming' (returns error code or SOAP_OK)
	int DeviceServiceImpl::StartMulticastStreaming(_trt__StartMulticastStreaming *trt__StartMulticastStreaming, _trt__StartMulticastStreamingResponse &trt__StartMulticastStreamingResponse) {return SOAP_ERR;}

	/// Web service operation 'StopMulticastStreaming' (returns error code or SOAP_OK)
	int DeviceServiceImpl::StopMulticastStreaming(_trt__StopMulticastStreaming *trt__StopMulticastStreaming, _trt__StopMulticastStreamingResponse &trt__StopMulticastStreamingResponse) {return SOAP_ERR;}

	/// Web service operation 'SetSynchronizationPoint' (returns error code or SOAP_OK)
	int DeviceServiceImpl::SetSynchronizationPoint(_trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse) {return SOAP_ERR;}

	/// Web service operation 'GetSnapshotUri' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetSnapshotUri(_trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) {return SOAP_ERR;}


	/// Web service operation 'GetSnapshotUri' (returns error code or SOAP_OK)
	int DeviceServiceImpl::GetSnapshotUri(_trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) {return SOAP_ERR;}
};


#endif //DEV_S
