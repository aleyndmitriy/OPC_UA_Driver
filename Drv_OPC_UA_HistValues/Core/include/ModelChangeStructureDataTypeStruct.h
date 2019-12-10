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

#ifndef _ModelChangeStructureDataTypeStruct_H_
#define _ModelChangeStructureDataTypeStruct_H_
#if TB5_ALARMS

#ifdef OT_COMPILATION
class OTServerBaseNode;
typedef SOCmnPointer<OTServerBaseNode> OTServerBaseNodePtr;
#endif

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(ModelChangeStructureDataTypeStruct::clear, cleanup)
//lint -sem(ModelChangeStructureDataTypeStruct::init, initializer)
typedef struct TBCORE_IF ModelChangeStructureDataTypeStruct
{
	/*!
	 * The NodeId of the node that was changed. The client should assume that the
	 * affected node has been created or deleted, had a reference added or deleted, or the data type
	 * has changed.
	 */
	NodeIdStruct affected;

	/*!
	 * If the affected node was an Object or Variable, this member holds the NodeId of the
	 * affected node's type definition node. Otherwise, it holds null NodeId.
	 */
	NodeIdStruct affectedType;

	/*!
	 * Holds a bit-field that describes the changes to the affected node.
	 *
	 * @li	Bit 0: If set, indicates that the affected node has been added
	 * @li	Bit 1: If set, indicates that the affected node has been deleted
	 * @li	Bit 2: If set, indicates that a reference has been added. The affected node
	 *		may be either the source or target of a reference. Note that an added bidirectional
	 *		reference is reflected by two ModelChangeStructure entries.
	 * @li	Bit 3: If set, indicates that a reference has been removed. The affected node
	 *		may be either the source or target of a reference. Note that an added bidirectional
	 *		reference is reflected by two ModelChangeStructure entries.
	 * @li	Bit 4: If set, indicates that the DataType attribute of a Variable or VariableType
	 *		has changed.
	 * @li	Bit 5-7: Reserved for future use. Shall always be zero.
	 *
	 * A verb may identify several changes on the affected node at once. Note that all verbs
	 * shall always be considered in the context where the ModelChangeStructureDataType is used.
	 * A set bit 1 may indicate that a node was removed from a view but still exists in other views.
	 */
	OTUInt8 verb;


	ModelChangeStructureDataTypeStruct();
	ModelChangeStructureDataTypeStruct(const ModelChangeStructureDataTypeStruct&);

	EnumStatusCode set(const ModelChangeStructureDataTypeStruct&);
	EnumStatusCode get(ModelChangeStructureDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ModelChangeStructureDataType&);
	EnumStatusCode get(OpcUa_ModelChangeStructureDataType&) const;

	/*!
	 * Convenience method to populate this structure based on a node object
	 */
	EnumStatusCode set(OTServerBaseNodePtr affectedNode, OTUInt8 verbMask);

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const ModelChangeStructureDataTypeStruct& operator=(const ModelChangeStructureDataTypeStruct& cp);
	bool operator==(const ModelChangeStructureDataTypeStruct& toCompare) const;
	bool operator!=(const ModelChangeStructureDataTypeStruct& toCompare) const;
	bool operator<(const ModelChangeStructureDataTypeStruct& toCompare) const;
	bool operator>(const ModelChangeStructureDataTypeStruct& toCompare) const;

	int compare(const ModelChangeStructureDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ModelChangeStructureDataTypeStruct(void);
} ModelChangeStructureDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
