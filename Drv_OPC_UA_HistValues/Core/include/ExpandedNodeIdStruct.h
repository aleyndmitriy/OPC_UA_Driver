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

#ifndef _EXPANDED_NODEID_H_
#define _EXPANDED_NODEID_H_

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(ExpandedNodeIdStruct::clear, cleanup)
//lint -sem(ExpandedNodeIdStruct::init, initializer)
typedef struct TBCORE_IF ExpandedNodeIdStruct
{
	NodeIdStruct      nodeId;
	OTChar*           pNamespaceUri;
	OTUInt32          serverIndex;

	ExpandedNodeIdStruct(void);
	ExpandedNodeIdStruct(const ExpandedNodeIdStruct& copy);
	~ExpandedNodeIdStruct(void);

	EnumStatusCode set(const ExpandedNodeIdStruct& cp);
	EnumStatusCode get(ExpandedNodeIdStruct& target) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExpandedNodeId& cp);
	EnumStatusCode get(OpcUa_ExpandedNodeId& target) const;
#endif

	EnumStatusCode set(const NodeIdStruct& cp);

	const ExpandedNodeIdStruct& operator=(const ExpandedNodeIdStruct& cp);
	bool operator==(const ExpandedNodeIdStruct& toCompare) const;
	bool operator!=(const ExpandedNodeIdStruct& toCompare) const;
	bool operator<(const ExpandedNodeIdStruct& toCompare) const;
	bool operator>(const ExpandedNodeIdStruct& toCompare) const;

	EnumStatusCode setNamespaceUri(const OTChar* pSrc);
	EnumStatusCode setNodeId(const NodeIdStruct& nodeId);

	int compare(const ExpandedNodeIdStruct* pTarget) const;

	tstring toString(void) const;
	static EnumStatusCode parse(const tstring& aString, ExpandedNodeIdStruct& pNode);
	void clear(void);
#ifdef OT_COMPILATION
	static void getNodeIdPointers(const std::vector<ExpandedNodeIdStruct>& expandedNodeIds, std::vector<const NodeIdStruct*>& nodeIdPointers);
#endif
}ExpandedNodeIdStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
