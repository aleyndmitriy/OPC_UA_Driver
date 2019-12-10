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

#ifndef ATTRIBUTEOPERANDSTRUCT_H
#define ATTRIBUTEOPERANDSTRUCT_H
#if TB5_FILTER

#include "NodeIdStruct.h"
#include "RelativePathStruct.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure defining an 'attribute' operand for the where clauses in the filter. */
//lint -sem(AttributeOperandStruct::clear, cleanup)
//lint -sem(AttributeOperandStruct::init, initializer)
typedef struct TBCORE_IF AttributeOperandStruct
{
	/*! Id of a node from the type system. */
	NodeIdStruct nodeId;

	/*! An optional parameter used to identify or refer to an alias. An alias is a symbolic
	* name that can be used to alias this operand and use it in other location in the
	* filter structure. */
	OTChar* pAlias;

	/*! Browse path relative to the Node identified by the nodeId parameter. See 7.25
	* for the definition of RelativePath. */
	RelativePathStruct browsePath;

	/*! Id of the Attribute */
	EnumAttributeId attributeId;

	/*! This parameter is used to identify a single element of an array or a single range
	* of indexes for an array.
	* This parameter is not used if the specified Attribute is not an array. However, if
	* the specified Attribute is an array and this parameter is not used, then all
	* elements are to be included in the range. The parameter is null if not used. */
	NumericRangeStruct indexRange;


	AttributeOperandStruct();
	EnumStatusCode setAlias(const OTChar* pValue);

	EnumStatusCode set(const AttributeOperandStruct&);
	EnumStatusCode get(AttributeOperandStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_AttributeOperand&);
	EnumStatusCode get(OpcUa_AttributeOperand&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const AttributeOperandStruct& operator=(const AttributeOperandStruct& cp);
	bool operator==(const AttributeOperandStruct& toCompare) const;
	bool operator!=(const AttributeOperandStruct& toCompare) const;
	bool operator<(const AttributeOperandStruct& toCompare) const;
	bool operator>(const AttributeOperandStruct& toCompare) const;

	int compare(const AttributeOperandStruct* pTarget) const;

	void clear(void);
	~AttributeOperandStruct(void);

}AttributeOperandStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// TB5_FILTER
#endif	// ATTRIBUTEOPERANDSTRUCT_H
