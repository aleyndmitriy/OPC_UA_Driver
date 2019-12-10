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

#ifndef INNERKEYVALUEPAIR_H
#define INNERKEYVALUEPAIR_H

#include "IKeyValuePair.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerKeyValuePair
		: public IKeyValuePair
	{
	public:
		/*! Destructor */
		virtual ~InnerKeyValuePair();

		/* see IKeyValuePair::getKey */
		virtual const IQualifiedName* getKey() const;
		/* see IKeyValuePair::setKey */
		virtual EnumStatusCode setKey(const IQualifiedName* value);
		/*! @overload */
		virtual EnumStatusCode setKey(const QualifiedName& value);

		/* see IKeyValuePair::getValue */
		virtual const IValue* getValue() const;
		/* see IKeyValuePair::setValue */
		virtual EnumStatusCode setValue(const IValue* value);
		/*! @overload */
		virtual EnumStatusCode setValue(const Value& value);

		/*! For internal use only */
		void initInner(KeyValuePairStruct* pHandle);

		virtual EnumStatusCode set(const IKeyValuePair* pSrc);
		virtual EnumStatusCode set(const IKeyValuePair& pSrc);

		virtual int compare(const IKeyValuePair* other) const;
		virtual int compare(const IKeyValuePair& other) const;

		virtual bool operator==(const IKeyValuePair& other) const;
		virtual bool operator!=(const IKeyValuePair& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerQualifiedName m_key;
		InnerValue m_value;

		KeyValuePairStruct* m_pContent;
	};
} // end namespace

#endif
