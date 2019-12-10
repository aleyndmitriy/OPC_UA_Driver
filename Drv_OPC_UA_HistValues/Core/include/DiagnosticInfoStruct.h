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

#ifndef DIAGNOSTICINFOSTRUCT_H
#define DIAGNOSTICINFOSTRUCT_H

class OTStringTable;

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*! A structure containing vendor-specific diagnostic information */
//lint -sem(DiagnosticInfoStruct::clear, cleanup)
//lint -sem(DiagnosticInfoStruct::init, initializer)
typedef struct TBCORE_IF DiagnosticInfoStruct
{
	/*! The symbolicId is defined within the context of a namespace. This namespace is
	* represented as a string and is conveyed to the Client in the stringTable parameter
	* of the ResponseHeader parameter. The namespaceIndex parameter contains the index
	* into the stringTable for this string. -1 indicates that no string is specified.
	*
	* The namespaceUri shall not be the standard OPC UA namespace. There are no symbolicIds
	* provided for standard StatusCodes.
	*/
	OTInt32 namespaceUri;

	/*! The symbolicId shall be used to identify a vendor-specific error or condition;
	* typically the result of some server internal operation. The maximum length of this
	* string is 32 characters. Servers wishing to return a numeric return code should convert
	* the return code into a string and use this string as symbolicId (e.g., "0xC0040007" or "-4").
	*
	* This symbolic identifier string is conveyed to the Client in the stringTable parameter of the
	* ResponseHeader parameter. The symbolicId parameter contains the index into the stringTable for
	* this string. -1 indicates that no string is specified.
	*
	* The symbolicId shall not contain StatusCodes. If the localizedText contains a translation for the
	* description of a StatusCode, the symbolicId is -1.
	*/
	OTInt32 symbolicId;

	/* The locale part of the vendor-specific localized text describing the symbolic id.
	* This localized text string is conveyed to the Client in the stringTable parameter of the
	* ResponseHeader parameter. The localizedTextIndex parameter contains the index into the
	* stringTable for this string. -1 indicates that no string is specified.
	*/
	OTInt32 locale;

	/* A vendor-specific localized text string describes the symbolic id. The maximum length
	* of this text string is 256 characters. This localized text string is conveyed to the Client
	* in the stringTable parameter of the ResponseHeader parameter. The localizedTextIndex parameter
	* contains the index into the stringTable for this string. -1 indicates that no string is specified.
	*
	* The localizedText refers to the symbolicId if present or the string that describes the standard
	* StatusCode if the server provides translations. If the index is -1, the server has no translation
	* to return and the client should use the invariant StatusCode description from the specification.
	*/
	OTInt32 localizedText;

	/* Vendor-specific diagnostic information. */
	OTChar* pAdditionalInfo;

	/* The StatusCode from the inner operation.
	* Many applications will make calls into underlying systems during OPC UA request processing.
	* An OPC UA Server has the option of reporting the status from the underlying system in the diagnostic info.
	*/
	EnumStatusCode innerStatusCode;

	/* The diagnostic info associated with the inner StatusCode. */
	struct DiagnosticInfoStruct* innerDiagnosticInfo;

	DiagnosticInfoStruct(void);
	DiagnosticInfoStruct(const DiagnosticInfoStruct& cp);

	/*! Initializes an instance of this structure. */
	void initialize_API();

	/*! Returns whether values for this instance have been defined or not */
	bool isNull() const;

#ifdef OT_COMPILATION
	EnumStatusCode getNamespaceUri_API(OTStringTable* pStringTable, tstring& namespaceUri) const;
	EnumStatusCode setNamespaceUri_API(const tstring& namespaceUri, OTStringTable* pStringTable);

	EnumStatusCode getSymbolicId_API(OTStringTable* pStringTable, tstring& symbolicId) const;
	EnumStatusCode setSymbolicId_API(const tstring& symbolicId, OTStringTable* pStringTable);

	EnumStatusCode getLocale_API(OTStringTable* pStringTable, tstring& locale) const;
	EnumStatusCode setLocale_API(const tstring& locale, OTStringTable* pStringTable);

	EnumStatusCode getLocalizedText_API(OTStringTable* pStringTable, tstring& localizedText) const;
	EnumStatusCode setLocalizedText_API(const tstring& localizedText, OTStringTable* pStringTable);
#endif

	EnumStatusCode setInnerDiagnosticInfo_API(const DiagnosticInfoStruct* pInnerDiagnosticInfo);

	tstring toString(OTStringTable* pStringTable);

	EnumStatusCode set(const DiagnosticInfoStruct& cp);
	EnumStatusCode get(DiagnosticInfoStruct& target) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DiagnosticInfo& target);
	EnumStatusCode get(OpcUa_DiagnosticInfo& target) const;
#endif

	int compare(const DiagnosticInfoStruct* pTarget) const;
	const DiagnosticInfoStruct& operator=(const DiagnosticInfoStruct& src);
	bool operator==(const DiagnosticInfoStruct& toCompare) const;
	bool operator!=(const DiagnosticInfoStruct& toCompare) const;

	EnumStatusCode setAdditionalInfo(const OTChar* pSrc);

	void clear(void);
	~DiagnosticInfoStruct(void);
} DiagnosticInfoStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DIAGNOSTICINFOSTRUCT_H
