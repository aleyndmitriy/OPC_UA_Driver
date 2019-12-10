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

#ifndef INNERLOCALIZEDTEXT_H
#define INNERLOCALIZEDTEXT_H

#include "ILocalizedText.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerLocalizedText
	class TBC_EXPORT InnerLocalizedText
		: public ILocalizedText
	{
	public:
		/*! Constructor */
		/*! Destructor */
		virtual ~InnerLocalizedText();

		/*! A string identifier identifying the localization. E.g. "de" is a German localization, "us" American etc. */
		virtual tstring getLocale() const;
		virtual void setLocale(const tstring& value);

		/*! The text content. */
		virtual tstring getText() const;
		virtual void setText(const tstring& value);

		// init from otb handle
		void initInner(LocalizedTextStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ILocalizedText* other) const;
		/*! @overload */
		virtual int compare(const ILocalizedText& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILocalizedText& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILocalizedText& other) const;

		// set from interface
		EnumStatusCode set(const ILocalizedText* pSrc);
		EnumStatusCode set(const ILocalizedText& pSrc);

		/*! Defines a translation for this LocalizedText
		*
		* @param text The translation
		* @param locale The RFC 3066 identifier for the language
		*
		* @return EnumStatusCode_Good, if the operation was successful.
		*         EnumStatusCode_BadInternalError, if an error occurred. */
		virtual EnumStatusCode defineTranslation(const tstring& text, const tstring& locale);

		/*! Returns a translation of the localized text for the best matching locale of the provided locales
		*
		* @param preferredLocales A list of preferred locales for the translation. The list must be sorted by priority.
		* @param[out] text The translated text
		* @param[out] locale The locale of the translated text
		*
		* @return EnumStatusCode_Good, if a translation is returned */
		virtual EnumStatusCode getTranslation(const std::vector<tstring>& preferredLocales, tstring& text, tstring& locale) const;

		/*! Removes the translation for the given @p locale
		*
		* @param locale The locale for which to remove the translation
		*
		* @return EnumStatusCode_Good, if the translation is removed or did not exist.
		*         EnumStatusCode_BadInternalError, if an error occurred while removing the translation. */
		virtual EnumStatusCode removeTranslation(const tstring& locale);

		/* see ILocalizedText::getAllTranslations */
		virtual EnumStatusCode getAllTranslations(std::vector<tstring>& texts, std::vector<tstring>& locales) const;

		/*! For internal use only */
		virtual void* getInternHandle() const;

private:
		// the handle to the related core object
		LocalizedTextStruct* m_pLocalizedText_Data;
	};
}
#endif	// INNERLOCALIZEDTEXT_H
