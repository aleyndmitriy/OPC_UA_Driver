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

#ifndef ENUMVALUETYPE_H
#define ENUMVALUETYPE_H

#include "IEnumValueType.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EnumValueType data type is used to store a human-readable representation of an
	* enumeration in an address space. */
	class TBC_EXPORT EnumValueType
		: public IEnumValueType
	{
	public:
		/*! Default constructor */
		EnumValueType();
		/*! Constructs a copy of the given instance @p cp */
		EnumValueType(const IEnumValueType* cp);
		/*! @overload */
		EnumValueType(const IEnumValueType& cp);
		/*! @overload */
		EnumValueType(const EnumValueType& cp);

		/*! Destructor */
		virtual ~EnumValueType();

		/*! Assigns the contents of @p cp to this instance */
		EnumValueType& operator=(const IEnumValueType* cp);
		/*! @overload */
		EnumValueType& operator=(const IEnumValueType& cp);
		/*! @overload */
		EnumValueType& operator=(const EnumValueType& cp);

		/*! @see IEnumValueType::compare(IEnumValueType*) */
		virtual int compare(const IEnumValueType* other) const;
		/*! @overload */
		virtual int compare(const IEnumValueType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEnumValueType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEnumValueType& other) const;

		/*! @see IEnumValueType::set(IEnumValueType*) */
		virtual EnumStatusCode set(const IEnumValueType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEnumValueType& pSrc);

		/* see IEnumValueType::getValue */
		virtual OTInt64 getValue() const;
		/* see IEnumValueType::setValue */
		virtual void setValue(const OTInt64& value);

		/* see IEnumValueType::getDisplayName */
		virtual const ILocalizedText* getDisplayName() const;
		/* see IEnumValueType::setDisplayName */
		virtual EnumStatusCode setDisplayName(const ILocalizedText* displayName);
		/*! @overload */
		virtual EnumStatusCode setDisplayName(const LocalizedText& displayName);

		/* see IEnumValueType::getDescription */
		virtual const ILocalizedText* getDescription() const;
		/* see IEnumValueType::setDescription */
		virtual EnumStatusCode setDescription(const ILocalizedText* description);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerLocalizedText m_displayName;
		InnerLocalizedText m_description;

		EnumValueTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ENUMVALUETYPE_H
