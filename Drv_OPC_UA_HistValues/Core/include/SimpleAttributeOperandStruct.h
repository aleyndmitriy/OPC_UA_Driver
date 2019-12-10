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

#ifndef __SIMPLEATTRIBUTEOPERANDSTRUCT_H_
#define __SIMPLEATTRIBUTEOPERANDSTRUCT_H_
#if TB5_FILTER

#include "NodeIdStruct.h"
#include "QualifiedNameStruct.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(SimpleAttributeOperandStruct::clear, cleanup)
//lint -sem(SimpleAttributeOperandStruct::init, initializer)
typedef struct TBCORE_IF SimpleAttributeOperandStruct
{
	/*! NodeId of a TypeDefinitionNode.
	* This parameter restricts the operand to instances of the TypeDefinitionNode or one of its subtypes. */
	NodeIdStruct typeDefinitionId;

	/*! A relative path to a Node.
	* This parameter specifies a relative path using a list of BrowseNames instead of the RelativePath structure
	* used in the AttributeOperand.
	* The list of BrowseNames is equivalent to a RelativePath that specifies forward references which are subtypes
	* of the HierarchicalReferences ReferenceType.
	* If this list is empty the Node is the instance of the TypeDefinition. */
	OTUInt32 browsePath_count;
	QualifiedNameStruct* pBrowsePath;

	/*! Id of the Attribute. */
	EnumAttributeId attributeId;

	/*! This parameter is used to identify a single element of an array, or a single range of indexes for an array.
	* The first element is identified by index 0 (zero).
	* This parameter is ignored if the selected Node is not a Variable or the Value of a Variable is not an
	* array.
	* The parameter is null if not specifed.
	* All values in the array are used if this parameter is not specified. */
	NumericRangeStruct indexRange;

	SimpleAttributeOperandStruct();
	EnumStatusCode addBrowsePath(const QualifiedNameStruct* pQualifiedName);

	EnumStatusCode set(const SimpleAttributeOperandStruct&);
	EnumStatusCode get(SimpleAttributeOperandStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SimpleAttributeOperand&);
	EnumStatusCode get(OpcUa_SimpleAttributeOperand&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const SimpleAttributeOperandStruct& operator=(const SimpleAttributeOperandStruct& cp);
	bool operator==(const SimpleAttributeOperandStruct& toCompare) const;
	bool operator!=(const SimpleAttributeOperandStruct& toCompare) const;
	bool operator<(const SimpleAttributeOperandStruct& toCompare) const;
	bool operator>(const SimpleAttributeOperandStruct& toCompare) const;

	int compare(const SimpleAttributeOperandStruct* pTarget) const;

	void clear(void);
	~SimpleAttributeOperandStruct(void);

}SimpleAttributeOperandStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
