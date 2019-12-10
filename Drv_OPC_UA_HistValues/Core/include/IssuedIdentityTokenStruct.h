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

#ifndef _IssuedIdentityTokenStruct_H_
#define _IssuedIdentityTokenStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "ByteStringStruct.h"

//lint -sem(IssuedIdentityTokenStruct::clear, cleanup)
//lint -sem(IssuedIdentityTokenStruct::init, initializer)
typedef struct TBCORE_IF IssuedIdentityTokenStruct
{
	/*! The data of this token */
	ByteStringStruct tokenData;

	/*! The encryptionAlgorithm */
	OTChar* pEncryptionAlgorithm;

	/*! PolicyId */
	OTChar* pPolicyId;


	IssuedIdentityTokenStruct();
	IssuedIdentityTokenStruct(const IssuedIdentityTokenStruct&);

	EnumStatusCode set(const IssuedIdentityTokenStruct&);
	EnumStatusCode get(IssuedIdentityTokenStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_IssuedIdentityToken&);
	EnumStatusCode get(OpcUa_IssuedIdentityToken&) const;
	EnumStatusCode setPolicyId(const OpcUa_String& pPolId);
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	EnumStatusCode setEncryptionAlgorithm(const OTChar* pValue);
	EnumStatusCode setData(unsigned length, const unsigned char* pValue);
	EnumStatusCode getData(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setPolicyId(const tstring& value);

	const IssuedIdentityTokenStruct& operator=(const IssuedIdentityTokenStruct& cp);
	bool operator==(const IssuedIdentityTokenStruct& toCompare) const;
	bool operator!=(const IssuedIdentityTokenStruct& toCompare) const;
	bool operator<(const IssuedIdentityTokenStruct& toCompare) const;
	bool operator>(const IssuedIdentityTokenStruct& toCompare) const;

	int compare(const IssuedIdentityTokenStruct* pTarget) const;

	tstring toString() const;

	void clear(void);

	~IssuedIdentityTokenStruct(void);
	void* operator new(size_t s) { return OTAllocateMemory(s); }
	void operator delete(void* p) { return OTFreeMemory(p); }
} IssuedIdentityTokenStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
