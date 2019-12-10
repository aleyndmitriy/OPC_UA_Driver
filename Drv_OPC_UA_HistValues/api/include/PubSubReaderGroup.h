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

#ifndef PUBSUBREADERGROUP_H
#define PUBSUBREADERGROUP_H

#include "PubSubGroup.h"
#include "PubSubDataSetReader.h"
#include "ReaderGroupMessageDataType.h"
#include "ReaderGroupTransportDataType.h"
namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
		/*! The ReaderGroup class represents a PubSub ReaderGroup for publishing values.
		*
		* A reader group is used to group a list of readers. It is not symmetric to a WriterGroup and it is not related to a particular NetworkMessage.
		* The NetworkMessage related filter settings are on the DataSetReaders.
		*
		* The configuration of the group (e.g. security) can be used as a default configuration of all contained DatSetReaders. */
		class TBC_EXPORT ReaderGroup
			: public Group
		{
		public:
			/*! Constructs a new ReaderGroup instance */
			static ObjectPointer<ReaderGroup> create();

		protected:
			/*! For internal use only */
			ReaderGroup(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ReaderGroup();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class ReaderGroup
			/////////////////////////////////////////////////////////////////////////

			/*! Adds a PubSub DataSetReader to the Reader group
			*
			* @note The name of the DataSetReader must be valid and unique among all other DataSetReaders of this ReaderGroup */
			EnumStatusCode addDataSetReader(DataSetReaderPtr dataSetReader);
			/*! Removes a PubSub dataSetReader from the Reader group */
			EnumStatusCode removeDataSetReader(DataSetReaderPtr dataSetReader);
			/*! Gets all dataSetReader from the Reader group */
			std::vector<DataSetReaderPtr> getDataSetReaders() const;

			// message settings for group uses the abstract class ReaderGroupMessageDataType
			// No concrete sub-class are defined, so no message settings can be provided
			// Issue in specification?

			/*! Sets the transport settings of the reader group
			*
			* @param transportSettings		The transport settings which shall be used
			*
			* @note <b>There is currently no transport protocol mapping specific setting defined.</b>
			*
			* @see IReaderGroupDataType::setTransportSettings */
			EnumStatusCode setTransportSettings(const ReaderGroupTransportDataType &transportSettings);
			/*! Gets the Transport settings
			*
			* @see setTransportSettings */
			ReaderGroupTransportDataType getTransportSettings() const;
		private:

			/*! Default constructor */
			ReaderGroup();
			/*! Forbid use assignment operator */
			ReaderGroup& operator=(const ReaderGroup&);
			/*! Forbid use of copy constructor */
			ReaderGroup(const ReaderGroup&);
		};
		typedef ObjectPointer<ReaderGroup>ReaderGroupPtr;
		typedef ObjectPointer<const ReaderGroup> ReaderGroupConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif //PUBSUBREADERGROUP_H
