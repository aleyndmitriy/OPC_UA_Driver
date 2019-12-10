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

#ifndef QUERYDATADESCRIPTION_H
#define QUERYDATADESCRIPTION_H
#if TB5_QUERY

#include "IQueryDataDescription.h"
#include "RelativePath.h"
#include "IRelativePath.h"
#include "InnerRelativePath.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "InnerNumericRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The QueryDataDescription data type is used by the QueryFirst service (see Client::Session::queryFirst())
	* to specify an attribute or a reference from the originating type definition node along a given RelativePath
	* for which to return data. */
	class TBC_EXPORT QueryDataDescription
		: public IQueryDataDescription
	{
	public:
		/*! Default constructor */
		QueryDataDescription();
		/*! Constructs a copy of the given instance */
		QueryDataDescription(const IQueryDataDescription*);
		/*! @overload */
		QueryDataDescription(const IQueryDataDescription&);
		/*! @overload */
		QueryDataDescription(const QueryDataDescription&);

		/*! Destructor */
		virtual ~QueryDataDescription();

		/*! Assigns the contents of @p cp to this instance */
		QueryDataDescription& operator=(const IQueryDataDescription* cp);
		/*! @overload */
		QueryDataDescription& operator=(const IQueryDataDescription& cp);
		/*! @overload */
		QueryDataDescription& operator=(const QueryDataDescription& cp);

		/* see IQueryDataDescription::set */
		virtual EnumStatusCode set(const IQueryDataDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IQueryDataDescription& pSrc);

		/* see IQueryDataDescription::compare */
		virtual int compare(const IQueryDataDescription*) const;
		/*! @overload */
		virtual int compare(const IQueryDataDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQueryDataDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQueryDataDescription& other) const;

		/* see IQueryDataDescription::getRelativePath */
		virtual const IRelativePath* getRelativePath() const;
		/* see IQueryDataDescription::setRelativePath */
		virtual EnumStatusCode setRelativePath(const IRelativePath* value);
		/*! @overload */
		virtual EnumStatusCode setRelativePath(const RelativePath& value);

		/* see IQueryDataDescription::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;
		/* see IQueryDataDescription::setAttributeId */
		virtual void setAttributeId(const EnumAttributeId& value);

		/* see IQueryDataDescription::getIndexRange */
		virtual const INumericRange* getIndexRange() const;
		/* see IQueryDataDescription::setIndexRange */
		virtual EnumStatusCode setIndexRange(const INumericRange* value);
		/*! @overload */
		virtual EnumStatusCode setIndexRange(const NumericRange& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerRelativePath m_relativePath;
		InnerNumericRange m_indexRange;

		QueryDataDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif	// QUERYDATADESCRIPTION_H
