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

#ifndef PUBSUBWRITERGROUP_H
#define PUBSUBWRITERGROUP_H

#include "PubSubGroup.h"
#include "PubSubDataSetWriter.h"
#include "WriterGroupMessageDataType.h"
#include "WriterGroupTransportDataType.h"
namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
		/*! The WriterGroup class represents a PubSub WriterGroup for publishing values.
		*
		* A writer group contains settings for a group of PubSub::DataSetWriter.
		* The writer group is responsible to publish cyclically messages containing all data of the contained DataSetWriter objects. */
		class TBC_EXPORT WriterGroup
			: public Group
		{
		public:
			/*! Constructs a new WriterGroup instance */
			static ObjectPointer<WriterGroup> create();

		protected:
			/*! Default constructor */
			WriterGroup();

			/*! For internal use only */
			WriterGroup(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~WriterGroup();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class WriterGroup
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the WriterGroupId
			*
			* The WriterGroupId with DataType UInt16 is an identifier for the WriterGroup
			* and shall be unique across all WriterGroups for a PublisherId.
			* All values, except for 0, are valid.
			*
			* @param writerGroupId	The WriterGroupId */
			EnumStatusCode setWriterGroupId(const OTUInt16 &writerGroupId);
			/*! Gets the WriterGroupId
			*
			* @see setWriterGroupId()) */
			OTUInt16 getWriterGroupId() const;

			/*! Sets the PublishingInterval
			*
			* @param publishingInterval	The publishingInterval
			*
			* @see IWriterGroupDataType::setPublishingInterval

			* @note Default PublishingInterval is 100 milliseconds
			* @note Minimal PublishingInterval is 1 millisecond */
			EnumStatusCode setPublishingInterval(const OTDouble &publishingInterval);
			/*! Gets the PublishingInterval
			*
			* @see setPublishingInterval()) */
			OTDouble getPublishingInterval() const;

			/*! Sets the KeepAliveTime
			*
			* @see IWriterGroupDataType::setKeepAliveTime
			*
			* @note Default KeepAliveTime is 10000 milliseconds */
			EnumStatusCode setKeepAliveTime(const OTDouble &keepAliveTime);
			/*! Gets the KeepAliveTime
			*
			* @see setKeepAliveTime()) */
			OTDouble getKeepAliveTime() const;

			/*! Sets the Priority
			*
			* @param priority	The new priority
			*
			* @see IWriterGroupDataType::setPriority
			*
			* @note Default priority is 100
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setPriority(const OTUInt8 &priority);
			/*! Gets the Priority
			*
			* @see setPriority()) */
			OTUInt8 getPriority() const;

			/*! Adds a PubSub dataSetWriter to the writer group
			*
			* @note The name of the DataSetWriter must be valid and unique among all other DataSetWriters of this WriterGroup */
			EnumStatusCode addDataSetWriter(DataSetWriterPtr dataSetWriter);
			/*! Removes a PubSub dataSetWriter from the writer group */
			EnumStatusCode removeDataSetWriter(DataSetWriterPtr dataSetWriter);
			/*! Gets all dataSetWriter from the writer group */
			std::vector<DataSetWriterPtr> getDataSetWriters() const;

			/*! Sets the message settings of the writer group
			*
			* @param messageSettings		The message settings which shall be used
			*
			* @see IWriterGroupDataType::setMessageSettings */
			EnumStatusCode setMessageSettings(const WriterGroupMessageDataType &messageSettings);
			/*! Gets the message settings
			*
			* @see setMessageSettings */
			WriterGroupMessageDataType getMessageSettings() const;

			/*! Sets the transport settings of the writer group
			*
			* @param transportSettings		The transport settings which shall be used
			*
			* @see IWriterGroupDataType::setTransportSettings
			*
			* @note <b>All settings in DatagramWriterGroupTransportDataType are not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setTransportSettings(const WriterGroupTransportDataType &transportSettings);
			/*! Gets the Transport settings
			*
			* @see setTransportSettings */
			WriterGroupTransportDataType getTransportSettings() const;
		private:

			/*! Forbid use assignment operator */
			WriterGroup& operator=(const WriterGroup&);
			/*! Forbid use of copy constructor */
			WriterGroup(const WriterGroup&);
		};
		typedef ObjectPointer<WriterGroup>WriterGroupPtr;
		typedef ObjectPointer<const WriterGroup> WriterGroupConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif //PUBSUBWRITERGROUP_H
