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

#ifndef __VIEWDESCRIPTIONSTRUCT_H_
#define __VIEWDESCRIPTIONSTRUCT_H_

#include "NodeIdStruct.h"
#include "DateTimeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Struct used for parameterization of the browse call (see Client::Session::browse()). */
//lint -sem(ViewDescriptionStruct::clear, cleanup)
//lint -sem(ViewDescriptionStruct::init, initializer)
typedef struct TBCORE_IF ViewDescriptionStruct
{
	/*! NodeId of the View to Query. A null value indicates the entire AddressSpace. */
	NodeIdStruct viewId;

	/*! The time date desired. The corresponding version is the one with the closest
	* previous creation timestamp. Either the Timestamp or the viewVersion
	* parameter may be set by a Client, but not both. If ViewVersion is set this
	* parameter shall be null. */
	DateTimeStruct timestamp;

	/*! The version number for the View desired. When Nodes are added to or removed
	* from a View, the value of a View's ViewVersion Property is updated. Either the
	* Timestamp or the viewVersion parameter may be set by a Client, but not both.
	* If timestamp is set this parameter shall be 0. The current view is used if timestamp is null and viewVersion
	* is 0. */
	OTUInt32 viewVersion;


	ViewDescriptionStruct();

	EnumStatusCode set(const ViewDescriptionStruct&);
	EnumStatusCode get(ViewDescriptionStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ViewDescription&);
	EnumStatusCode get(OpcUa_ViewDescription&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const ViewDescriptionStruct& operator=(const ViewDescriptionStruct& cp);
	bool operator==(const ViewDescriptionStruct& toCompare) const;
	bool operator!=(const ViewDescriptionStruct& toCompare) const;
	bool operator<(const ViewDescriptionStruct& toCompare) const;
	bool operator>(const ViewDescriptionStruct& toCompare) const;

	int compare(const ViewDescriptionStruct* pTarget) const;

	void clear(void);
	~ViewDescriptionStruct(void);

}ViewDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
