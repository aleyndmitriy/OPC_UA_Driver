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

#ifndef PUBSUBCONFIGURATIONDATATYPE_H
#define PUBSUBCONFIGURATIONDATATYPE_H

#include "IPubSubConfigurationDataType.h"
#include "PublishedDataSetDataType.h"
#include "IPublishedDataSetDataType.h"
#include "InnerPublishedDataSetDataType.h"
#include "PubSubConnectionDataType.h"
#include "IPubSubConnectionDataType.h"
#include "InnerPubSubConnectionDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The PubSubConfigurationDataType is used to store the PubSub configuration of an OPC UA Application. */
	class TBC_EXPORT PubSubConfigurationDataType
		: public IPubSubConfigurationDataType
	{
	public:
		/*! Default constructor */
		PubSubConfigurationDataType();
		/*! Constructs a copy of the given instance @p cp */
		PubSubConfigurationDataType(const IPubSubConfigurationDataType* cp);
		/*! @overload */
		PubSubConfigurationDataType(const IPubSubConfigurationDataType& cp);
		/*! @overload */
		PubSubConfigurationDataType(const PubSubConfigurationDataType& cp);

		/*! Destructor */
		virtual ~PubSubConfigurationDataType();

		/*! Assigns the contents of @p cp to this instance */
		PubSubConfigurationDataType& operator=(const IPubSubConfigurationDataType* cp);
		/*! @overload */
		PubSubConfigurationDataType& operator=(const IPubSubConfigurationDataType& cp);
		/*! @overload */
		PubSubConfigurationDataType& operator=(const PubSubConfigurationDataType& cp);

		/*! @see IPubSubConfigurationDataType::compare(IPubSubConfigurationDataType*) */
		virtual int compare(const IPubSubConfigurationDataType* other) const;
		/*! @overload */
		virtual int compare(const IPubSubConfigurationDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubConfigurationDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubConfigurationDataType& other) const;

		/* see IPubSubConfigurationDataType::set(IPubSubConfigurationDataType*) */
		virtual EnumStatusCode set(const IPubSubConfigurationDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubConfigurationDataType& pSrc);

		/* see IPubSubConfigurationDataType::addPublishedDataSet */
		virtual EnumStatusCode addPublishedDataSet(const IPublishedDataSetDataType& dataSet);
		/* see IPubSubConfigurationDataType::getPublishedDataSets */
		virtual std::vector<PublishedDataSetDataType> getPublishedDataSets() const;

		/* see IPubSubConfigurationDataType::addConnection */
		virtual EnumStatusCode addConnection(const IPubSubConnectionDataType& connection);
		/* see IPubSubConfigurationDataType::getConnections */
		virtual std::vector<PubSubConnectionDataType> getConnections() const;

		/* see IPubSubConfigurationDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IPubSubConfigurationDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPublishedDataSetDataType> m_pPublishedDataSets)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPubSubConnectionDataType> m_pConnections)

		PubSubConfigurationDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
