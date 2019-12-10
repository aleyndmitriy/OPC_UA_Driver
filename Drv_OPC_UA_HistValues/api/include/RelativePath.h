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

#ifndef RELATIVEPATH_H
#define RELATIVEPATH_H

#include "IRelativePath.h"
#include "InnerRelativePathElement.h"
#include "RelativePathElement.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The RelativePath data type defines a sequence of browse names and references to follow. */
	class TBC_EXPORT RelativePath
		: public IRelativePath
	{
	public:
		/*! Default constructor */
		RelativePath();
		/*! Constructs a copy of the given instance */
		RelativePath(const IRelativePath*);
		/*! @overload */
		RelativePath(const IRelativePath&);
		/*! @overload */
		RelativePath(const RelativePath&);

		/*! Destructor */
		virtual ~RelativePath();

		/*! Assigns the contents of @p cp to this instance */
		RelativePath& operator=(const IRelativePath*);
		/*! @overload */
		RelativePath& operator=(const IRelativePath&);
		/*! @overload */
		RelativePath& operator=(const RelativePath&);

		/* see IRelativePath::set */
		virtual EnumStatusCode set(const IRelativePath* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IRelativePath& pSrc);

		/* see IRelativePath::compare */
		virtual int compare(const IRelativePath*) const;
		/*! @overload */
		virtual int compare(const IRelativePath&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRelativePath& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRelativePath& other) const;

		/* see IRelativePath::getElementCount */
		virtual OTUInt32 getElementCount() const;
		/* see IRelativePath::getElement */
		virtual const IRelativePathElement* getElement(OTUInt32 index) const;
		/* see IRelativePath::getElements */
		virtual std::vector<RelativePathElement> getElements() const;
		/* see IRelativePath::addElement */
		virtual EnumStatusCode addElement(const IRelativePathElement* pValue);
		/*! @overload */
		virtual EnumStatusCode addElement(const IRelativePathElement& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerRelativePathElement> m_Elements)
		RelativePathStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// RELATIVEPATH_H
