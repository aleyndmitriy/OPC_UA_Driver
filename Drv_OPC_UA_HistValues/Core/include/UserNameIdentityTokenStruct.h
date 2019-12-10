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

#ifndef _UserNameIdentityTokenStruct_H_
#define _UserNameIdentityTokenStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "ByteStringStruct.h"

//lint -sem(UserNameIdentityTokenStruct::clear, cleanup)
//lint -sem(UserNameIdentityTokenStruct::init, initializer)
typedef struct TBCORE_IF UserNameIdentityTokenStruct
{
	/*! The username */
	OTChar* pUserName;

	/*! The password */
	ByteStringStruct password;

	/*! The encryption algorithm used.
	*
	* Note: On the client side, when connection, this field should not be filled in as it is automatically filled
	* in by the OT (depending on the security policy used), when this user token is actually sent to the server. */
	OTChar* pEncryptionAlgorithm;

	/*! The policy ID */
	OTChar* pPolicyId;


	UserNameIdentityTokenStruct();
	UserNameIdentityTokenStruct(const UserNameIdentityTokenStruct&);

	EnumStatusCode set(const UserNameIdentityTokenStruct&);
	EnumStatusCode get(UserNameIdentityTokenStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_UserNameIdentityToken&);
	EnumStatusCode get(OpcUa_UserNameIdentityToken&) const;
	EnumStatusCode setUserName(const OpcUa_String& userName);
	EnumStatusCode setEncryptionAlgorithm(const OpcUa_String& algoName);
	EnumStatusCode setPolicyId(const OpcUa_String& pPolId);
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	EnumStatusCode setUserName(const OTChar* pValue);
	EnumStatusCode setPassword(unsigned length, const unsigned char* pValue);
	EnumStatusCode getPassword(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setEncryptionAlgorithm(const OTChar* pValue);
	EnumStatusCode setPolicyId(const tstring& value);

	const UserNameIdentityTokenStruct& operator=(const UserNameIdentityTokenStruct& cp);
	bool operator==(const UserNameIdentityTokenStruct& toCompare) const;
	bool operator!=(const UserNameIdentityTokenStruct& toCompare) const;
	bool operator<(const UserNameIdentityTokenStruct& toCompare) const;
	bool operator>(const UserNameIdentityTokenStruct& toCompare) const;

	int compare(const UserNameIdentityTokenStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~UserNameIdentityTokenStruct(void);
	void* operator new(size_t s) { return OTAllocateMemory(s); }
	void operator delete(void* p) { return OTFreeMemory(p); }
} UserNameIdentityTokenStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
