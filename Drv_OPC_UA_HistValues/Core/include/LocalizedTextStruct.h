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

#ifndef __LOCALIZEDTEXTSTRUCT_H_
#define __LOCALIZEDTEXTSTRUCT_H_

#include <vector>

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*!
 * @brief This type is used as an index into the application's table of localizable texts
 */
typedef OTUInt64 OTTextId;

/*!
 * @brief A special OTTextId which is initially assigned to every LocalizedText
 */
static const OTTextId OT_TEXTID_INVALID = 0;

/*!
 * @brief The first generated OTTextId
 */
static const OTTextId OT_TEXTID_FIRST_GENERATED_ID = 1;

/*!
 * @brief The default invariant locale used for translations
 */
static const OTChar OT_DEFAULT_LOCALE[] = _T("");

/*! Structure for localized text representations. E.g. a DisplayName of a node is localized and the display
* of such a text shall consider the localization. */
//lint -sem(LocalizedTextStruct::clear, cleanup)
//lint -sem(LocalizedTextStruct::init, initializer)
typedef struct TBCORE_IF LocalizedTextStruct
{
	/*!
	 * An identifier that refers to a set of <Locale, Text> entries for this LocalizedText
	 *
	 * @warning Do not set this member directly. Use @ref setTextId_API() instead.
	 *
	 * @see OTLocalizedTextManager
	 */
	OTTextId textId;

	/*!
	 * This member denotes whether the LocalizedText was provided by an OPC UA client.
	 *
	 * In this case, the locale and text is interpreted according to the OPC UA specification,
	 * i.e. a non-empty locale and empty text removes a translation, an empty locale and text
	 * removes all translations.
	 */
	bool providedByClient;

	/*!
	 * Holds whether this LocalizedText is a member variable of a node class
	 */
	bool isMemberOfNode;

	/*!
	 * @brief Constructs a localized text with an empty translation for the invariant locale ("")
	 */
	LocalizedTextStruct();

	/*!
	 * @brief Constructs a localized text with an invariant locale and the provided translation
	 */
	LocalizedTextStruct(const tstring& translation);
	LocalizedTextStruct(const OTChar* translation);

	/*!
	 * @brief Constructs a localized text with a @p translation for the given @p locale
	 */
	LocalizedTextStruct(const tstring& translation, const tstring& locale, OTUInt32 reserved = 0);

	/*!
	 * @brief Copy Constructor
	 */
	LocalizedTextStruct(const LocalizedTextStruct& cp);

	/*!
	 * @brief Defines a translation for this LocalizedText
	 *
	 * @param translation the translation
	 * @param locale the RFC 3066 identifier for the language
	 *
	 * @return EnumStatusCode_Good, if the operation was successful.
	 *         EnumStatusCode_BadInternalError, if an error occurred.
	 */
	EnumStatusCode defineTranslation_API(const tstring& translation, const tstring& locale, OTUInt32 reserved = 0);

	/*!
	 * @brief Removes the translation for the given @p locale
	 *
	 * @param locale the locale for which to remove the translation
	 *
	 * @return EnumStatusCode_Good, if the translation is removed or did not exist.
	 *         EnumStatusCode_BadInternalError, if an error occurred while removing the translation.
	 */
	EnumStatusCode removeTranslation_API(const tstring& locale);

	/*!
	 * @see OTLocalizedTextManager::getTranslation()
	 */
	EnumStatusCode getTranslation_API(unsigned preferredLocalesCount, const OTChar** pPreferredLocales, tstring& translation, tstring& locale) const;

	/*!
	 * @see OTLocalizedTextManager::getTranslation()
	 */
	EnumStatusCode getTranslation(const std::vector<tstring>& preferredLocales, tstring& translation, tstring& locale) const;

	/*!
	 * @see OTLocalizedTextManager::getTranslation()
	 *
	 * Retrieves a translation for the LocalizedText using default locales.
	 */
	EnumStatusCode getTranslation(tstring& translation, tstring& locale) const;

	EnumStatusCode getAllTranslations_API(std::vector<tstring>& allTexts, std::vector<tstring>& allLocales) const;

	EnumStatusCode getAllTranslations(std::vector<tstring>& allTexts, std::vector<tstring>& allLocales) const;

	/*!
	 * @brief Sets the OTTextId for this localized text
	 *
	 * @param textId the textId to assign
	 */
	EnumStatusCode setTextId_API(const OTTextId& textId);


	EnumStatusCode set(const LocalizedTextStruct& cp, bool targetIsMemberOfNode = false);
	EnumStatusCode get(LocalizedTextStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_LocalizedText&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_LocalizedText& targetLocalizedText, const std::vector<tstring>& preferredLocales) const;
#endif
	tstring toString() const;

	const LocalizedTextStruct& operator=(const LocalizedTextStruct& cp);
	bool operator==(const LocalizedTextStruct& toCompare) const;
	bool operator!=(const LocalizedTextStruct& toCompare) const;
	bool operator<(const LocalizedTextStruct& toCompare) const;
	bool operator>(const LocalizedTextStruct& toCompare) const;

	int compare(const LocalizedTextStruct* pTarget) const;

	void clear(void);
	~LocalizedTextStruct(void);
}LocalizedTextStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
