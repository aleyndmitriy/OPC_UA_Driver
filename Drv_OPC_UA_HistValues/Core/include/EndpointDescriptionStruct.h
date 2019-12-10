/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2019                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             dataFEED OPC UA C++ Server & Client SDK           *
*                                                                            *
* VERSION                  5.61.0                                            *
*                                                                            *
* DATE                     05.11.2019                                        *
*                                                                            *
*****************************************************************************/

#ifndef __ENDPOINTDESCRIPTIONSTRUCT_H_
#define __ENDPOINTDESCRIPTIONSTRUCT_H_

#include "ApplicationDescriptionStruct.h"
#include "UserTokenPolicyStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Stores information related to an endpoint. This is usually used, when calling the "GetEndpoints" or "FindServer"
* on the Application object. */
//lint -sem(EndpointDescriptionStruct::clear, cleanup)
//lint -sem(EndpointDescriptionStruct::init, initializer)
typedef struct TBCORE_IF EndpointDescriptionStruct
{
	/*! The URL of this Endpoint. Clients that want to connect to this Endpoint have to use this URL. */
	OTChar* pEndpointUrl;

	/*! The application description of the hosting server. */
	ApplicationDescriptionStruct server;

	/*! The application instance Certificate issued to the Server. A Server shall prove possession by using the
	* private key to sign the Nonce provided by the Client in the request.
	* The Client shall verify that this Certificate is the same as the one used to create the SecureChannel. */
	ByteStringStruct serverCertificate;

	/*! The messageSecurityMode is an enumeration that specifies what security should be applied to messages exchanges
	* during a Session.
	* See enumeration type for possible values. */
	EnumMessageSecurityMode messageSecurityMode;

	/*! The URI for SecurityPolicy to use when securing messages. */
	OTChar* pSecurityPolicy;

	/*! The user identity tokens that the Server will accept. One of these have to be used for configuring a Client::Session. */
	unsigned userIdentityTokens_count;
	UserTokenPolicyStruct* userIdentityTokens;

	/*! The URI of the Transport Profile supported by the Endpoint. */
	OTChar* pTransportProfile;

	/*! A numeric value that indicates how secure the EndpointDescription is compared to other EndpointDescriptions
	* for the same Server. A value of 0 indicates that the EndpointDescription is not recommended and is only
	* supported for backward compatibility. */
	unsigned char securityLevel;


	EndpointDescriptionStruct();
	EnumStatusCode setEndpointUrl(const OTChar* pValue);
	EnumStatusCode setServerCertificate(unsigned length, const unsigned char* pValue);
	EnumStatusCode getServerCertificate(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setSecurityPolicy(const OTChar* pValue);
	EnumStatusCode setUserIdentityTokens(unsigned UserIdentityTokensCount, const UserTokenPolicyStruct* UserIdentityTokens);
	EnumStatusCode setTransportProfile(const OTChar* pValue);

	EnumStatusCode set(const EndpointDescriptionStruct&);
	EnumStatusCode get(EndpointDescriptionStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_EndpointDescription&);
	EnumStatusCode get(OpcUa_EndpointDescription&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const EndpointDescriptionStruct& operator=(const EndpointDescriptionStruct& cp);
	bool operator==(const EndpointDescriptionStruct& toCompare) const;
	bool operator!=(const EndpointDescriptionStruct& toCompare) const;
	bool operator<(const EndpointDescriptionStruct& toCompare) const;
	bool operator>(const EndpointDescriptionStruct& toCompare) const;

	int compare(const EndpointDescriptionStruct* pTarget) const;
	tstring toString() const;

	void clear(void);
	~EndpointDescriptionStruct(void);

}EndpointDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
