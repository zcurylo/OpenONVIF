
#include "AnalyticsServiceImpl.h"

#ifdef ANALY_S
#include "BaseServer.h"

int
AnalyticsServiceImpl::GetAnalyticsModules( _tan__GetAnalyticsModules *tan__GetAnalyticsModules,
                                           _tan__GetAnalyticsModulesResponse *tan__GetAnalyticsModulesResponse) {
    AnltGetAnalyticsModulesResponse r(tan__GetAnalyticsModulesResponse);
    return handler_->GetAnalyticsModules( tan__GetAnalyticsModules->ConfigurationToken, r );
}

int
AnalyticsServiceImpl::GetSupportedAnalyticsModules( _tan__GetSupportedAnalyticsModules *tan__GetSupportedAnalyticsModules,
                                                    _tan__GetSupportedAnalyticsModulesResponse *tan__GetSupportedAnalyticsModulesResponse) {
    return 0;
}
int AnalyticsServiceImpl::GetSupportedRules(_tan__GetSupportedRules *tan__GetSupportedRules, _tan__GetSupportedRulesResponse *tan__GetSupportedRulesResponse)
{
	return SOAP_ERR;
}
    // Web service operation 'CreateRules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::CreateRules(_tan__CreateRules *tan__CreateRules, _tan__CreateRulesResponse *tan__CreateRulesResponse)
{
	return SOAP_ERR;
}
    // Web service operation 'DeleteRules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::DeleteRules(_tan__DeleteRules *tan__DeleteRules, _tan__DeleteRulesResponse *tan__DeleteRulesResponse)
{
	return SOAP_ERR;
}

    // Web service operation 'GetRules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::GetRules(_tan__GetRules *tan__GetRules, _tan__GetRulesResponse *tan__GetRulesResponse)
{
	return SOAP_ERR;
}

    // Web service operation 'ModifyRules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::ModifyRules(_tan__ModifyRules *tan__ModifyRules, _tan__ModifyRulesResponse *tan__ModifyRulesResponse)
{
	return SOAP_ERR;
}

    // Web service operation 'GetServiceCapabilities' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::GetServiceCapabilities(_tan__GetServiceCapabilities *tan__GetServiceCapabilities, _tan__GetServiceCapabilitiesResponse *tan__GetServiceCapabilitiesResponse)
{
	return SOAP_ERR;
}
    // Web service operation 'CreateAnalyticsModules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::CreateAnalyticsModules(_tan__CreateAnalyticsModules *tan__CreateAnalyticsModules, _tan__CreateAnalyticsModulesResponse *tan__CreateAnalyticsModulesResponse)
{
	return SOAP_ERR;
}
    // Web service operation 'DeleteAnalyticsModules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::DeleteAnalyticsModules(_tan__DeleteAnalyticsModules *tan__DeleteAnalyticsModules, _tan__DeleteAnalyticsModulesResponse *tan__DeleteAnalyticsModulesResponse)
{
	return SOAP_ERR;	
}
    // Web service operation 'ModifyAnalyticsModules' (returns error code or SOAP_OK)
int AnalythicsServiceImpl::ModifyAnalyticsModulesZCU(_tan__ModifyAnalyticsModules *tan__ModifyAnalyticsModules, _tan__ModifyAnalyticsModulesResponse *tan__ModifyAnalyticsModulesResponse)
{
	return SOAP_ERR;	
}
#endif //ANALY_S
