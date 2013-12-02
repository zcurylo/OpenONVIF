#ifndef deviceClient_H
#define deviceClient_H

#include "sigrlog.h"
#include "OnvifSDK.h"
#include "WebDeviceBindingProxy.h"

class DeviceClient
{
public:
	DeviceClient(const char * pchAdress, soap * s);
	~DeviceClient();

    int SetDateAndTime(const DevSetSystemDateAndTime &);
	int GetDateAndTime(DevGetSystemDateAndTimeResponse &);
	//int GetDeviceInfo(DevGetDeviceInformationResponse &);
	//int GetCapabilities(DevGetCapabilitiesResponse &);
	int GetUsers(DevGetUsersResponse &);
	int GetServices(DevGetServicesResponse &);

private:
	DeviceBindingProxy m_proxy;
};
#endif	// deviceClient_H

