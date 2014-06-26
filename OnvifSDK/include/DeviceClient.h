#ifndef deviceClient_H
#define deviceClient_H

#include "OnvifSDK.h"

#ifdef DEV_S
#include "sigrlog.h"
#include "WebDeviceBindingProxy.h"

class DeviceClient:
        public IOnvifDevMgmt {
public:
	DeviceClient(const char * pchAdress, soap * s);
    virtual ~DeviceClient() {
    }

    int SetDateAndTime( DevSetSystemDateAndTime & );
	int GetDateAndTime(DevGetSystemDateAndTimeResponse &);
    int GetUsers(DevGetUsersResponse &);

private:
	DeviceBindingProxy m_proxy;
};
#endif //DEV_S
#endif	// deviceClient_H

