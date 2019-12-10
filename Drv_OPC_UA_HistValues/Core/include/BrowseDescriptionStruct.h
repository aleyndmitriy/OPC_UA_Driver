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

#ifndef __BROWSEDESCRIPTIONSTRUCT_H_
#define __BROWSEDESCRIPTIONSTRUCT_H_

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure class containing attributes used during the browse functionality. */
//lint -sem(BrowseDescriptionStruct::clear, cleanup)
//lint -sem(BrowseDescriptionStruct::init, initializer)
typedef struct TBCORE_IF BrowseDescriptionStruct
{
	/*! The nodeId where the browse starts. */
	NodeIdStruct nodeId;

	/*! Defines the direction into that the browse call is performed.
	* A browse can follow references in the forward direction of the given reference type, backward or along
	* both directions.
	* See definition of the enumeration type for available values. */
	EnumBrowseDirection browseDirection;

	/*! The nodeId of the reference type along that that the browse will be executed.
	* For instance a "hasSubtype" reference ID returns all nodes that are connected to the source node by that
	* reference type.
	* If the browseDirection attribute is set to "Forward" all nodeIds of subTypes of the source node are returned.
	*
	* In case of a "Backward" browse direction all nodeIds of nodes are returned which are baseTypes for the
	* source node (in this example typically one). */
	NodeIdStruct referenceTypeId;

	/*! If set to true all subtypes of the given reference type are also included.
	* If false only the exact matching reference type is considered during the browse and that means that an
	* abstract type is not allowed in the referenceTypeID.
	*
	* If true all subtypes of the given reference are also included in the browse operation (required for abstract
	* reference types). */
	bool includeSubtypes;

	/*! A bit coded enumeration of the NodeClasses of nodes to be considered in the browse call. If set to zero,
	* then all NodeClasses are returned.
	* The browse call can be limited that way to a set of node classes.
	*
	* See enumeration type for available values. */
	EnumNodeClass nodeClassMask;

	/*! Specifies the fields in the ReferenceDescription structure that should be returned.
	*
	* The fields are assigned the following bits:
	*
	* 0 ReferenceType
	*
	* 1 IsForward
	*
	* 2 NodeClass
	*
	* 3 BrowseName
	*
	* 4 DisplayName
	*
	* 5 TypeDefinition */
	EnumResultMask resultMask;


	BrowseDescriptionStruct();

	EnumStatusCode set(const BrowseDescriptionStruct&);
	EnumStatusCode get(BrowseDescriptionStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_BrowseDescription&);
	EnumStatusCode get(OpcUa_BrowseDescription&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const BrowseDescriptionStruct& operator=(const BrowseDescriptionStruct& cp);
	bool operator==(const BrowseDescriptionStruct& toCompare) const;
	bool operator!=(const BrowseDescriptionStruct& toCompare) const;
	bool operator<(const BrowseDescriptionStruct& toCompare) const;
	bool operator>(const BrowseDescriptionStruct& toCompare) const;

	int compare(const BrowseDescriptionStruct* pTarget) const;

	void clear(void);
	~BrowseDescriptionStruct(void);

}BrowseDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
