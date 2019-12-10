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

#ifndef DIAGNOSTICINFO_H
#define DIAGNOSTICINFO_H

#include "IDiagnosticInfo.h"
#include "InnerDiagnosticInfo.h"
#include "StringTable.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
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
	class TBC_EXPORT DiagnosticInfo
		: public IDiagnosticInfo
	{
	public:
		/*! Default constructor */
		DiagnosticInfo();
		/*! Constructs a copy of the given instance @p cp */
		DiagnosticInfo(const IDiagnosticInfo* cp);
		/*! @overload */
		DiagnosticInfo(const IDiagnosticInfo& cp);
		/*! @overload */
		DiagnosticInfo(const DiagnosticInfo& cp);

		/*! Destructor */
		virtual ~DiagnosticInfo();

		/*! Assigns the contents of @p cp to this instance */
		DiagnosticInfo& operator=(const IDiagnosticInfo* cp);
		/*! @overload */
		DiagnosticInfo& operator=(const IDiagnosticInfo& cp);
		/*! @overload */
		DiagnosticInfo& operator=(const DiagnosticInfo& cp);

		/* see IDiagnosticInfo::set */
		virtual EnumStatusCode set(const IDiagnosticInfo* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDiagnosticInfo& pSrc);

		/* see IDiagnosticInfo::compare */
		virtual int compare(const IDiagnosticInfo* other) const;
		/*! @overload */
		virtual int compare(const IDiagnosticInfo& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDiagnosticInfo& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDiagnosticInfo& other) const;

		/*! Returns whether the provided "diagnosticsToReturn" mask requires
		* the server to return diagnostics on service level. */
		static bool returnServiceLevelDiagnostics(EnumDiagnosticsToReturn diagnosticsToReturnMask);

		/*! Returns whether the provided "diagnosticsToReturn" mask requires
		* the server to return diagnostics on operation level. */
		static bool returnOperationLevelDiagnostics(EnumDiagnosticsToReturn diagnosticsToReturnMask);

		/* see IDiagnosticInfo::getNamespaceUri */
		virtual OTInt32 getNamespaceUri() const;
		/*! @overload */
		virtual EnumStatusCode getNamespaceUri(ObjectPointer<const StringTable> stringTable, tstring& namespaceUri) const;
		/* see IDiagnosticInfo::setNamespaceUri(OTInt32) */
		virtual void setNamespaceUri(OTInt32 index);
		/* see IDiagnosticInfo::setNamespaceUri(const tstring&, ObjectPointer<StringTable>) */
		virtual EnumStatusCode setNamespaceUri(const tstring& namespaceUri, ObjectPointer<StringTable> stringTable);

		/* see IDiagnosticInfo::getSymbolicId */
		virtual OTInt32 getSymbolicId() const;
		/*! @overload */
		virtual EnumStatusCode getSymbolicId(ObjectPointer<const StringTable> stringTable, tstring& symbolicId) const;
		/* see IDiagnosticInfo::setSymbolicId(OTIn32) */
		virtual void setSymbolicId(OTInt32 index);
		/* see IDiagnosticInfo::setSymbolicId(const tstring&, ObjectPointer<StringTable>) */
		virtual EnumStatusCode setSymbolicId(const tstring& symbolicId, ObjectPointer<StringTable> stringTable);

		/* see IDiagnosticInfo::getLocale */
		virtual OTInt32 getLocale() const;
		/*! @overload */
		virtual EnumStatusCode getLocale(ObjectPointer<const StringTable> stringTable, tstring& locale) const;
		/* see IDiagnosticInfo::setLocale(OTInt32) */
		virtual void setLocale(OTInt32 index);
		/* see IDiagnosticInfo::setLocale(const tstring&, ObjectPointer<StringTable>) */
		virtual EnumStatusCode setLocale(const tstring& locale, ObjectPointer<StringTable> stringTable);

		/* see IDiagnosticInfo::getLocalizedText */
		virtual OTInt32 getLocalizedText() const;
		/*! @overload */
		virtual EnumStatusCode getLocalizedText(ObjectPointer<const StringTable> stringTable, tstring& localizedText) const;
		/* see IDiagnosticInfo::setLocalizedText(OTInt32) */
		virtual void setLocalizedText(OTInt32 index);
		/* see IDiagnosticInfo::setLocalizedText(const tstring&, ObjectPointer<StringTable>) */
		virtual EnumStatusCode setLocalizedText(const tstring& localizedText, ObjectPointer<StringTable> stringTable);

		/* see IDiagnosticInfo::getAdditionalInfo */
		virtual tstring getAdditionalInfo() const;
		/* see IDiagnosticInfo::setAdditionalInfo */
		virtual EnumStatusCode setAdditionalInfo(const tstring& additionalInfo);

		/* see IDiagnosticInfo::getInnerStatusCode */
		virtual EnumStatusCode getInnerStatusCode() const;
		/* see IDiagnosticInfo::setInnerStatusCode */
		virtual void setInnerStatusCode(EnumStatusCode innerStatusCode);

		/* see IDiagnosticInfo::getInnerDiagnosticInfo */
		virtual const IDiagnosticInfo* getInnerDiagnosticInfo() const;
		/* see IDiagnosticInfo::setInnerDiagnosticInfo */
		virtual EnumStatusCode setInnerDiagnosticInfo(const IDiagnosticInfo* pInnerDiagnosticInfo);

		/* see IDiagnosticInfo::toString */
		virtual tstring toString(ObjectPointer<const StringTable> stringTable) const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		DiagnosticInfoStruct m_content;
		InnerDiagnosticInfo m_innerDiagnosticInfo;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DIAGNOSTICINFO_H
