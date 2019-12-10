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

#ifndef IVIEWDESCRIPTION_H
#define IVIEWDESCRIPTION_H

#include "ViewDescriptionStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDateTime.h"
#include "DateTime.h"

namespace SoftingOPCToolbox5
{
	/*! The ViewDescription data type is used by the Browse (see Client::Session::browse() et al.) and
	* Query services (see Client::Session::queryFirst()) to specify the View to browse or query. */
	class TBC_EXPORT IViewDescription
	{
	public:
		/*! Destructor */
		virtual ~IViewDescription(){};

		/*! Returns the NodeId of the View to query.
		*
		* @see setViewId() */
		virtual const INodeId* getViewId() const = 0;
		/*! @overload */
		virtual INodeId* getViewId() = 0;
		/*! Sets the NodeId of the View to query.
		*
		* Omitting this parameter indicates the entire AddressSpace. */
		virtual void setViewId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setViewId(const NodeId& value) = 0;

		/*! Returns the time date desired.
		*
		* @see setTimestamp() */
		virtual const IDateTime* getTimestamp() const = 0;
		/*! @overload */
		virtual IDateTime* getTimestamp() = 0;
		/*! Sets the time date desired.
		* The corresponding version is the one with the closest previous creation timestamp.
		*
		* @see setViewVersion()
		* @note Either the Timestamp or the ViewVersion parameter may be set by a client, but not both. */
		virtual void setTimestamp(const IDateTime* value) = 0;
		/*! @overload */
		virtual void setTimestamp(const DateTime& value) = 0;

		/*! Returns the version number for the View desired.
		*
		* @see setViewVersion() */
		virtual OTUInt32 getViewVersion() const = 0;
		/*! Sets the version number for the View desired.
		*
		* When nodes are added to or removed from a View, the value of a View's ViewVersion
		* property is updated. The current view is used if both Timestamp and ViewVersion
		* is not set.
		*
		* @see setTimestamp()
		* @note Either the Timestamp or the ViewVersion parameter may be set by a Client, but not both. */
		virtual void setViewVersion(OTUInt32 value) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IViewDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IViewDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IViewDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IViewDescription& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IViewDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IViewDescription& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IViewDescription
} // end namespace
#endif	// IVIEWDESCRIPTION_H
