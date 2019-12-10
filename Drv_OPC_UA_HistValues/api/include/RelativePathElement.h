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

#ifndef RELATIVEPATHELEMENT_H
#define RELATIVEPATHELEMENT_H

#include "IRelativePathElement.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The RelativePathElement data type defines a single element of a RelativePath. */
	class TBC_EXPORT RelativePathElement
		: public IRelativePathElement
	{
	public:
		/*! Default constructor */
		RelativePathElement();
		/*! Constructs a copy of the given instance */
		RelativePathElement(const IRelativePathElement*);
		/*! @overload */
		RelativePathElement(const IRelativePathElement&);
		/*! @overload */
		RelativePathElement(const RelativePathElement&);

		/*! Destructor */
		virtual ~RelativePathElement();

		/*! Assigns the contents of @p cp to this instance */
		RelativePathElement& operator=(const IRelativePathElement* cp);
		/*! @overload */
		RelativePathElement& operator=(const IRelativePathElement& cp);
		/*! @overload */
		RelativePathElement& operator=(const RelativePathElement& cp);

		/* see IRelativePathElement::set */
		virtual EnumStatusCode set(const IRelativePathElement* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IRelativePathElement& pSrc);

		/* see IRelativePathElement::compare */
		virtual int compare(const IRelativePathElement*) const;
		/*! @overload */
		virtual int compare(const IRelativePathElement&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRelativePathElement& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRelativePathElement& other) const;

		/* see IRelativePathElement::getReferenceTypeId */
		virtual const INodeId* getReferenceTypeId() const;
		/*! @overload */
		virtual INodeId* getReferenceTypeId();
		/* see IRelativePathElement::setReferenceTypeId */
		virtual void setReferenceTypeId(const INodeId* value);
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value);

		/* see IRelativePathElement::getIsInverse */
		virtual bool getIsInverse() const;
		/* see IRelativePathElement::setIsInverse */
		virtual void setIsInverse(bool value);

		/* see IRelativePathElement::getIncludeSubtypes */
		virtual bool getIncludeSubtypes() const;
		/* see IRelativePathElement::setIncludeSubtypes */
		virtual void setIncludeSubtypes(bool value);

		/* see IRelativePathElement::getTargetName */
		virtual const IQualifiedName* getTargetName() const;
		/*! @overload */
		virtual IQualifiedName* getTargetName();
		/* see IRelativePathElement::setTargetName */
		virtual void setTargetName(const IQualifiedName* value);
		/*! @overload */
		virtual void setTargetName(const QualifiedName& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_ReferenceTypeId;
		InnerQualifiedName m_TargetName;

		RelativePathElementStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// RELATIVEPATHELEMENT_H
