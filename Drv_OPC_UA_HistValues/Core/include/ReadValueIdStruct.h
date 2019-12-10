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

#ifndef __READVALUEIDSTRUCT_H_
#define __READVALUEIDSTRUCT_H_

#include "NodeIdStruct.h"
#include "QualifiedNameStruct.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure used for defining the target of a read request (see Client::Session::Read()). On the server
* sided implementation this structure is a member of the ReadRequest and to be evaluated by the read's implementation. */
//lint -sem(ReadValueIdStruct::clear, cleanup)
//lint -sem(ReadValueIdStruct::init, initializer)
typedef struct TBCORE_IF ReadValueIdStruct
{
	/*! The NodeId from the node to read the value. */
	NodeIdStruct nodeId;

	/*! The attribute that shall be read from the server node (see enumeration type for possible values). Only
	* one attribute can be set (not a bit mask). */
	EnumAttributeId attributeId;

	/*! Defines by a string the index range or a requested value (only required for array values).
	* If empty the parameter is not used.
	* The indices are zero based. */
	NumericRangeStruct indexRange;


	ReadValueIdStruct();
	ReadValueIdStruct(const ReadValueIdStruct&);

	EnumStatusCode set(const ReadValueIdStruct&);
	EnumStatusCode get(ReadValueIdStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ReadValueId&);
	EnumStatusCode get(OpcUa_ReadValueId&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const ReadValueIdStruct& operator=(const ReadValueIdStruct& cp);
	bool operator==(const ReadValueIdStruct& toCompare) const;
	bool operator!=(const ReadValueIdStruct& toCompare) const;
	bool operator<(const ReadValueIdStruct& toCompare) const;
	bool operator>(const ReadValueIdStruct& toCompare) const;

	int compare(const ReadValueIdStruct* pTarget) const;

	void clear(void);
	~ReadValueIdStruct(void);

}ReadValueIdStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
