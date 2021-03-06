/* soapaddProxy.cpp
   Generated by gSOAP 2.8.28 from add.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapaddProxy.h"

addProxy::addProxy() : soap(SOAP_IO_DEFAULT)
{	addProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

addProxy::addProxy(const addProxy& rhs)
{	soap_copy_context(this, &rhs);
	this->soap_endpoint = rhs.soap_endpoint;
}

addProxy::addProxy(const struct soap &_soap) : soap(_soap)
{ }

addProxy::addProxy(const char *url) : soap(SOAP_IO_DEFAULT)
{	addProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

addProxy::addProxy(soap_mode iomode) : soap(iomode)
{	addProxy_init(iomode, iomode);
}

addProxy::addProxy(const char *url, soap_mode iomode) : soap(iomode)
{	addProxy_init(iomode, iomode);
	soap_endpoint = url;
}

addProxy::addProxy(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	addProxy_init(imode, omode);
}

addProxy::~addProxy()
{
	this->destroy();
	}

void addProxy::addProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:add", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

#ifndef WITH_PURE_VIRTUAL
addProxy *addProxy::copy()
{	addProxy *dup = SOAP_NEW_COPY(addProxy(*(struct soap*)this));
	return dup;
}
#endif

addProxy& addProxy::operator=(const addProxy& rhs)
{	soap_copy_context(this, &rhs);
	this->soap_endpoint = rhs.soap_endpoint;
	return *this;
}

void addProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void addProxy::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	addProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void addProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *addProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *addProxy::soap_fault()
{	return this->fault;
}

const char *addProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *addProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int addProxy::soap_close_socket()
{	return soap_closesock(this);
}

int addProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void addProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void addProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *addProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int addProxy::add(const char *endpoint, const char *soap_action, int a, int b, int *result)
{	struct soap *soap = this;
	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse *soap_tmp_ns__addResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost";
	soap_tmp_ns__add.a = a;
	soap_tmp_ns__add.b = b;
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__add(soap, &soap_tmp_ns__add);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_int(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__addResponse = soap_get_ns__addResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__addResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__addResponse->result)
		*result = *soap_tmp_ns__addResponse->result;
	return soap_closesock(soap);
}
/* End of client proxy code */
