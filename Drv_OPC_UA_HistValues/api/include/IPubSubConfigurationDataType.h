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

#ifndef IPUBSUBCONFIGURATIONDATATYPE_H
#define IPUBSUBCONFIGURATIONDATATYPE_H

#include "PubSubConfigurationDataTypeStruct.h"
#include "PublishedDataSetDataType.h"
#include "IPublishedDataSetDataType.h"
#include "PubSubConnectionDataType.h"
#include "IPubSubConnectionDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The PubSubConfigurationDataType is used to store the PubSub configuration of an OPC UA Application. */
	class TBC_EXPORT IPubSubConfigurationDataType
	{
	public:
		/*! Destructor */
		virtual ~IPubSubConfigurationDataType(){};

		/*! Adds a PublishedDataSet to the PublishedDataSets member of the class */
		virtual EnumStatusCode addPublishedDataSet(const IPublishedDataSetDataType& dataSet) = 0;
		/*! Gets the PublishedDataSets member of the class */
		virtual std::vector<PublishedDataSetDataType> getPublishedDataSets() const = 0;

		/*! Adds a Connection to the Connections member of the class */
		virtual EnumStatusCode addConnection(const IPubSubConnectionDataType& connection) = 0;
		/*! Gets the Connections member of the class */
		virtual std::vector<PubSubConnectionDataType> getConnections() const = 0;

		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPubSubConfigurationDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IPubSubConfigurationDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubConfigurationDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubConfigurationDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPubSubConfigurationDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubConfigurationDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPubSubConfigurationDataType
} // end namespace

#endif
