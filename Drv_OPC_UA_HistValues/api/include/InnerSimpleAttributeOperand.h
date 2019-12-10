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

#ifndef INNERSIMPLEATTRIBUTEOPERAND_H
#define INNERSIMPLEATTRIBUTEOPERAND_H

#include "ISimpleAttributeOperand.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerSimpleAttributeOperand
	class TBC_EXPORT InnerSimpleAttributeOperand
		: public ISimpleAttributeOperand
	{
	public:
		/*! Destructor */
		virtual ~InnerSimpleAttributeOperand();

		/*! NodeId of a TypeDefinitionNode.
		* This parameter restricts the operand to instances of the TypeDefinitionNode or one of its subtypes. */
		virtual const INodeId* getTypeDefinitionId() const;
		virtual INodeId* getTypeDefinitionId();
		virtual void setTypeDefinitionId(const INodeId* value);
		virtual void setTypeDefinitionId(const NodeId& value);

		/*! A relative path to a Node.
		* This parameter specifies a relative path using a list of BrowseNames instead of the RelativePath structure
		* used in the AttributeOperand.
		* The list of BrowseNames is equivalent to a RelativePath that specifies forward references which are subtypes
		* of the HierarchicalReferences ReferenceType.
		* If this list is empty the Node is the instance of the TypeDefinition. */
		virtual OTUInt32 getBrowsePathCount() const;
		virtual const IQualifiedName* getBrowsePath(OTUInt32 index) const;
		virtual std::vector<QualifiedName> getBrowsePath() const;
		virtual EnumStatusCode addBrowsePath(const IQualifiedName* pValue);
		/*! @overload */
		virtual EnumStatusCode addBrowsePath(const QualifiedName& value);

		/*! Id of the Attribute. */
		virtual EnumAttributeId getAttributeId() const;
		virtual void setAttributeId(EnumAttributeId value);

		/*! This parameter is used to identify a single element of an array, or a single range of indexes for an array.
		* The first element is identified by index 0 (zero).
		* This parameter is ignored if the selected Node is not a Variable or the Value of a Variable is not an
		* array.
		* The parameter is null if not specifed.
		* All values in the array are used if this parameter is not specified. */
		virtual const INumericRange* getIndexRange() const;
		virtual void setIndexRange(const INumericRange* value);
		virtual void setIndexRange(const NumericRange& value);


		// init from otb handle
		void initInner(SimpleAttributeOperandStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISimpleAttributeOperand* other) const;
		/*! @overload */
		virtual int compare(const ISimpleAttributeOperand& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISimpleAttributeOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISimpleAttributeOperand& other) const;

		// set from interface
		EnumStatusCode set(const ISimpleAttributeOperand* pSrc);
		EnumStatusCode set(const ISimpleAttributeOperand& pSrc);

		// protected:
		// the handle to the related core object
		SimpleAttributeOperandStruct* m_pSimpleAttributeOperand_Data;

	private:
		/*! For internal use only */
		virtual void* getInternHandle() const;

		InnerNodeId m_TypeDefinitionId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerQualifiedName> m_BrowsePath)
		InnerNumericRange m_IndexRange;
	};
}
#endif	// INNERSIMPLEATTRIBUTEOPERAND_H
