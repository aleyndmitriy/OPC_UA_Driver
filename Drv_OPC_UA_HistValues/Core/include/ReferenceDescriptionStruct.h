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

#ifndef __REFERENCEDESCRIPTIONSTRUCT_H_
#define __REFERENCEDESCRIPTIONSTRUCT_H_

#include "NodeIdStruct.h"
#include "ExpandedNodeIdStruct.h"
#include "QualifiedNameStruct.h"
#include "LocalizedTextStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Return struct used for browse results. The content depends on the input parameter of the browse call returning
* the result. */
//lint -sem(ReferenceDescriptionStruct::clear, cleanup)
//lint -sem(ReferenceDescriptionStruct::init, initializer)
typedef struct TBCORE_IF ReferenceDescriptionStruct
{
	/*! The NodeId of the used reference type of this reference type. */
	NodeIdStruct referenceTypeId;

	/*! Signals in case of a true, that the returned reference is pointing to the returned Node. If false, the
	* returned Node is the Source of the returned reference. */
	bool isForward;

	/*! The NodeId of the related Node of this reference. */
	ExpandedNodeIdStruct nodeId;

	/*! The browse name of the referenced node. */
	QualifiedNameStruct browseName;

	/*! The DisplayName of the related Node of this reference. */
	LocalizedTextStruct displayName;

	/*! The NodeClass of the related Node of this reference. */
	EnumNodeClass nodeClass;

	/*! The NodeId of the type definition of the related Node of this reference. */
	ExpandedNodeIdStruct typeDefinition;


	ReferenceDescriptionStruct();
	ReferenceDescriptionStruct(const ReferenceDescriptionStruct&);

	EnumStatusCode set(const ReferenceDescriptionStruct&);
	EnumStatusCode get(ReferenceDescriptionStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ReferenceDescription&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_ReferenceDescription&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const ReferenceDescriptionStruct& operator=(const ReferenceDescriptionStruct& cp);
	bool operator==(const ReferenceDescriptionStruct& toCompare) const;
	bool operator!=(const ReferenceDescriptionStruct& toCompare) const;
	bool operator<(const ReferenceDescriptionStruct& toCompare) const;
	bool operator>(const ReferenceDescriptionStruct& toCompare) const;

	int compare(const ReferenceDescriptionStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ReferenceDescriptionStruct(void);

}ReferenceDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
