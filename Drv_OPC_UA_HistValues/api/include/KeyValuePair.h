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

#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H

#include "IKeyValuePair.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"
#include "Value.h"
#include "InnerValue.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The KeyValuePair data type represents a value for a specific key.
	*
	* With this data type a collection of values for specific keys can be stored. */
	class TBC_EXPORT KeyValuePair
		: public IKeyValuePair
	{
	public:
		/*! Default constructor */
		KeyValuePair();
		/*! Constructs a copy of the given instance @p cp */
		KeyValuePair(const IKeyValuePair* cp);
		/*! @overload */
		KeyValuePair(const IKeyValuePair& cp);
		/*! @overload */
		KeyValuePair(const KeyValuePair& cp);
		/*! @overload */
		KeyValuePair(const IQualifiedName& key, const IValue& value);

		/*! Destructor */
		virtual ~KeyValuePair();

		/*! Assigns the contents of @p cp to this instance */
		KeyValuePair& operator=(const IKeyValuePair* cp);
		/*! @overload */
		KeyValuePair& operator=(const IKeyValuePair& cp);
		/*! @overload */
		KeyValuePair& operator=(const KeyValuePair& cp);

		/* see IKeyValuePair::compare(IKeyValuePair*) */
		virtual int compare(const IKeyValuePair* other) const;
		/*! @overload */
		virtual int compare(const IKeyValuePair& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IKeyValuePair& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IKeyValuePair& other) const;

		/* see IKeyValuePair::set(IKeyValuePair*) */
		virtual EnumStatusCode set(const IKeyValuePair* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IKeyValuePair& pSrc);

		/* see IKeyValuePair::setKey */
		virtual EnumStatusCode setKey(const IQualifiedName* key);
		/*! @overload */
		virtual EnumStatusCode setKey(const QualifiedName& key);
		/* see IKeyValuePair::getKey */
		virtual const IQualifiedName* getKey() const;

		/* see IKeyValuePair::setValue */
		virtual EnumStatusCode setValue(const IValue* value);
		/*! @overload */
		virtual EnumStatusCode setValue(const Value& value);
		/* see IKeyValuePair::getValue */
		virtual const IValue* getValue() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerQualifiedName m_key;
		InnerValue m_value;

		KeyValuePairStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
