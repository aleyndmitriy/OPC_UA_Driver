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

#ifndef INNERDIAGNOSTICINFO_H
#define INNERDIAGNOSTICINFO_H

#include "IDiagnosticInfo.h"
#include "StringTable.h"

namespace SoftingOPCToolbox5
{
	/*! @copydoc IDiagnosticInfo */
	class TBC_EXPORT InnerDiagnosticInfo
		: public IDiagnosticInfo
	{
	public:
		/*! Constructor */
		InnerDiagnosticInfo();

		/*! Destructor */
		virtual ~InnerDiagnosticInfo();

		virtual OTInt32 getNamespaceUri() const;
		virtual EnumStatusCode getNamespaceUri(ObjectPointer<const StringTable> stringTable, tstring& namespaceUri) const;
		virtual void setNamespaceUri(OTInt32 value);
		virtual EnumStatusCode setNamespaceUri(const tstring& namespaceUri, ObjectPointer<StringTable> stringTable);

		virtual OTInt32 getSymbolicId() const;
		virtual EnumStatusCode getSymbolicId(ObjectPointer<const StringTable> stringTable, tstring& symbolicId) const;
		virtual void setSymbolicId(OTInt32 value);
		virtual EnumStatusCode setSymbolicId(const tstring& symbolicId, ObjectPointer<StringTable> stringTable);

		virtual OTInt32 getLocale() const;
		virtual EnumStatusCode getLocale(ObjectPointer<const StringTable> stringTable, tstring& locale) const;
		virtual void setLocale(OTInt32 value);
		virtual EnumStatusCode setLocale(const tstring& locale, ObjectPointer<StringTable> stringTable);

		virtual OTInt32 getLocalizedText() const;
		virtual EnumStatusCode getLocalizedText(ObjectPointer<const StringTable> stringTable, tstring& localizedText) const;
		virtual void setLocalizedText(OTInt32 value);
		virtual EnumStatusCode setLocalizedText(const tstring& localizedText, ObjectPointer<StringTable> stringTable);

		virtual tstring getAdditionalInfo() const;
		virtual EnumStatusCode setAdditionalInfo(const tstring& additionalInfo);

		virtual EnumStatusCode getInnerStatusCode() const;
		virtual void setInnerStatusCode(EnumStatusCode innerStatusCode);

		virtual const IDiagnosticInfo* getInnerDiagnosticInfo() const;
		virtual EnumStatusCode setInnerDiagnosticInfo(const IDiagnosticInfo* pInnerDiagnosticInfo);

		virtual tstring toString(ObjectPointer<const StringTable> stringTable) const;

		/*! For internal use only */
		void initInner(DiagnosticInfoStruct* pHandle);

		/*! @see IDiagnosticInfo::set(const IDiagnosticInfo*) */
		EnumStatusCode set(const IDiagnosticInfo* pSrc);
		/*! @see IDiagnosticInfo::set(const IDiagnosticInfo&) */
		EnumStatusCode set(const IDiagnosticInfo& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDiagnosticInfo* other) const;
		/*! @overload */
		virtual int compare(const IDiagnosticInfo& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDiagnosticInfo& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDiagnosticInfo& other) const;

		/*! @see IDiagnosticInfo::getInternHandle() */
		virtual void* getInternHandle() const;

	private:
		InnerDiagnosticInfo* m_pInnerDiagnosticInfo;
		DiagnosticInfoStruct* m_pContent;
	};
} // end namespace

#endif	// INNERDIAGNOSTICINFO_H
