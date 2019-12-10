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

#ifndef INNERRELATIVEPATHELEMENT_H
#define INNERRELATIVEPATHELEMENT_H

#include "IRelativePathElement.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerRelativePathElement
	class TBC_EXPORT InnerRelativePathElement
		: public IRelativePathElement
	{
	public:
		/*! Destructor */
		virtual ~InnerRelativePathElement();

		/*! The type of reference to follow from the current node.
		* The current path can not be followed any further if the referenceTypeId is not
		* available on the Node instance. */
		virtual const INodeId* getReferenceTypeId() const;
		virtual INodeId* getReferenceTypeId();
		virtual void setReferenceTypeId(const INodeId* value);
		virtual void setReferenceTypeId(const NodeId& value);

		/*! Indicates whether the inverse Reference should be followed. The inverse
		* reference is followed if this value is TRUE. */
		virtual bool getIsInverse() const;
		virtual void setIsInverse(bool value);

		/*! Indicates whether subtypes of the ReferenceType should be followed. Subtypes are included if this value
		* is TRUE. */
		virtual bool getIncludeSubtypes() const;
		virtual void setIncludeSubtypes(bool value);

		/*! The BrowseName of the target node.
		* The final element may have an empty targetName. In this situation all targets of
		* the references identified by the referenceTypeId are the targets of the RelativePath.
		* The targetName shall be specified for all other elements.
		* The current path can not be followed any further if no targets with the specified BrowseName exist. */
		virtual const IQualifiedName* getTargetName() const;
		virtual IQualifiedName* getTargetName();
		virtual void setTargetName(const IQualifiedName* value);
		virtual void setTargetName(const QualifiedName& value);


		// init from otb handle
		void initInner(RelativePathElementStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IRelativePathElement* other) const;
		/*! @overload */
		virtual int compare(const IRelativePathElement& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRelativePathElement& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRelativePathElement& other) const;

		// set from interface
		EnumStatusCode set(const IRelativePathElement* pSrc);
		EnumStatusCode set(const IRelativePathElement& pSrc);

		// protected:
		// the handle to the related core object
		RelativePathElementStruct* m_pRelativePathElement_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerNodeId m_ReferenceTypeId;
		InnerQualifiedName m_TargetName;
	};
}
#endif	// INNERRELATIVEPATHELEMENT_H
