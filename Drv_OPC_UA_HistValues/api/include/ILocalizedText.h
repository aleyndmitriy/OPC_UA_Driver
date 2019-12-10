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

#ifndef ILOCALIZEDTEXT_H
#define ILOCALIZEDTEXT_H

#include "LocalizedTextStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The LocalizedText data type contains a string in a locale-specific translation specified
	* in the identifier for the locale. The preferred locale that a client wishes to receive from
	* a server can be specified by Client::Session::setPreferredLocales().
	*
	* Please note that for server applications the LocalizedText data type is not limited to one
	* localized string. The method defineTranslation() can be used to define additional translations
	* for a text which can be returned to clients. */
	class TBC_EXPORT ILocalizedText
	{
	public:
		/*! Destructor */
		virtual ~ILocalizedText(){};

		/*! Returns the identifier for the locale that conforms to RFC 3066. */
		virtual tstring getLocale() const = 0;
		/*! Sets the identifier for the locale that conforms to RFC 3066. The locale defines
		* the language of the text. For example, the locale "en-US" would denote an American
		* English locale, "de" would denote a German locale. */
		virtual void setLocale(const tstring& value) = 0;

		/*! Returns the localized text. The language of the text is defined by getLocale(). */
		virtual tstring getText() const = 0;
		/*! Sets the localized text. The language of the text is defined by getLocale(). */
		virtual void setText(const tstring& value) = 0;

		/*! Defines or re-defines a translation of a text.
		*
		* This method is only useful for server applications. Clients always receive exactly one translation from a server.
		* The Client::Session::setPreferredLocales() method can be used by clients to specify their preferred language.
		*
		* @param text The translated text
		* @param locale The RFC 3066 identifier for the language */
		virtual EnumStatusCode defineTranslation(const tstring& text, const tstring& locale) = 0;

		/*! Returns a translated text for the best matching locale among the list of provided locales.
		*
		* This method is only useful for server applications. Clients always receive exactly one translation from a server.
		* The Client::Session::setPreferredLocales() method can be used by clients to specify their preferred language.

		* @param preferredLocales	A list of preferred locales for the translation. The list must be sorted by priority.
		* @param[out] text			The translated text
		* @param[out] locale		The locale of the translated text */
		virtual EnumStatusCode getTranslation(const std::vector<tstring>& preferredLocales, tstring& text, tstring& locale) const = 0;

		/*! Returns all translations for this LocalizedText.
		*
		* This method is only useful for server applications. Clients always receive exactly one translation from a server.
		* The Client::Session::setPreferredLocales() method can be used by clients to specify their preferred language.

		* @param[out] texts			The translations for each locale
		* @param[out] locales		The locales of the translations */
		virtual EnumStatusCode getAllTranslations(std::vector<tstring>& texts, std::vector<tstring>& locales) const =  0;

		/*! Removes the translation for the given @p locale.
		*
		* This method is only useful for server applications. Clients always receive exactly one translation from a server.
		* The Client::Session::setPreferredLocales() method can be used by clients to specify their preferred language.
		*
		* @param locale		The locale for which to remove the translation */
		virtual EnumStatusCode removeTranslation(const tstring& locale) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ILocalizedText* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ILocalizedText& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ILocalizedText* other) const = 0;
		/*! @overload */
		virtual int compare(const ILocalizedText& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILocalizedText& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILocalizedText& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ILocalizedText
} // end namespace
#endif	// ILOCALIZEDTEXT_H
