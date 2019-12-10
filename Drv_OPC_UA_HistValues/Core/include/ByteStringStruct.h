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

#ifndef BYTESTRINGSTRUCT_H
#define BYTESTRINGSTRUCT_H

#include <vector>
#include "OTMemory.h"

#ifdef OT_COMPILATION
#include "opcua_platformdefs.h"
#include "opcua_builtintypes.h"
#include "opcua_types.h"
#include "opcua_p_types.h"
#include "opcua_memory.h"
#include "opcua_string.h"
#include "opcua_crypto.h"
#endif

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(ByteStringStruct::clear, cleanup)
//lint -sem(ByteStringStruct::init, initializer)
typedef struct TBCORE_IF ByteStringStruct
{
	OTUInt32	length;
	OTUInt8*	pData;

	ByteStringStruct(void);
	ByteStringStruct(const ByteStringStruct&);
	ByteStringStruct(const OTUInt32 size, const OTUInt8* src);

	~ByteStringStruct(void);

	EnumStatusCode set(const ByteStringStruct& cp);
	EnumStatusCode get(ByteStringStruct& target) const;
	EnumStatusCode get(OTUInt32* len, OTUInt8** ppData) const;

	EnumStatusCode init(const OTUInt32 size, const OTUInt8* src);
	void clear();

	OTUInt32 getLength(void) const;
	const OTUInt8* getData(void) const;

	EnumStatusCode alloc(OTUInt32 size);

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ByteString& target);
	EnumStatusCode get(OpcUa_ByteString& target) const;
#endif

	bool operator==(const ByteStringStruct& bs) const;
	bool operator!=(const ByteStringStruct& bs) const;

	int compare(const ByteStringStruct& bs) const;
	int compare(const ByteStringStruct* bs) const;

	EnumStatusCode getStringFromUtf8_API(OTChar*& pTargetString) const;
	EnumStatusCode getStringFromUtf8(tstring& targetString) const;
	EnumStatusCode setUtf8FromString(const OTChar* pString);

	tstring toString(void) const;

	EnumStatusCode getRange(const std::pair<OTUInt32, OTUInt32>& range, ByteStringStruct& target);
	EnumStatusCode replaceRange(const ByteStringStruct& source, const std::pair<OTUInt32, OTUInt32>& range);

	ByteStringStruct& operator=(const ByteStringStruct& src);

} ByteStringStruct;

typedef ByteStringStruct XmlElementStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BYTESTRINGSTRUCT_H
