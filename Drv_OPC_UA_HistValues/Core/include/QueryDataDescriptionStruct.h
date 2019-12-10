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

#ifndef _QueryDataDescriptionStruct_H_
#define _QueryDataDescriptionStruct_H_
#if TB5_QUERY

#include "RelativePathStruct.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(QueryDataDescriptionStruct::clear, cleanup)
//lint -sem(QueryDataDescriptionStruct::init, initializer)
typedef struct TBCORE_IF QueryDataDescriptionStruct
{
	/*! @brief Browse path relative to the originating Node that identifies the Node
	 * which contains the data that is being requested, where the originating
	 * Node is an instance Node of the type defined by the type definition
	 * Node. The instance Nodes are further limited by the filter provided as
	 * part of this call.
	 *
	 * This relative path could end on a Reference, in which case the
	 * ReferenceDescription of the Reference would be returned as its value. */
	RelativePathStruct relativePath;

	/*! @brief Id of the Attribute. If the RelativePath ended in a Reference
	 * then this parameter is 0 and ignored by the server. */
	EnumAttributeId attributeId;

	/*! @brief This parameter is used to identify a single element of a structure or an
	 * array, or a single range of indexes for arrays. If a range of elements
	 * are specified, the values are returned as a composite.
	 *
	 * This parameter is null if the specified Attribute is not an array or a
	 * structure. However, if the specified Attribute is an array or a structure,
	 * and this parameter is null, then all elements are to be included in the
	 * range. */
	NumericRangeStruct indexRange;


	QueryDataDescriptionStruct();
	QueryDataDescriptionStruct(const QueryDataDescriptionStruct&);

	EnumStatusCode set(const QueryDataDescriptionStruct&);
	EnumStatusCode get(QueryDataDescriptionStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_QueryDataDescription&);
	EnumStatusCode get(OpcUa_QueryDataDescription&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const QueryDataDescriptionStruct& operator=(const QueryDataDescriptionStruct& cp);
	bool operator==(const QueryDataDescriptionStruct& toCompare) const;
	bool operator!=(const QueryDataDescriptionStruct& toCompare) const;
	bool operator<(const QueryDataDescriptionStruct& toCompare) const;
	bool operator>(const QueryDataDescriptionStruct& toCompare) const;

	int compare(const QueryDataDescriptionStruct* pTarget) const;

	void clear(void);
	~QueryDataDescriptionStruct(void);
} QueryDataDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
