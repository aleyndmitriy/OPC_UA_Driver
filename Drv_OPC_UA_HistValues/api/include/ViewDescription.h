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

#ifndef VIEWDESCRIPTION_H
#define VIEWDESCRIPTION_H

#include "IViewDescription.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDateTime.h"
#include "DateTime.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ViewDescription data type is used by the Browse (see Client::Session::browse() et al.) and
	* Query services (see Client::Session::queryFirst()) to specify the View to browse or query. */
	class TBC_EXPORT ViewDescription
		: public IViewDescription
	{
	public:
		/*! Default constructor */
		ViewDescription();
		/*! Constructs a copy of the given instance */
		ViewDescription(const IViewDescription*);
		/*! @overload */
		ViewDescription(const IViewDescription&);
		/*! @overload */
		ViewDescription(const ViewDescription&);

		/*! Destructor */
		virtual ~ViewDescription();

		/*! Assigns the contents of @p cp to this instance */
		ViewDescription& operator=(const IViewDescription* cp);
		/*! @overload */
		ViewDescription& operator=(const IViewDescription& cp);
		/*! @overload */
		ViewDescription& operator=(const ViewDescription& cp);

		/* see IViewDescription::set */
		virtual EnumStatusCode set(const IViewDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IViewDescription& pSrc);

		/* see IViewDescription::compare */
		virtual int compare(const IViewDescription*) const;
		/*! @overload */
		virtual int compare(const IViewDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IViewDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IViewDescription& other) const;

		/* see IViewDescription::getViewId */
		virtual const INodeId* getViewId() const;
		/*! @overload */
		virtual INodeId* getViewId();
		/* see IViewDescription::setViewId */
		virtual void setViewId(const INodeId* value);
		/*! @overload */
		virtual void setViewId(const NodeId& value);

		/* see IViewDescription::getTimestamp */
		virtual const IDateTime* getTimestamp() const;
		/*! @overload */
		virtual IDateTime* getTimestamp();
		/* see IViewDescription::setTimestamp */
		virtual void setTimestamp(const IDateTime* value);
		/*! @overload */
		virtual void setTimestamp(const DateTime& value);

		/* see IViewDescription::getViewVersion */
		virtual OTUInt32 getViewVersion() const;
		/* see IViewDescription::setViewVersion */
		virtual void setViewVersion(OTUInt32 value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		InnerNodeId m_ViewId;
		InnerDateTime m_Timestamp;

		ViewDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// VIEWDESCRIPTION_H
