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

#ifndef ILITERALOPERAND_H
#define ILITERALOPERAND_H
#if TB5_FILTER

#include "LiteralOperandStruct.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The LiteralOperand data type is used as operand in event and query filters to
	* specify a literal value such as an integer or a NodeId.
	*
	* @see IContentFilter */
	class TBC_EXPORT ILiteralOperand
	{
	public:
		/*! Destructor */
		virtual ~ILiteralOperand(){};

		/*! Returns the literal value. */
		virtual const IValue* getValue() const = 0;
		/*! @overload */
		virtual IValue* getValue() = 0;
		/*! Sets the literal value. */
		virtual void setValue(const IValue* value) = 0;
		/*! @overload */
		virtual void setValue(const Value& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ILiteralOperand* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ILiteralOperand& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ILiteralOperand* other) const = 0;
		/*! @overload */
		virtual int compare(const ILiteralOperand& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILiteralOperand& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILiteralOperand& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ILiteralOperand
} // end namespace
#endif
#endif	// ILITERALOPERAND_H
