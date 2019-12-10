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

#ifndef INNERQUERYDATADESCRIPTION_H
#define INNERQUERYDATADESCRIPTION_H
#if TB5_QUERY

#include "IQueryDataDescription.h"
#include "RelativePath.h"
#include "IRelativePath.h"
#include "InnerRelativePath.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "InnerNumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! Specifies an Attribute or Reference from the originating
	*  typeDefinitionNode along a given relativePath for which to return data.
	*
	* @note This class is used by the Query service */
	class TBC_EXPORT InnerQueryDataDescription
		: public IQueryDataDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerQueryDataDescription();

		/*! Browse path relative to the originating Node that identifies the Node
		* which contains the data that is being requested, where the originating
		* Node is an instance Node of the type defined by the type definition
		* Node. The instance Nodes are further limited by the filter provided as
		* part of this call.
		*
		* This relative path could end on a Reference, in which case the
		* ReferenceDescription of the Reference would be returned as its value. */
		virtual const IRelativePath* getRelativePath() const;
		virtual EnumStatusCode setRelativePath(const IRelativePath* value);
		virtual EnumStatusCode setRelativePath(const RelativePath& value);

		/*! Id of the Attribute. If the RelativePath ended in a Reference
		* then this parameter is 0 and ignored by the server. */
		virtual EnumAttributeId getAttributeId() const;
		virtual void setAttributeId(const EnumAttributeId& value);

		/*! This parameter is used to identify a single element of a structure or an
		* array, or a single range of indexes for arrays. If a range of elements
		* are specified, the values are returned as a composite.
		*
		* This parameter is null if the specified Attribute is not an array or a
		* structure. However, if the specified Attribute is an array or a structure,
		* and this parameter is null, then all elements are to be included in the
		* range. */
		virtual const INumericRange* getIndexRange() const;
		virtual EnumStatusCode setIndexRange(const INumericRange* value);
		virtual EnumStatusCode setIndexRange(const NumericRange& value);

		// init from otb handle
		void initInner(QueryDataDescriptionStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IQueryDataDescription* other) const;
		/*! @overload */
		virtual int compare(const IQueryDataDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQueryDataDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQueryDataDescription& other) const;

		/* see IQueryDataDescription::set */
		EnumStatusCode set(const IQueryDataDescription* pSrc);
		/*! @overload */
		EnumStatusCode set(const IQueryDataDescription& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		InnerRelativePath m_relativePath;
		InnerNumericRange m_indexRange;

		QueryDataDescriptionStruct* m_pContent;
	};
} // end namespace
#endif

#endif	// INNERQUERYDATADESCRIPTION_H
