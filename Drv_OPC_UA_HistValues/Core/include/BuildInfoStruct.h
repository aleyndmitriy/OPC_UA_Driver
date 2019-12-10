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

#ifndef _BuildInfoStruct_H_
#define _BuildInfoStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"

/*! Information that describes the build of the software. */
//lint -sem(BuildInfoStruct::clear, cleanup)
//lint -sem(BuildInfoStruct::init, initializer)
typedef struct TBCORE_IF BuildInfoStruct
{
	/*! URI that identifies the software. */
	OTChar* pProductUri;

	/*! Name of the software manufacturer. */
	OTChar* pManufacturerName;

	/*! Name of the software. */
	OTChar* pProductName;

	/*! Software version. */
	OTChar* pSoftwareVersion;

	/*! Build number. */
	OTChar* pBuildNumber;

	/*! Date and time of the build. */
	DateTimeStruct buildDate;


	BuildInfoStruct();
	BuildInfoStruct(const BuildInfoStruct&);

	EnumStatusCode setProductUri(const OTChar* pValue);
	EnumStatusCode setManufacturerName(const OTChar* pValue);
	EnumStatusCode setProductName(const OTChar* pValue);
	EnumStatusCode setSoftwareVersion(const OTChar* pValue);
	EnumStatusCode setBuildNumber(const OTChar* pValue);
	EnumStatusCode setBuildDate(const DateTimeStruct& value);

	tstring getProductUri() const;
	tstring getManufacturerName() const;
	tstring getProductName() const;
	tstring getSoftwareVersion() const;
	tstring getBuildNumber() const;
	const DateTimeStruct& getBuildDate() const;

	EnumStatusCode set(const BuildInfoStruct&);
	EnumStatusCode get(BuildInfoStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_BuildInfo&);
	EnumStatusCode get(OpcUa_BuildInfo&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const BuildInfoStruct& operator=(const BuildInfoStruct& cp);
	bool operator==(const BuildInfoStruct& toCompare) const;
	bool operator!=(const BuildInfoStruct& toCompare) const;
	bool operator<(const BuildInfoStruct& toCompare) const;
	bool operator>(const BuildInfoStruct& toCompare) const;

	int compare(const BuildInfoStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~BuildInfoStruct(void);
} BuildInfoStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
