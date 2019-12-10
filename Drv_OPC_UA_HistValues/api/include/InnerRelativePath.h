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

#ifndef INNERRELATIVEPATH_H
#define INNERRELATIVEPATH_H

#include "IRelativePath.h"
#include "InnerRelativePathElement.h"
#include "RelativePathElement.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerRelativePath
	class TBC_EXPORT InnerRelativePath
		: public IRelativePath
	{
	public:
		/*! Destructor */
		virtual ~InnerRelativePath();

		/*! A sequence of References and BrowseNames to follow.
		* Each element in the sequence is processed by finding the targets and then using those targets as the starting
		* nodes for the next element. The targets of the final element are the target of the RelativePath. */
		virtual OTUInt32 getElementCount() const;
		virtual const IRelativePathElement* getElement(OTUInt32 index) const;
		virtual std::vector<RelativePathElement> getElements() const;
		virtual EnumStatusCode addElement(const IRelativePathElement* pValue);
		virtual EnumStatusCode addElement(const IRelativePathElement& value);


		// init from otb handle
		void initInner(RelativePathStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IRelativePath* other) const;
		/*! @overload */
		virtual int compare(const IRelativePath& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRelativePath& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRelativePath& other) const;

		// set from interface
		EnumStatusCode set(const IRelativePath* pSrc);
		EnumStatusCode set(const IRelativePath& pSrc);

	private:
		// the handle to the related core object
		RelativePathStruct* m_pRelativePath_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerRelativePathElement> m_Elements)
	};
}
#endif	// INNERRELATIVEPATH_H
