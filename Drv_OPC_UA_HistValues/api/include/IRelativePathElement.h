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

#ifndef IRELATIVEPATHELEMENT_H
#define IRELATIVEPATHELEMENT_H

#include "RelativePathElementStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! The RelativePathElement data type defines a single element of a RelativePath. */
	class TBC_EXPORT IRelativePathElement
	{
	public:
		/*! Destructor */
		virtual ~IRelativePathElement(){};

		/*! Returns the type of reference to follow from the current node.
		*
		* @see setReferenceTypeId() */
		virtual const INodeId* getReferenceTypeId() const = 0;
		/*! @overload */
		virtual INodeId* getReferenceTypeId() = 0;
		/*! Sets the type of reference to follow from the current node.
		*
		* The current path can not be followed any further if the ReferenceTypeId is not
		* available on the node instance. */
		virtual void setReferenceTypeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value) = 0;

		/*! Returns whether the inverse reference should be followed. */
		virtual bool getIsInverse() const = 0;
		/*! Sets whether the inverse reference should be followed. The inverse
		* reference is followed if this value is TRUE. */
		virtual void setIsInverse(bool value) = 0;

		/*! Returns whether subtypes of the reference type should be followed. */
		virtual bool getIncludeSubtypes() const = 0;
		/*! Sets whether subtypes of the reference type should be followed.
		* Subtypes are included if this value is TRUE. */
		virtual void setIncludeSubtypes(bool value) = 0;

		/*! Returns the browse name of the target node.
		*
		* @see setTargetName() */
		virtual const IQualifiedName* getTargetName() const = 0;
		/*! @overload */
		virtual IQualifiedName* getTargetName() = 0;
		/*! Sets the browse name of the target node.
		*
		* The final element may have an empty target name. In this situation all
		* targets of the references identified by the ReferenceTypeId are the targets
		* of the RelativePath. The target name shall be specified for all other elements.
		* The current path can not be followed any further if no targets with the specified
		* browse name exist. */
		virtual void setTargetName(const IQualifiedName* value) = 0;
		/*! @overload */
		virtual void setTargetName(const QualifiedName& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IRelativePathElement* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IRelativePathElement& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IRelativePathElement* other) const = 0;
		/*! @overload */
		virtual int compare(const IRelativePathElement& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRelativePathElement& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRelativePathElement& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IRelativePathElement
} // end namespace
#endif	// IRELATIVEPATHELEMENT_H
