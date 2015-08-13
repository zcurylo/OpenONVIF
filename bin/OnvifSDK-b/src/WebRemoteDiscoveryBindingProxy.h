/* WebRemoteDiscoveryBindingProxy.h
   Generated by gSOAP 2.8.21 from web.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef WebRemoteDiscoveryBindingProxy_H
#define WebRemoteDiscoveryBindingProxy_H
#include "WebH.h"

class SOAP_CMAC RemoteDiscoveryBindingProxy
{ public:
	struct soap *soap;
	bool soap_own;
	/// Endpoint URL of service 'RemoteDiscoveryBindingProxy' (change as needed)
	const char *soap_endpoint;
	/// Variables globally declared in web.h (non-static)
	/// Constructor
	RemoteDiscoveryBindingProxy();
	/// Constructor to use/share an engine state
	RemoteDiscoveryBindingProxy(struct soap*);
	/// Constructor with endpoint URL
	RemoteDiscoveryBindingProxy(const char *url);
	/// Constructor with engine input+output mode control
	RemoteDiscoveryBindingProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	RemoteDiscoveryBindingProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	RemoteDiscoveryBindingProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~RemoteDiscoveryBindingProxy();
	/// Initializer used by constructors
	virtual	void RemoteDiscoveryBindingProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to default
	virtual	void reset();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Put SOAP Header in message
	virtual	void soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, char *wsa__MessageID, wsa__Relationship *wsa__RelatesTo, wsa__EndpointReferenceType *wsa__From, wsa__EndpointReferenceType *wsa__ReplyTo, wsa__EndpointReferenceType *wsa__FaultTo, char *wsa__To, char *wsa__Action, wsd__AppSequenceType *wsd__AppSequence);
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'Hello' (returns error code or SOAP_OK)
	virtual	int Hello(wsd__HelloType *dn__Hello, wsd__ResolveType &dn__HelloResponse) { return this->Hello(NULL, NULL, dn__Hello, dn__HelloResponse); }
	virtual	int Hello(const char *endpoint, const char *soap_action, wsd__HelloType *dn__Hello, wsd__ResolveType &dn__HelloResponse);

	/// Web service operation 'Bye' (returns error code or SOAP_OK)
	virtual	int Bye(wsd__ByeType *dn__Bye, wsd__ResolveType &dn__ByeResponse) { return this->Bye(NULL, NULL, dn__Bye, dn__ByeResponse); }
	virtual	int Bye(const char *endpoint, const char *soap_action, wsd__ByeType *dn__Bye, wsd__ResolveType &dn__ByeResponse);

	/// Web service operation 'Probe' (returns error code or SOAP_OK)
	virtual	int Probe(wsd__ProbeType *dn__Probe, wsd__ProbeMatchesType &dn__ProbeResponse) { return this->Probe(NULL, NULL, dn__Probe, dn__ProbeResponse); }
	virtual	int Probe(const char *endpoint, const char *soap_action, wsd__ProbeType *dn__Probe, wsd__ProbeMatchesType &dn__ProbeResponse);
};
#endif
