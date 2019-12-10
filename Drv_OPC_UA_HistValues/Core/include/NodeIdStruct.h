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

#ifndef _NODEIDSTRUCT_H_
#define _NODEIDSTRUCT_H_

#include"GuidStruct.h"

struct ByteStringStruct;

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(NodeIdStruct::clear, cleanup)
//lint -sem(NodeIdStruct::init, initializer)
typedef struct TBCORE_IF NodeIdStruct
{
	OTUInt16    namespaceIndex;
	unsigned char  identifierType;
	union
	{
		OTUInt32       numeric;
		OTChar*           pString;
		GuidStruct*       pGuid;
		ByteStringStruct* pByteString;
	} identifier;

	NodeIdStruct(void);
	NodeIdStruct(const NodeIdStruct& cp);
	NodeIdStruct(EnumNumericNodeId id);

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_NodeId& cp);
	EnumStatusCode get(OpcUa_NodeId& target) const;
#endif

	EnumStatusCode set(const NodeIdStruct& aSource);
	EnumStatusCode get(NodeIdStruct& aDestination) const;

	const NodeIdStruct& operator=(const NodeIdStruct& cp);
	bool operator==(const NodeIdStruct& toCompare) const;
	bool operator!=(const NodeIdStruct& toCompare) const;

	bool operator < (const NodeIdStruct& toCompare) const
	{
		return (compare(&toCompare) < 0);
	}

	int compare(const NodeIdStruct* pTarget) const
	{
		// quick comparison which will help in some cases
		if(pTarget == this)
		{
			return 0;
		}
		
		// compare namespace index...
		if(this->namespaceIndex < pTarget->namespaceIndex)
		{
			return -1;
		}
		else if(this->namespaceIndex > pTarget->namespaceIndex)
		{
			return 1;
		}

		// compare identifier types ...
		if(this->identifierType < pTarget->identifierType)
		{
			return -1;
		}
		else if(this->identifierType > pTarget->identifierType)
		{
			return 1;
		}

		// from here we have identical namespace index and identifier types
		switch(this->identifierType)
		{
		case EnumIdentifierType_Numeric:
			if(this->identifier.numeric < pTarget->identifier.numeric)
			{
				return -1;
			}
			else if(this->identifier.numeric > pTarget->identifier.numeric)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case EnumIdentifierType_String:
			return _tcscmp(this->identifier.pString, pTarget->identifier.pString);
		case EnumIdentifierType_Guid:
			return memcmp(this->identifier.pGuid, pTarget->identifier.pGuid, sizeof(struct GuidStruct));
		case EnumIdentifierType_Opaque:
			if(this->identifier.pByteString->length	< pTarget->identifier.pByteString->length)
			{
				return -1;
			}
			if(this->identifier.pByteString->length	> pTarget->identifier.pByteString->length)
			{
				return 1;
			}
			// if both are empty we return true;
			if(this->identifier.pByteString->length == 0)
			{
				return 0;
			}
			return memcmp(this->identifier.pByteString->pData,
				pTarget->identifier.pByteString->pData,
				this->identifier.pByteString->length);

		default:
			_REPORT_ASSERTION(_T("Unknown Identifier type;"));
		}
		return -1;
	}

	EnumStatusCode setNumeric_API(unsigned short nsIndex, OTUInt32 numeric);
	void setNumeric(OTUInt16 nsIndex, OTUInt32 numeric);
	void setNumeric(OTUInt32 numeric);
	EnumStatusCode setString_API(unsigned short nsIndex, const OTChar* string);
	EnumStatusCode setGuid_API(unsigned short nsIndex, const GuidStruct* guid);
	EnumStatusCode setOpaque_API(unsigned short nsIndex, const ByteStringStruct* byteString);


	tstring toString() const;
	static EnumStatusCode parse(const tstring& pString, NodeIdStruct& pNode);

	void clear(void);
	~NodeIdStruct(void);

	EnumStatusCode setNull_API(void);
	bool isNull_API(void) const;
	bool isNull() const;

}NodeIdStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
