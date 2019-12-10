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

#ifndef LITERALOPERAND_H
#define LITERALOPERAND_H
#if TB5_FILTER

#include "ILiteralOperand.h"
#include "InnerValue.h"
#include "Value.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The LiteralOperand data type is used as operand in event and query filters to
	* specify a literal value (such as an integer or a NodeId).
	*
	* @see IContentFilter */
	class TBC_EXPORT LiteralOperand
		: public ILiteralOperand
	{
	public:
		/*! Default constructor */
		LiteralOperand();
		/*! Constructs a copy of the given instance */
		LiteralOperand(const ILiteralOperand*);
		/*! @overload */
		LiteralOperand(const ILiteralOperand&);
		/*! @overload */
		LiteralOperand(const LiteralOperand&);
		/*! @overload */
		LiteralOperand(const IValue* value);
		/*! @overload */
		LiteralOperand(const Value& value);


		/*! Destructor */
		virtual ~LiteralOperand();

		/*! Assigns the contents of @p cp to this instance */
		LiteralOperand& operator=(const ILiteralOperand* cp);
		/*! @overload */
		LiteralOperand& operator=(const ILiteralOperand& cp);
		/*! @overload */
		LiteralOperand& operator=(const LiteralOperand& cp);

		/* see ILiteralOperand::set */
		virtual EnumStatusCode set(const ILiteralOperand* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ILiteralOperand& pSrc);

		/* see ILiteralOperand::compare */
		virtual int compare(const ILiteralOperand*) const;
		/*! @overload */
		virtual int compare(const ILiteralOperand&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILiteralOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILiteralOperand& other) const;

		/* see ILiteralOperand::getValue */
		virtual const IValue* getValue() const;
		/*! @overload */
		virtual IValue* getValue();
		/* see ILiteralOperand::setValue */
		virtual void setValue(const IValue* value);
		/*! @overload */
		virtual void setValue(const Value& value);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void initMembers();

		InnerValue m_Value;

		LiteralOperandStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// LITERALOPERAND_H
