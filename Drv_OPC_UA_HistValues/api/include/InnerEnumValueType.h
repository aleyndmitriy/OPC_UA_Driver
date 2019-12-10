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

#ifndef INNERENUMVALUETYPE_H
#define INNERENUMVALUETYPE_H

#include "IEnumValueType.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerEnumValueType
		: public IEnumValueType
	{
	public:
		/*! Destructor */
		virtual ~InnerEnumValueType();

		/* see IEnumValueType::getValue */
		virtual OTInt64 getValue() const;
		/* see IEnumValueType::setValue */
		virtual void setValue(const OTInt64& value);

		/* see IEnumValueType::getDisplayName */
		virtual const ILocalizedText* getDisplayName() const;
		/* see IEnumValueType::setDisplayName */
		virtual EnumStatusCode setDisplayName(const ILocalizedText* value);
		/*! @overload */
		virtual EnumStatusCode setDisplayName(const LocalizedText& value);

		/* see IEnumValueType::getDescription */
		virtual const ILocalizedText* getDescription() const;
		/* see IEnumValueType::setDescription */
		virtual EnumStatusCode setDescription(const ILocalizedText* value);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& value);

		/*! For internal use only */
		void initInner(EnumValueTypeStruct* pHandle);

		virtual EnumStatusCode set(const IEnumValueType* pSrc);
		virtual EnumStatusCode set(const IEnumValueType& pSrc);

		virtual int compare(const IEnumValueType* other) const;
		virtual int compare(const IEnumValueType& other) const;

		virtual bool operator==(const IEnumValueType& other) const;
		virtual bool operator!=(const IEnumValueType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerLocalizedText m_displayName;
		InnerLocalizedText m_description;

		EnumValueTypeStruct* m_pContent;
	};
} // end namespace

#endif	// INNERENUMVALUETYPE_H
