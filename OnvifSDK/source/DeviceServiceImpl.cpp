#include "sigrlog.h"
#include "DeviceServiceImpl.h"
#include "BaseServer.h"

int DeviceServiceImpl::GetSystemDateAndTime(_tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse)
{
	DevGetSystemDateAndTimeResponse dt(tds__GetSystemDateAndTimeResponse);

    int nRes = m_pBaseServer->GetDateAndTime(dt);

	CHECKRETURN(nRes, "DeviceServiceImpl::GetSystemDateAndTime");
};

// for while not supporting copy
DeviceBindingService* DeviceServiceImpl::copy()
{
	return NULL;
};

int DeviceServiceImpl::SetSystemDateAndTime(_tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse)
{
	if(tds__SetSystemDateAndTime->DateTimeType != tt__SetDateTimeType__Manual)
	{
		SIGRLOG(SIGRWARNING, "DeviceServiceImpl::SetSystemDateAndTime Time is not Manual");
		return SOAP_ERR;
	}

	DevSetSystemDateAndTime dt(tds__SetSystemDateAndTime);

    int nRes = m_pBaseServer->SetDateAndTime(dt);

	CHECKRETURN(nRes, "DeviceServiceImpl::SetSystemDateAndTime");
}

int DeviceServiceImpl::GetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse)
{
	DevGetCapabilitiesResponse resp(tds__GetCapabilitiesResponse);
    resp.SetDeviceCapabilities( m_pBaseServer->m_endpoint );
    if( m_pBaseServer->m_deviceType == OnvifDevice::NVT ) {
        resp.SetEventsCapabilities( m_pBaseServer->m_endpoint );
        resp.SetMediaCapabilities( m_pBaseServer->m_endpoint );
        resp.SetAnalyticsCapabilities( m_pBaseServer->m_endpoint );
    }

	return SOAP_OK;
}

int DeviceServiceImpl::GetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse)
{
	DevGetDeviceInformationResponse resp(tds__GetDeviceInformationResponse);

    resp.SetDeviceInfo( m_pBaseServer->m_manufacturer, m_pBaseServer->m_model,
                        m_pBaseServer->m_firmwareVersion, m_pBaseServer->m_serialNumber, m_pBaseServer->m_hardwareId );

	return SOAP_OK;
}

int DeviceServiceImpl::GetUsers(_tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse *tds__GetUsersResponse)
{
	DevGetUsersResponse resp(tds__GetUsersResponse);

    int nRes = m_pBaseServer->GetUsers(resp);

	CHECKRETURN(nRes, "DeviceServiceImpl::GetUsers");
}

int DeviceServiceImpl::GetServices(_tds__GetServices *tds__GetServices, _tds__GetServicesResponse *tds__GetServicesResponse)
{
	DevGetServices req(tds__GetServices);
    DevGetServicesResponse resp(tds__GetServicesResponse);

    if( req.d->IncludeCapability )
        SIGRLOG(SIGRWARNING, "DeviceServiceImpl::GetServices 'Including Capabilities' still not implemented");

    resp.AddService( "http://www.onvif.org/ver10/events/wsdl",  m_pBaseServer->m_endpoint );
	return 0;
}

int DeviceServiceImpl::GetScopes(_tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse *tds__GetScopesResponse)
{
    DevGetScopesResponse resp(tds__GetScopesResponse);
    resp.AddItems( m_pBaseServer->m_scopes );
    return SOAP_OK;
}

