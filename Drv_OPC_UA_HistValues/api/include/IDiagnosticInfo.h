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

#ifndef IDIAGNOSTICINFO_H
#define IDIAGNOSTICINFO_H

#include "Base.h"
#include "DiagnosticInfoStruct.h"

namespace SoftingOPCToolbox5
{
	// Forward declaration
	class StringTable;

	/*! The DiagnosticInfo data type contains diagnostic information that is returned by an OPC UA server.
	* Diagnostic information is vendor-specific and complements status codes defined
	* by the OPC UA specification.
	*
	* DiagnosticInfo contains the following information:
	* @li	A reference to a vendor-specific error or condition represented by
	*		the tuple (namespaceUri, symbolicId, locale, localizedText).
	* @li	A free-form string containing additional information.
	* @li	The status code and DiagnosticInfo originating from an underlying system.
	*
	* Please note that the strings in the tuple (namespaceUri, symbolicId, locale, localizedText) are
	* not stored in the DiagnosticInfo itself. Instead, DiagnosticInfo contains indices
	* that refer to a StringTable that is being provided with each response to a service call. */
	class TBC_EXPORT IDiagnosticInfo
	{
	public:
		/*! Destructor */
		virtual ~IDiagnosticInfo(){};

		/*! Returns the index into the StringTable that contains the NamespaceUri of the vendor-specific
		* error or condition.
		*
		* @see setNamespaceUri() */
		virtual OTInt32 getNamespaceUri() const = 0;
		/*! Returns the NamespaceUri of the vendor-specific error or condition. The provided
		* @p stringTable is used to resolve the string.
		*
		* @param stringTable	The string table that is used to resolve the NamespaceUri string.
		* @param namespaceUri	The NamespaceUri of the vendor-specific error or condition.
		*
		* @note If the server did not specify a NamespaceUri, this method will return EnumStatusCode_BadNotFound.
		*
		* @see setNamespaceUri() */
		virtual EnumStatusCode getNamespaceUri(ObjectPointer<const StringTable> stringTable, tstring& namespaceUri) const = 0;
		/*! Sets the index for the NamespaceUri of a vendor-specific error or condition. The index must
		* point to an entry in a StringTable that is conveyed to the client along with the DiagnosticInfo.
		*
		* @param index	The index of the NamespaceUri string in a StringTable associated with the DiagnosticInfo */
		virtual void setNamespaceUri(OTInt32 index) = 0;
		/*! @overload
		*
		* Sets the NamespaceUri of a vendor-specific error or condition. If the given @p stringTable does not contain
		* an entry for the @p namespaceUri string, the string is added to the StringTable.
		*
		* @param namespaceUri	The NamespaceUri of a vendor-specific error or condition
		* @param stringTable	The StringTable that should be used to store the NamespaceUri. */
		virtual EnumStatusCode setNamespaceUri(const tstring& namespaceUri, ObjectPointer<StringTable> stringTable) = 0;

		/*! Returns the index into the StringTable that contains the SymbolicId of the vendor-specific
		* error or condition.
		*
		* @see setSymbolicId() */
		virtual OTInt32 getSymbolicId() const = 0;
		/*! Returns the SymbolicId of the vendor-specific error or condition. The provided
		* @p stringTable is used to resolve the string.
		*
		* @param stringTable	The string table that is used to resolve the SymbolicId string.
		* @param symbolicId		The SymbolicId of the vendor-specific error or condition.
		*
		* @note If the server did not specify a SymbolicId, this method will return EnumStatusCode_BadNotFound.
		*
		* @see setSymbolicId() */
		virtual EnumStatusCode getSymbolicId(ObjectPointer<const StringTable> stringTable, tstring& symbolicId) const = 0;
		/*! Sets the index for the SymbolicId of a vendor-specific error or condition. The index must
		* point to an entry in a StringTable that is conveyed to the client along with the DiagnosticInfo.
		*
		* @param index	The index of the SymbolicId string in a StringTable associated with the DiagnosticInfo */
		virtual void setSymbolicId(OTInt32 index) = 0;
		/*! @overload
		*
		* Sets the SymbolicId of a vendor-specific error or condition. If the given @p stringTable does not contain
		* an entry for the @p symbolicId string, the string is added to the StringTable.
		*
		* @param symbolicId		The SymbolicId of a vendor-specific error or condition
		* @param stringTable	The StringTable that should be used to store the SymbolicId. */
		virtual EnumStatusCode setSymbolicId(const tstring& symbolicId, ObjectPointer<StringTable> stringTable) = 0;

		/*! Returns the index into the StringTable that contains the Locale-part
		* of the LocalizedText describing the symbolicId.
		*
		* @see setLocale() */
		virtual OTInt32 getLocale() const = 0;
		/*! Returns the Locale-part of the LocalizedText describing the symbolicId. The provided
		* @p stringTable is used to resolve the string.
		*
		* @param stringTable	The string table that is used to resolve the Locale string.
		* @param locale			The Locale-part of the symbolicId.
		*
		* @note If the server did not specify a Locale, this method will return EnumStatusCode_BadNotFound.
		*
		* @see setLocale() */
		virtual EnumStatusCode getLocale(ObjectPointer<const StringTable> stringTable, tstring& locale) const = 0;
		/*! Sets the index for the Locale-part of the LocalizedText describing the symbolicId. The index must
		* point to an entry in a StringTable that is conveyed to the client along with the DiagnosticInfo.
		*
		* @param index	The index of the Locale string in a StringTable associated with the DiagnosticInfo */
		virtual void setLocale(OTInt32 index) = 0;
		/*! @overload
		*
		* Sets the Locale-part of the LocalizedText describing the symbolicId. If the given @p stringTable does not contain
		* an entry for the @p locale string, the string is added to the StringTable.
		*
		* @param locale	The Locale of a vendor-specific error or condition
		* @param stringTable	The StringTable that should be used to store the Locale. */
		virtual EnumStatusCode setLocale(const tstring& locale, ObjectPointer<StringTable> stringTable) = 0;

		/*! Returns the index into the StringTable that contains the LocalizedText of the vendor-specific
		* error or condition.
		*
		* @see setLocalizedText() */
		virtual OTInt32 getLocalizedText() const = 0;
		/*! Returns the vendor-specific LocalizedText string that describes the symbolicId. The provided
		* @p stringTable is used to resolve the string.
		*
		* @param stringTable	The string table that is used to resolve the LocalizedText string.
		* @param localizedText	The vendor-specific LocalizedText string that describes the symbolicId.
		*
		* @note If the server did not specify a LocalizedText, this method will return EnumStatusCode_BadNotFound.
		*
		* @see setLocalizedText() */
		virtual EnumStatusCode getLocalizedText(ObjectPointer<const StringTable> stringTable, tstring& localizedText) const = 0;
		/*! Sets the index for the vendor-specific LocalizedText string that describes the symbolicId. The index must
		* point to an entry in a StringTable that is conveyed to the client along with the DiagnosticInfo.
		*
		* @param index	The index of the LocalizedText string in a StringTable associated with the DiagnosticInfo */
		virtual void setLocalizedText(OTInt32 index) = 0;
		/*! @overload
		*
		* Sets the vendor-specific LocalizedText string that describes the symbolicId. If the given @p stringTable
		* does not contain an entry for the @p localizedText string, the string is added to the StringTable.
		*
		* @param localizedText	The vendor-specific LocalizedText string that describes the symbolicId.
		* @param stringTable	The StringTable that should be used to store the LocalizedText. */
		virtual EnumStatusCode setLocalizedText(const tstring& localizedText, ObjectPointer<StringTable> stringTable) = 0;

		/*! Returns vendor-specific diagnostic information.
		*
		* @see setAdditionalInfo() */
		virtual tstring getAdditionalInfo() const = 0;
		/*! Sets vendor-specific diagnostic information.
		*
		* @param additionalInfo Additional vendor-specific diagnostic information. */
		virtual EnumStatusCode setAdditionalInfo(const tstring& additionalInfo) = 0;

		/*! Returns The status code from the inner operation.
		*
		* @see setInnerStatusCode() */
		virtual EnumStatusCode getInnerStatusCode() const = 0;
		/*! Sets the status code from the inner operation.
		*
		* Many applications will make calls into underlying systems during OPC UA request processing. An OPC UA server
		* has the option of reporting the status from the underlying system in the diagnostic info.
		*
		* @param innerStatusCode	The status code associated with an inner operation.
		*
		* @see setInnerDiagnosticInfo() */
		virtual void setInnerStatusCode(EnumStatusCode innerStatusCode) = 0;

		/*! Returns diagnostic information associated with an inner status code.
		*
		* @note	Please note that inner diagnostic information is optional.
		*		If no diagnostic information has been provided, this method returns NULL.
		*
		* @see setInnerDiagnosticInfo() setInnerStatusCode() */
		virtual const IDiagnosticInfo* getInnerDiagnosticInfo() const = 0;
		/*! Sets diagnostic information associated with an inner status code.
		* Please note that inner diagnostic information is optional.
		*
		* @param pInnerDiagnosticInfo	Diagnostic information associated with an inner status code.
		*								This method accepts a NULL pointer if the server does not wish to
		*								provide diagnostic information for an inner status code. */
		virtual EnumStatusCode setInnerDiagnosticInfo(const IDiagnosticInfo* pInnerDiagnosticInfo) = 0;

		/*! Returns a string that contains a textual representation of the DiagnosticInfo instance
		*
		* @param stringTable	The string table that is used to resolve the strings referenced
		*						by the DiagnosticInfo instance. */
		virtual tstring toString(ObjectPointer<const StringTable> stringTable) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDiagnosticInfo* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDiagnosticInfo& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDiagnosticInfo* other) const = 0;
		/*! @overload */
		virtual int compare(const IDiagnosticInfo& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDiagnosticInfo& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDiagnosticInfo& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDiagnosticInfo
} // end namespace

#endif	// IDIAGNOSTICINFO_H
