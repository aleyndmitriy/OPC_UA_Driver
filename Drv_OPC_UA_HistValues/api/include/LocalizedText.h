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

#ifndef LOCALIZEDTEXT_H
#define LOCALIZEDTEXT_H

#include "ILocalizedText.h"


#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The LocalizedText data type contains a string in a locale-specific translation specified
	* in the identifier for the locale. The preferred locale that a client wishes to receive from
	* a server can be specified by Client::Session::setPreferredLocales().
	*
	* Please note that for server applications the LocalizedText data type is not limited to one
	* localized string. The method defineTranslation() can be used to define additional translations
	* for a text which can be returned to clients. */
	class TBC_EXPORT LocalizedText
		: public ILocalizedText
	{
	public:
		/*! Default constructor */
		LocalizedText();
		/*! Constructs a copy of the given instance */
		LocalizedText(const tstring& text, const tstring& locale);
		/*! @overload */
		LocalizedText(const ILocalizedText*);
		/*! @overload */
		LocalizedText(const ILocalizedText&);
		/*! @overload */
		LocalizedText(const LocalizedText&);

		/*! Destructor */
		virtual ~LocalizedText();

		/*! Assigns the contents of @p cp to this instance */
		LocalizedText& operator=(const ILocalizedText* cp);
		/*! @overload */
		LocalizedText& operator=(const ILocalizedText& cp);
		/*! @overload */
		LocalizedText& operator=(const LocalizedText& cp);

		/* see ILocalizedText::set */
		virtual EnumStatusCode set(const ILocalizedText* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ILocalizedText& pSrc);

		/* see ILocalizedText::compare */
		virtual int compare(const ILocalizedText*) const;
		/*! @overload */
		virtual int compare(const ILocalizedText&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILocalizedText& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILocalizedText& other) const;

		/* see ILocalizedText::getLocale */
		virtual tstring getLocale() const;
		/* see ILocalizedText::setLocale */
		virtual void setLocale(const tstring& value);

		/* see ILocalizedText::getText */
		virtual tstring getText() const;
		/* see ILocalizedText::setText */
		virtual void setText(const tstring& value);

		/* see ILocalizedText::defineTranslation */
		virtual EnumStatusCode defineTranslation(const tstring& text, const tstring& locale);

		/* see ILocalizedText::getTranslation */
		virtual EnumStatusCode getTranslation(const std::vector<tstring>& preferredLocales, tstring& text, tstring& locale) const;

		/* see ILocalizedText::getAllTranslations */
		virtual EnumStatusCode getAllTranslations(std::vector<tstring>& texts, std::vector<tstring>& locales) const;

		/* see ILocalizedText::removeTranslation */
		virtual EnumStatusCode removeTranslation(const tstring& locale);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		LocalizedTextStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// LOCALIZEDTEXT_H
