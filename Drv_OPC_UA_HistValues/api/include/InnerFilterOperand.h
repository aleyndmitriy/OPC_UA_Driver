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

#ifndef INNERFILTEROPERAND_H
#define INNERFILTEROPERAND_H

#include "IFilterOperand.h"
#include "InnerLiteralOperand.h"
#include "LiteralOperand.h"
#include "InnerElementOperand.h"
#include "ElementOperand.h"
#include "InnerAttributeOperand.h"
#include "AttributeOperand.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"
#if TB5_FILTER

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerFilterOperand
	class TBC_EXPORT InnerFilterOperand
		: public IFilterOperand
	{
	public:
		/*! Destructor */
		virtual ~InnerFilterOperand();

		/*! Returns the actual type of the filter operand. */
		virtual EnumFilterOperand getType() const;

		/* see IFilterOperand::getLiteralOperand */
		virtual EnumStatusCode getLiteralOperand(LiteralOperand& operand) const;
		/* see IFilterOperand::setLiteralOperand */
		virtual EnumStatusCode setLiteralOperand(const ILiteralOperand* operand);
		/* see IFilterOperand::setLiteralOperand */
		virtual EnumStatusCode setLiteralOperand(const LiteralOperand& operand);

		/* see IFilterOperand::getElementOperand */
		virtual EnumStatusCode getElementOperand(ElementOperand& operand) const;
		/* see IFilterOperand::setElementOperand */
		virtual EnumStatusCode setElementOperand(const IElementOperand* operand);
		/* see IFilterOperand::setElementOperand */
		virtual EnumStatusCode setElementOperand(const ElementOperand& operand);

		/* see IFilterOperand::getAttributeOperand */
		virtual EnumStatusCode getAttributeOperand(AttributeOperand& operand) const;
		/* see IFilterOperand::setAttributeOperand */
		virtual EnumStatusCode setAttributeOperand(const IAttributeOperand* operand);
		/* see IFilterOperand::setAttributeOperand */
		virtual EnumStatusCode setAttributeOperand(const AttributeOperand& operand);

		/* see IFilterOperand::getSimpleAttributeOperand */
		virtual EnumStatusCode getSimpleAttributeOperand(SimpleAttributeOperand& operand) const;
		/* see IFilterOperand::setSimpleAttributeOperand */
		virtual EnumStatusCode setSimpleAttributeOperand(const ISimpleAttributeOperand* operand);
		/* see IFilterOperand::setSimpleAttributeOperand */
		virtual EnumStatusCode setSimpleAttributeOperand(const SimpleAttributeOperand& operand);


		// init from otb handle
		void initInner(FilterOperandStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IFilterOperand* other) const;
		/*! @overload */
		virtual int compare(const IFilterOperand& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFilterOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFilterOperand& other) const;

		// set from interface
		EnumStatusCode set(const IFilterOperand* pSrc);
		EnumStatusCode set(const IFilterOperand& pSrc);

		// protected:
		// the handle to the related core object
		FilterOperandStruct* m_pFilterOperand_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif
#endif	// INNERFILTEROPERAND_H
