
#include "OnvifSDK.h"
#include "commonTypes.h"
#include "WebMediaBindingProxy.h"

#define EXTRA_CONSTRUCT() \
{\
}

CLASS_CTORS(trt, Med, GetProfileResponse)
CLASS_CTORS(trt, Med, GetProfilesResponse)
CLASS_CTORS(trt, Med, GetVideoSourcesResponse)
CLASS_CTORS(trt, Med, GetCompatibleVideoEncoderConfigurationsResponse)
CLASS_CTORS(trt, Med, GetCompatibleVideoAnalyticsConfigurationsResponse)


void
MedGetVideoSourcesResponse::AddEntry( const std::string & sourceToken,
                                      int w, int h, float frmRate ) {
    d->VideoSources.push_back( soap_new_tt__VideoSource( d->soap, -1 ) );
    d->VideoSources.back()->token = sourceToken;
    d->VideoSources.back()->Framerate = frmRate;
    d->VideoSources.back()->Resolution = soap_new_tt__VideoResolution(d->soap, -1);
    d->VideoSources.back()->Resolution->Width = w;
    d->VideoSources.back()->Resolution->Height = h;
}

void
MedGetVideoSourcesResponse::AddEntry( const MedVideoSource & src ) {
    d->VideoSources.push_back( src.d );
}

void
MedGetProfileResponse::SetProfile( MedProfile& prof ) {
    d->Profile = prof.d;
}

void
MedGetProfilesResponse::AddProfile( MedProfile& prof ) {
    d->Profiles.push_back(prof.d);
}


MedProfile::MedProfile( tt__Profile* pData) {
    d = pData;
}

MedProfile::MedProfile( soap * pSoap, const std::string& name, const std::string& token ) {
    d = soap_new_tt__Profile(pSoap);
    d->Name = name;
    d->token = token;
    d->fixed = static_cast<bool*>(soap_malloc(pSoap, sizeof(bool)));
    *d->fixed = false;
}

void
MedProfile::AddVideoSrc(const std::string & sourceToken, int w, int h) {
    d->VideoSourceConfiguration = soap_new_tt__VideoSourceConfiguration(d->soap, -1);
    d->VideoSourceConfiguration->SourceToken = sourceToken;
    d->VideoSourceConfiguration->Bounds = soap_new_tt__IntRectangle(d->soap, -1);
    d->VideoSourceConfiguration->Bounds->x = 0;
    d->VideoSourceConfiguration->Bounds->y = 0;
    d->VideoSourceConfiguration->Bounds->width = w;
    d->VideoSourceConfiguration->Bounds->height = h;

}

void
MedProfile::AddVideoEnc( int w, int h ) {
    d->VideoEncoderConfiguration = soap_new_tt__VideoEncoderConfiguration(d->soap, -1);
    d->VideoEncoderConfiguration->Encoding =  tt__VideoEncoding__H264;
    d->VideoEncoderConfiguration->Quality = 100.0f;
    d->VideoEncoderConfiguration->Resolution = soap_new_tt__VideoResolution(d->soap, -1);
    d->VideoEncoderConfiguration->Resolution->Width = w;
    d->VideoEncoderConfiguration->Resolution->Height = h;
}

const std::string &
MedProfile::getToken() {
    return d->token;
}

void
MedProfile::AddVideoAnalytics() {
    d->VideoAnalyticsConfiguration = soap_new_tt__VideoAnalyticsConfiguration(d->soap, -1);
    d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration = soap_new_tt__AnalyticsEngineConfiguration(d->soap, -1);
    //d->VideoAnalyticsConfiguration->RuleEngineConfiguration = soap_new_tt__RuleEngineConfiguration(d->soap, -1);
    d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.push_back(soap_new_tt__Config(d->soap, -1));
    d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.back()->Name = "CellMotion";
    d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.back()->Type = "tt:CellMotionEngine";
    d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.back()->Parameters = soap_new_tt__ItemList(d->soap, -1);
    //d->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.back()->Parameters->SimpleItem->push_back();

}

MedVideoSource::MedVideoSource( soap * pSoap, const std::string &token, int w, int h, double frmRate) {
    d = soap_new_tt__VideoSource( pSoap );
    d->token = token;
    d->Framerate = frmRate;
    d->Resolution = soap_new_tt__VideoResolution( pSoap );
    d->Resolution->Width = w;
    d->Resolution->Height = h;
}

const std::string &
MedVideoSource::getToken() {
    return d->token;
}

void
MedGetCompatibleVideoEncoderConfigurationsResponse::AddVideoEnc(  int w, int h ) {
    d->Configurations.push_back( soap_new_tt__VideoEncoderConfiguration(d->soap, -1) );
    d->Configurations.back()->Encoding =  tt__VideoEncoding__H264;
    d->Configurations.back()->Quality = 100.0f;
    d->Configurations.back()->Resolution = soap_new_tt__VideoResolution(d->soap, -1);
    d->Configurations.back()->Resolution->Width = w;
    d->Configurations.back()->Resolution->Height = h;
}

void
MedGetCompatibleVideoAnalyticsConfigurationsResponse::AddVideoAn() {
    d->Configurations.push_back( soap_new_tt__VideoAnalyticsConfiguration(d->soap, -1) );
    d->Configurations.back()->AnalyticsEngineConfiguration = soap_new_tt__AnalyticsEngineConfiguration(d->soap, -1);
    d->Configurations.back()->AnalyticsEngineConfiguration->AnalyticsModule.push_back(soap_new_tt__Config(d->soap, -1));
    d->Configurations.back()->AnalyticsEngineConfiguration->AnalyticsModule.back()->Type = "tt:CellMotionEngine";
    d->Configurations.back()->AnalyticsEngineConfiguration->AnalyticsModule.back()->Name = "CellMotion";
    d->Configurations.back()->AnalyticsEngineConfiguration->AnalyticsModule.back()->Parameters = soap_new_tt__ItemList(d->soap, -1);
}
