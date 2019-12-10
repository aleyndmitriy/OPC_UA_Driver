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

#ifndef INNERLITERALOPERAND_H
#define INNERLITERALOPERAND_H
#if TB5_FILTER

#include "ILiteralOperand.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerLiteralOperand
	class TBC_EXPORT InnerLiteralOperand
		: public ILiteralOperand
	{
	public:
		/*! Destructor */
		virtual ~InnerLiteralOperand();

		virtual const IValue* getValue() const;
		virtual IValue* getValue();
		virtual void setValue(const IValue* value);
		virtual void setValue(const Value& value);


		// init from otb handle
		void initInner(LiteralOperandStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ILiteralOperand* other) const;
		/*! @overload */
		virtual int compare(const ILiteralOperand& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ILiteralOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ILiteralOperand& other) const;

		// set from interface
		EnumStatusCode set(const ILiteralOperand* pSrc);
		EnumStatusCode set(const ILiteralOperand& pSrc);

		// protected:
		// the handle to the related core object
		LiteralOperandStruct* m_pLiteralOperand_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerValue m_Value;
	};
}
#endif
#endif	// INNERLITERALOPERAND_H
