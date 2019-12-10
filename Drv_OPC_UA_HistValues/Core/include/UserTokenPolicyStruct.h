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

#ifndef _UserTokenPolicyStruct_H_
#define _UserTokenPolicyStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "Enums.h"

/*! Specifies a UserIdentityToken that a Server will accept. */
//lint -sem(UserTokenPolicyStruct::clear, cleanup)
//lint -sem(UserTokenPolicyStruct::init, initializer)
typedef struct TBCORE_IF UserTokenPolicyStruct
{
	/*! An identifier for the UserTokenPolicy assigned by the Server.
	* The Client specifies this value when it constructs a UserIdentityToken that
	* conforms to the policy.
	* This value is only unique within the context of a single Server. */
	OTChar* pPolicyId;

	/*! The type of user identity token required.
	* See enumeration type for available values. */
	EnumUserTokenType tokenType;

	/*! This field may only be specified if TokenType is ISSUEDTOKEN. A URI for the type of token.
	* Vendors may specify their own token. WS-Security tokens are sometimes identified by XML QualifiedNames.
	*
	* A URI for the token can be constructed by appending the name to namespace with a ":" separator.
	* The XML QualifiedName can be reconstructed by searching for the last ":" delimiter. */
	OTChar* pIssuedTokenType;

	/*! An optional URL for the token issuing service.
	* The meaning of this value depends on the issuedTokenType */
	OTChar* pIssuerEndpointUrl;

	/*! The security policy to use when encrypting or signing the UserToken when it is
	* passed to the Server in the ActivateSession request.
	*
	* The security policy for the SecureChannel is used if this value is omitted. */
	OTChar* pSecurityPolicyUri;


	UserTokenPolicyStruct();
	UserTokenPolicyStruct(const UserTokenPolicyStruct&);

	EnumStatusCode set(const UserTokenPolicyStruct&);
	EnumStatusCode get(UserTokenPolicyStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_UserTokenPolicy&);
	EnumStatusCode get(OpcUa_UserTokenPolicy&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const UserTokenPolicyStruct& operator=(const UserTokenPolicyStruct& cp);
	bool operator==(const UserTokenPolicyStruct& toCompare) const;
	bool operator!=(const UserTokenPolicyStruct& toCompare) const;
	bool operator<(const UserTokenPolicyStruct& toCompare) const;
	bool operator>(const UserTokenPolicyStruct& toCompare) const;

	int compare(const UserTokenPolicyStruct* pTarget) const;

	void clear(void);
	~UserTokenPolicyStruct(void);

	EnumStatusCode setPolicyId(const OTChar* pValue);
	EnumStatusCode setIssuerEndpointUrl(const OTChar* pValue);
	EnumStatusCode setSecurityPolicyUri(const OTChar* pValue);
	EnumStatusCode setIssuedTokenType(const OTChar* pValue);

} UserTokenPolicyStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
