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

#ifndef _X509IdentityTokenStruct_H_
#define _X509IdentityTokenStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "ByteStringStruct.h"

/*! Structure that stores X509 authentication token. */
//lint -sem(X509IdentityTokenStruct::clear, cleanup)
//lint -sem(X509IdentityTokenStruct::init, initializer)
typedef struct TBCORE_IF X509IdentityTokenStruct
{
	/*! The certificate used for authentication */
	ByteStringStruct certificateData;

	/*! The policy ID */
	OTChar* pPolicyId;

	/*! The private key of the certificate */
#ifdef OT_COMPILATION
	OpcUa_Key * pPrivateKey;
#else
	void * pPrivateKey;
#endif

	X509IdentityTokenStruct();
	X509IdentityTokenStruct(const X509IdentityTokenStruct&);
	~X509IdentityTokenStruct(void);

	EnumStatusCode set(const X509IdentityTokenStruct&);
	EnumStatusCode get(X509IdentityTokenStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_X509IdentityToken&);
	EnumStatusCode get(OpcUa_X509IdentityToken&) const;
	EnumStatusCode setPolicyId(const OpcUa_String& pPolId);
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	EnumStatusCode setCertificate(unsigned length, const unsigned char* pValue);
	EnumStatusCode getCertificate(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode loadPrivateKey(const tstring& privateKeyFilename, const tstring& password);
	EnumStatusCode setPolicyId(const tstring& value);

	const X509IdentityTokenStruct& operator=(const X509IdentityTokenStruct& cp);
	bool operator==(const X509IdentityTokenStruct& toCompare) const;
	bool operator!=(const X509IdentityTokenStruct& toCompare) const;
	bool operator<(const X509IdentityTokenStruct& toCompare) const;
	bool operator>(const X509IdentityTokenStruct& toCompare) const;

	int compare(const X509IdentityTokenStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	void* operator new(size_t s) { return OTAllocateMemory(s); }
	void operator delete(void* p) { return OTFreeMemory(p); }
} X509IdentityTokenStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
