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

#ifndef __WRITEVALUESTRUCT_H_
#define __WRITEVALUESTRUCT_H_

#include "NodeIdStruct.h"
#include "DataValueStruct.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure used for parameterization of write requests and on server side as attribute of a write request. */
//lint -sem(WriteValueStruct::clear, cleanup)
//lint -sem(WriteValueStruct::init, initializer)
typedef struct TBCORE_IF WriteValueStruct
{
	/*! The NodeId of the node to write on. */
	NodeIdStruct nodeId;

	/*! The AttributeId of the attribute that shall be written (see enumeration type for possible values). */
	EnumAttributeId attributeId;

	/*! The string based index range of the values to be written (applies only to array types). See also ReadValueId
	* for more details. */
	NumericRangeStruct indexRange;

	/*! The value that shall be applied to the target write's target node. */
	DataValueStruct value;


	WriteValueStruct();

	EnumStatusCode set(const WriteValueStruct&);
	EnumStatusCode get(WriteValueStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_WriteValue&);
	EnumStatusCode get(OpcUa_WriteValue&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const WriteValueStruct& operator=(const WriteValueStruct& cp);
	bool operator==(const WriteValueStruct& toCompare) const;
	bool operator!=(const WriteValueStruct& toCompare) const;
	bool operator<(const WriteValueStruct& toCompare) const;
	bool operator>(const WriteValueStruct& toCompare) const;

	int compare(const WriteValueStruct* pTarget) const;

	void clear(void);
	~WriteValueStruct(void);

}WriteValueStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
