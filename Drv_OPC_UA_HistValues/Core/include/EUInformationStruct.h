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

#ifndef EUINFORMATIONSTRUCT_H
#define EUINFORMATIONSTRUCT_H

#include "LocalizedTextStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure describing engineering units. */
//lint -sem(EUInformationStruct::clear, cleanup)
//lint -sem(EUInformationStruct::init, initializer)
typedef struct TBCORE_IF EUInformationStruct
{
	/*! The displayName of the engineering unit is typically the abbreviation of the engineering unit, e.g. "h"
	* for hour or m/s for meter per second. */
	LocalizedTextStruct displayName;

	/*! Identifies the organization (company, standards organization) that defines the EUInformation. */
	OTChar* pNamespaceUri;

	/*! Identifier for programmatic evaluation. */
	OTInt32 unitId;

	/*! Contains an additional description for the given Unit. */
	LocalizedTextStruct description;


	EUInformationStruct();
	EnumStatusCode setNamespaceUri(const OTChar* pValue);

	EnumStatusCode set(const EUInformationStruct&, bool targetIsMemberOfNode = false);
	EnumStatusCode get(EUInformationStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_EUInformation&);
	EnumStatusCode get(OpcUa_EUInformation&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const EUInformationStruct& operator=(const EUInformationStruct& cp);
	bool operator==(const EUInformationStruct& toCompare) const;
	bool operator!=(const EUInformationStruct& toCompare) const;
	bool operator<(const EUInformationStruct& toCompare) const;
	bool operator>(const EUInformationStruct& toCompare) const;

	int compare(const EUInformationStruct* pTarget) const;

	void clear(void);
	~EUInformationStruct(void);

}EUInformationStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// EUINFORMATIONSTRUCT_H
