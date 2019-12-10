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

#ifndef INNERVIEWDESCRIPTION_H
#define INNERVIEWDESCRIPTION_H

#include "IViewDescription.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDateTime.h"
#include "DateTime.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerViewDescription
	class TBC_EXPORT InnerViewDescription
		: public IViewDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerViewDescription();

		/*! NodeId of the View to Query. A null value indicates the entire AddressSpace. */
		virtual const INodeId* getViewId() const;
		virtual INodeId* getViewId();
		virtual void setViewId(const INodeId* value);
		virtual void setViewId(const NodeId& value);

		/*! The time date desired. The corresponding version is the one with the closest
		* previous creation timestamp. Either the Timestamp or the viewVersion
		* parameter may be set by a Client, but not both. If ViewVersion is set this
		* parameter shall be null. */
		virtual const IDateTime* getTimestamp() const;
		virtual IDateTime* getTimestamp();
		virtual void setTimestamp(const IDateTime* value);
		virtual void setTimestamp(const DateTime& value);

		/*! The version number for the View desired. When Nodes are added to or removed
		* from a View, the value of a View's ViewVersion Property is updated. Either the
		* Timestamp or the viewVersion parameter may be set by a Client, but not both.
		* If timestamp is set this parameter shall be 0. The current view is used if timestamp is null and viewVersion
		* is 0. */
		virtual OTUInt32 getViewVersion() const;
		virtual void setViewVersion(OTUInt32 value);


		// init from otb handle
		void initInner(ViewDescriptionStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IViewDescription* other) const;
		/*! @overload */
		virtual int compare(const IViewDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IViewDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IViewDescription& other) const;

		// set from interface
		EnumStatusCode set(const IViewDescription* pSrc);
		EnumStatusCode set(const IViewDescription& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		// the handle to the related core object
		ViewDescriptionStruct* m_pViewDescription_Data;
		InnerNodeId m_ViewId;
		InnerDateTime m_Timestamp;
	};
}
#endif	// INNERVIEWDESCRIPTION_H
