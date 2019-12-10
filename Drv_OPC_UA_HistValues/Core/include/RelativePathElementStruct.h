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

#ifndef __RELATIVEPATHELEMENTSTRUCT_H_
#define __RELATIVEPATHELEMENTSTRUCT_H_

#include "NodeIdStruct.h"
#include "QualifiedNameStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure defining the References and BrowseNames to follow for a RelativePath. */
//lint -sem(RelativePathElementStruct::clear, cleanup)
//lint -sem(RelativePathElementStruct::init, initializer)
typedef struct TBCORE_IF RelativePathElementStruct
{
	/*! The type of reference to follow from the current node.
	* The current path can not be followed any further if the referenceTypeId is not
	* available on the Node instance. */
	NodeIdStruct referenceTypeId;

	/*! Indicates whether the inverse Reference should be followed. The inverse
	* reference is followed if this value is TRUE. */
	bool isInverse;

	/*! Indicates whether subtypes of the ReferenceType should be followed. Subtypes are included if this value
	* is TRUE. */
	bool includeSubtypes;

	/*! The BrowseName of the target node.
	* The final element may have an empty targetName. In this situation all targets of
	* the references identified by the referenceTypeId are the targets of the RelativePath.
	* The targetName shall be specified for all other elements.
	* The current path can not be followed any further if no targets with the specified BrowseName exist. */
	QualifiedNameStruct targetName;


	RelativePathElementStruct();

	EnumStatusCode set(const RelativePathElementStruct&);
	EnumStatusCode get(RelativePathElementStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_RelativePathElement&);
	EnumStatusCode get(OpcUa_RelativePathElement&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	static EnumStatusCode parse(const tstring& reader, RelativePathElementStruct& target, size_t& sizeConsumed, void* context = NULL);


	const RelativePathElementStruct& operator=(const RelativePathElementStruct& cp);
	bool operator==(const RelativePathElementStruct& toCompare) const;
	bool operator!=(const RelativePathElementStruct& toCompare) const;
	bool operator<(const RelativePathElementStruct& toCompare) const;
	bool operator>(const RelativePathElementStruct& toCompare) const;

	int compare(const RelativePathElementStruct* pTarget) const;

	void clear(void);
	~RelativePathElementStruct(void);

}RelativePathElementStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
