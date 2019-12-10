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

#ifndef ANONYMOUSIDENTITYTOKENSTRUCT_H
#define ANONYMOUSIDENTITYTOKENSTRUCT_H

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


//lint -sem(AnonymousIdentityTokenStruct::clear, cleanup)
//lint -sem(AnonymousIdentityTokenStruct::init, initializer)
typedef struct TBCORE_IF AnonymousIdentityTokenStruct
{
	/*! The policyId is an identifier, specified by the user identities returned from server during getEndpoints call.
	* This value is only unique within the context of a single Server. */
	OTChar* pPolicyId;


	AnonymousIdentityTokenStruct();
	AnonymousIdentityTokenStruct(const AnonymousIdentityTokenStruct&);

	EnumStatusCode set(const AnonymousIdentityTokenStruct&);
	EnumStatusCode get(AnonymousIdentityTokenStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_AnonymousIdentityToken&);
	EnumStatusCode get(OpcUa_AnonymousIdentityToken&) const;
	EnumStatusCode setPolicyId(const OpcUa_String& pPolId);
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	EnumStatusCode setPolicyId(const tstring& value);

	const AnonymousIdentityTokenStruct& operator=(const AnonymousIdentityTokenStruct& cp);
	bool operator==(const AnonymousIdentityTokenStruct& toCompare) const;
	bool operator!=(const AnonymousIdentityTokenStruct& toCompare) const;
	bool operator<(const AnonymousIdentityTokenStruct& toCompare) const;
	bool operator>(const AnonymousIdentityTokenStruct& toCompare) const;

	int compare(const AnonymousIdentityTokenStruct* pTarget) const;

	tstring toString() const;
	void clear(void);
	~AnonymousIdentityTokenStruct(void);
	void* operator new(size_t s) { return OTAllocateMemory(s); }
	void operator delete(void* p) { return OTFreeMemory(p); }
} AnonymousIdentityTokenStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ANONYMOUSIDENTITYTOKENSTRUCT_H
