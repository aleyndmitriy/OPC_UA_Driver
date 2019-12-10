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

#ifndef _NodeTypeDescriptionStruct_H_
#define _NodeTypeDescriptionStruct_H_
#if TB5_QUERY

#include "ExpandedNodeIdStruct.h"
#include "QueryDataDescriptionStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(NodeTypeDescriptionStruct::clear, cleanup)
//lint -sem(NodeTypeDescriptionStruct::init, initializer)
typedef struct TBCORE_IF NodeTypeDescriptionStruct
{
	/*!
	 * @brief NodeId of the originating TypeDefinitionNode of the instances for
	 * which data is to be returned.
	 */
	ExpandedNodeIdStruct typeDefinitionNode;

	/*!
	 * @brief A flag that indicates whether the Server should include instances of
	 * subtypes of the TypeDefinitionNode in the list of instances of the Node
	 * type.
	 */
	bool includeSubTypes;

	/*!
	 * @brief Specifies an Attribute or Reference from the originating
	 * typeDefinitionNode along a given relativePath for which to return data.
	 */
	QueryDataDescriptionStruct* pDataToReturn;
	OTUInt32 dataToReturn_count;


	NodeTypeDescriptionStruct();
	NodeTypeDescriptionStruct(const NodeTypeDescriptionStruct&);

	EnumStatusCode set(const NodeTypeDescriptionStruct&);
	EnumStatusCode get(NodeTypeDescriptionStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_NodeTypeDescription&);
	EnumStatusCode get(OpcUa_NodeTypeDescription&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const NodeTypeDescriptionStruct& operator=(const NodeTypeDescriptionStruct& cp);
	bool operator==(const NodeTypeDescriptionStruct& toCompare) const;
	bool operator!=(const NodeTypeDescriptionStruct& toCompare) const;
	bool operator<(const NodeTypeDescriptionStruct& toCompare) const;
	bool operator>(const NodeTypeDescriptionStruct& toCompare) const;

	int compare(const NodeTypeDescriptionStruct* pTarget) const;

	void clear(void);
	~NodeTypeDescriptionStruct(void);
} NodeTypeDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
