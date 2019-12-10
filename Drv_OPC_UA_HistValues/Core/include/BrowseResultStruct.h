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

#ifndef __BROWSERESULTSTRUCT_H_
#define __BROWSERESULTSTRUCT_H_

#include "ReferenceDescriptionStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! The result of a browse call for a single node. For each requested node in a browse call such a result
* is generated.
*
* Each BrowseResult can contain a ContinuationPoint to be used for a following BrowseNext call. These ContinuationPoints
* have to be released actively by a BrowseNext call. */
//lint -sem(BrowseResultStruct::clear, cleanup)
//lint -sem(BrowseResultStruct::init, initializer)
typedef struct TBCORE_IF BrowseResultStruct
{
	/*! The status code for the browse result of a single node. */
	EnumStatusCode statusCode;

	/*! The continuation point returned from the server.
	* If the browse result exceeds the max. references given for the related node a continuation point is returned
	* which can be used for a browseNext call.
	* If the value is empty no continuation point was created on the server. */
	ByteStringStruct continuationPoint;

	/*! The references returned from the server. Due to that each node can have more than one reference an array
	* of references is expected for each node. */
	unsigned references_count;
	ReferenceDescriptionStruct* references;


	BrowseResultStruct();
	EnumStatusCode setContinuationPoint(unsigned length, const unsigned char* pValue);
	EnumStatusCode getContinuationPoint(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setReferences(unsigned ReferencesCount, const ReferenceDescriptionStruct* References);

	EnumStatusCode set(const BrowseResultStruct&);
	EnumStatusCode get(BrowseResultStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_BrowseResult&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_BrowseResult&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const BrowseResultStruct& operator=(const BrowseResultStruct& cp);
	bool operator==(const BrowseResultStruct& toCompare) const;
	bool operator!=(const BrowseResultStruct& toCompare) const;
	bool operator<(const BrowseResultStruct& toCompare) const;
	bool operator>(const BrowseResultStruct& toCompare) const;

	int compare(const BrowseResultStruct* pTarget) const;

	void clear(void);
	~BrowseResultStruct(void);

}BrowseResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
