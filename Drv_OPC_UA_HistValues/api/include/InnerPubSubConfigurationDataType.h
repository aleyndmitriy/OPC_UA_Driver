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

#ifndef INNERPUBSUBCONFIGURATIONDATATYPE_H
#define INNERPUBSUBCONFIGURATIONDATATYPE_H

#include "IPubSubConfigurationDataType.h"
#include "PublishedDataSetDataType.h"
#include "IPublishedDataSetDataType.h"
#include "InnerPublishedDataSetDataType.h"
#include "PubSubConnectionDataType.h"
#include "IPubSubConnectionDataType.h"
#include "InnerPubSubConnectionDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPubSubConfigurationDataType
		: public IPubSubConfigurationDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPubSubConfigurationDataType();

		/*! Gets the PublishedDataSets member of the class */
		virtual std::vector<PublishedDataSetDataType> getPublishedDataSets() const;
		/*! Adds a PublishedDataSet to the PublishedDataSets member of the class */
		virtual EnumStatusCode addPublishedDataSet(const IPublishedDataSetDataType& dataSet);

		/*! Gets the Connections member of the class */
		virtual std::vector<PubSubConnectionDataType> getConnections() const;
		/*! Adds a Connection to the Connections member of the class */
		virtual EnumStatusCode addConnection(const IPubSubConnectionDataType& connection);

		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const;
		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& value);

		/*! For internal use only */
		void initInner(PubSubConfigurationDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPubSubConfigurationDataType* pSrc);
		virtual EnumStatusCode set(const IPubSubConfigurationDataType& pSrc);

		virtual int compare(const IPubSubConfigurationDataType* other) const;
		virtual int compare(const IPubSubConfigurationDataType& other) const;

		virtual bool operator==(const IPubSubConfigurationDataType& other) const;
		virtual bool operator!=(const IPubSubConfigurationDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPublishedDataSetDataType> m_pPublishedDataSets)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPubSubConnectionDataType> m_pConnections)

		PubSubConfigurationDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
