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

#ifndef _QueryDataSetStruct_H_
#define _QueryDataSetStruct_H_
#if TB5_QUERY

#include "ExpandedNodeIdStruct.h"
#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(QueryDataSetStruct::clear, cleanup)
//lint -sem(QueryDataSetStruct::init, initializer)
typedef struct TBCORE_IF QueryDataSetStruct
{
	/*! @brief The NodeId for this Node description. */
	ExpandedNodeIdStruct nodeId;

	/*! @brief The NodeId for the type definition for this Node description. */
	ExpandedNodeIdStruct typeDefinitionNode;

	/*! @brief Values for the selected Attributes.
	 *
	 * The order of returned items matches the order of the requested items.
	 * There is an entry for each requested item for the  given TypeDefinitionNode
	 * that matches the selected instance, this includes any related nodes that were
	 * specified using a relative path from the selected instance's TypeDefinitionNode.
	 *
	 * If no values where found for a given requested item a null value is return for
	 * that item. If multiple values exist for a requested item then an array of values
	 * is returned.
	 *
	 * If the requested item is a reference then a ReferenceDescription or array of
	 * ReferenceDescriptions are returned for that item. */
	ValueStruct* pValues;
	OTUInt32 values_count;


	QueryDataSetStruct();
	QueryDataSetStruct(const QueryDataSetStruct&);

	EnumStatusCode set(const QueryDataSetStruct&);
	EnumStatusCode get(QueryDataSetStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_QueryDataSet&);
	EnumStatusCode get(OpcUa_QueryDataSet&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const QueryDataSetStruct& operator=(const QueryDataSetStruct& cp);
	bool operator==(const QueryDataSetStruct& toCompare) const;
	bool operator!=(const QueryDataSetStruct& toCompare) const;
	bool operator<(const QueryDataSetStruct& toCompare) const;
	bool operator>(const QueryDataSetStruct& toCompare) const;

	int compare(const QueryDataSetStruct* pTarget) const;

	void clear(void);
	~QueryDataSetStruct(void);
} QueryDataSetStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
