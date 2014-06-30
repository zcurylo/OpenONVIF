
#include "DeviceClient.h"

#ifdef DEV_S
DeviceClient::DeviceClient(const char * pchAdress, soap * s):m_proxy(s)
{
	m_proxy.soap_endpoint = pchAdress;
}

int DeviceClient::GetDateAndTime(DevGetSystemDateAndTimeResponse & resp)
{
	DevGetSystemDateAndTime req(m_proxy.soap);

	int nRes = m_proxy.GetSystemDateAndTime(req.d, resp.d);

	CHECKRETURN(nRes, "DeviceClient::GetDateAndTime");
}


int DeviceClient::SetDateAndTime(DevSetSystemDateAndTime & req)
{
    DevSetSystemDateAndTimeResponse resp(m_proxy.soap);

	int nRes = m_proxy.SetSystemDateAndTime(req.d, resp.d);

	CHECKRETURN(nRes, "DeviceClient::SetDateAndTime");
}

int DeviceClient::GetUsers(DevGetUsersResponse & resp)
{
	DevGetUsers req(m_proxy.soap);

	int nRes = m_proxy.GetUsers(req.d, resp.d);

	CHECKRETURN(nRes, "DeviceClient::GetUsers");
}

#endif //DEV_S
