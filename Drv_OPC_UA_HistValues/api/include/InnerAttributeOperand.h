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

#ifndef INNERATTRIBUTEOPERAND_H
#define INNERATTRIBUTEOPERAND_H
#if TB5_FILTER

#include "IAttributeOperand.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerRelativePath.h"
#include "RelativePath.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerAttributeOperand
	class TBC_EXPORT InnerAttributeOperand
		: public IAttributeOperand
	{
	public:
		/*! Destructor */
		virtual ~InnerAttributeOperand();

		/*! Id of a node from the type system. */
		virtual const INodeId* getNodeId() const;
		virtual INodeId* getNodeId();
		virtual void setNodeId(const INodeId* value);
		virtual void setNodeId(const NodeId& value);

		/*! An optional parameter used to identify or refer to an alias. An alias is a symbolic
		* name that can be used to alias this operand and use it in other location in the
		* filter structure. */
		virtual tstring getAlias() const;
		virtual void setAlias(const tstring& value);

		/*! Browse path relative to the Node identified by the nodeId parameter. See 7.25
		* for the definition of RelativePath. */
		virtual const IRelativePath* getBrowsePath() const;
		virtual IRelativePath* getBrowsePath();
		virtual void setBrowsePath(const IRelativePath* value);
		virtual void setBrowsePath(const RelativePath& value);

		/*! Id of the Attribute */
		virtual EnumAttributeId getAttributeId() const;
		virtual void setAttributeId(EnumAttributeId value);

		/*! This parameter is used to identify a single element of an array or a single range
		* of indexes for an array.
		* This parameter is not used if the specified Attribute is not an array. However, if
		* the specified Attribute is an array and this parameter is not used, then all
		* elements are to be included in the range. The parameter is null if not used. */
		virtual const INumericRange* getIndexRange() const;
		virtual void setIndexRange(const INumericRange* value);
		virtual void setIndexRange(const NumericRange& value);


		// init from otb handle
		void initInner(AttributeOperandStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAttributeOperand* other) const;
		/*! @overload */
		virtual int compare(const IAttributeOperand& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAttributeOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAttributeOperand& other) const;

		// set from interface
		EnumStatusCode set(const IAttributeOperand* pSrc);
		EnumStatusCode set(const IAttributeOperand& pSrc);

		// protected:
		// the handle to the related core object
		AttributeOperandStruct* m_pAttributeOperand_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerNodeId m_NodeId;
		InnerRelativePath m_BrowsePath;
		InnerNumericRange m_IndexRange;
	};
}
#endif
#endif	// INNERATTRIBUTEOPERAND_H
