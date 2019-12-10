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

#ifndef SERVERDATAITEM_H
#define SERVERDATAITEM_H

#include "ServerVariable.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A DataItem represents a link to automation data.
		*
		* This class is abstract and used as base for other item classes e.g. AnalogItem or DiscreteItem.
		* Properties of DataItem are:
		* @li Definition (optional):		A vendor-specific, human readable string that specifies how the value of this DataItem is
		*									calculated. Definition is non-localized and will often contain an equation that can be parsed
		*									by certain clients.
		* @li ValuePrecision (optional):	Specifies the maximum precision that the server can maintain for the item
		*									based on restrictions in the target environment.
		*									For Float and Double values it specifies the number of digits after the decimal place.
		*									For DateTime values it indicates the minimum time difference in nanoseconds.
		*									E.g., a ValuePrecision of 20.000.000 defines a precision of 20 milliseconds. */
		class TBC_EXPORT DataItem
			: public Server::Variable
		{
		public:
			/*! Constructs a new DataItem instance */
			static ObjectPointer<DataItem> create();

			/*! Constructor with mandatory attributes
			*
			* @param nodeId						NodeId of the DataItem to be created
			* @param displayName				The display name of the DataItem to be created
			* @param browseName					The browse name of the DataItem to be created */
			static ObjectPointer<DataItem> create(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName);

		protected:
			/*! Default constructor */
			DataItem();

			/*! For internal use only */
			DataItem(bool suppressCoreInstanceCreate);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DataItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~DataItem();

		protected:
			/*! Sets mandatory attributes to the data item
			*
			* This method is meant to be invoked within the create() method of this and derived classes where the attributes are given.
			*
			* @param nodeId						NodeId of the DataItem to be created
			* @param displayName				The display name of the DataItem to be created
			* @param browseName					The browse name of the DataItem to be created */
			void setMandatoryAttributes(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName);
		public:
			/////////////////////////////////////////////////////////////////////////
			// Methods of class DataItem
			/////////////////////////////////////////////////////////////////////////

			/*! Set the Definition property of the data item. */
			EnumStatusCode setDefinition(const tstring definition);

			/*! Set the ValuePrecision property of the data item. */
			EnumStatusCode setPrecision(double valuePrecision);

			/*! @see BaseNode::init() */
			virtual EnumStatusCode init(const INodeId* typeId);

		private:
			/*! Forbid use assignment operator */
			DataItem& operator=(const DataItem&);
			/*! Forbid use of copy constructor */
			DataItem(const DataItem&);
		};

		typedef ObjectPointer<DataItem> DataItemPtr;
		typedef ObjectPointer<const DataItem> DataItemConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDATAITEM_H
