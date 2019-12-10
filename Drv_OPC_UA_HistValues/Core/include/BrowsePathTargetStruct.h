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

#ifndef __BROWSEPATHTARGETSTRUCT_H_
#define __BROWSEPATHTARGETSTRUCT_H_

#include "ExpandedNodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure that defines a list of targets for the relativePath from the startingNode. */
//lint -sem(BrowsePathTargetStruct::clear, cleanup)
//lint -sem(BrowsePathTargetStruct::init, initializer)
typedef struct TBCORE_IF BrowsePathTargetStruct
{
	/*! The identifier for a target of the RelativePath. */
	ExpandedNodeIdStruct targetId;

	/*! The index of the first unprocessed element in the RelativePath. */
	OTUInt32 remainingPathIndex;


	BrowsePathTargetStruct();

	EnumStatusCode set(const BrowsePathTargetStruct&);
	EnumStatusCode get(BrowsePathTargetStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_BrowsePathTarget&);
	EnumStatusCode get(OpcUa_BrowsePathTarget&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const BrowsePathTargetStruct& operator=(const BrowsePathTargetStruct& cp);
	bool operator==(const BrowsePathTargetStruct& toCompare) const;
	bool operator!=(const BrowsePathTargetStruct& toCompare) const;
	bool operator<(const BrowsePathTargetStruct& toCompare) const;
	bool operator>(const BrowsePathTargetStruct& toCompare) const;

	int compare(const BrowsePathTargetStruct* pTarget) const;

	void clear(void);
	~BrowsePathTargetStruct(void);

}BrowsePathTargetStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
