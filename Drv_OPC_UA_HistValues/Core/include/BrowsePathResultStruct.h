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

#ifndef __BROWSEPATHRESULTSTRUCT_H_
#define __BROWSEPATHRESULTSTRUCT_H_

#include "BrowsePathTargetStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure that defines the list of results for the list of browse paths. */
//lint -sem(BrowsePathResultStruct::clear, cleanup)
//lint -sem(BrowsePathResultStruct::init, initializer)
typedef struct TBCORE_IF BrowsePathResultStruct
{
	/*! StatusCode for the browse path. */
	EnumStatusCode statusCode;

	/*! List of targets for the relativePath from the startingNode. */
	OTUInt32 targets_count;
	BrowsePathTargetStruct* pTargets;


	BrowsePathResultStruct();
	EnumStatusCode addTarget(const BrowsePathTargetStruct* pBrowsePathTarget);

	EnumStatusCode set(const BrowsePathResultStruct&);
	EnumStatusCode get(BrowsePathResultStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_BrowsePathResult&);
	EnumStatusCode get(OpcUa_BrowsePathResult&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const BrowsePathResultStruct& operator=(const BrowsePathResultStruct& cp);
	bool operator==(const BrowsePathResultStruct& toCompare) const;
	bool operator!=(const BrowsePathResultStruct& toCompare) const;
	bool operator<(const BrowsePathResultStruct& toCompare) const;
	bool operator>(const BrowsePathResultStruct& toCompare) const;

	int compare(const BrowsePathResultStruct* pTarget) const;

	void clear(void);
	~BrowsePathResultStruct(void);

}BrowsePathResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
