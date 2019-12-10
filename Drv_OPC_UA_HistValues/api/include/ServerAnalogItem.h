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

#ifndef SERVERANALOGITEM_H
#define SERVERANALOGITEM_H

#include "ServerDataItem.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents a variable containing an analog value.
		*
		* The AnalogItem variable has the following properties:
		* @li InstrumentRange (optional):	Defines the value range that can be returned by the instrument.
		* @li EURange (mandatory):			Defines the value range likely to be obtained in normal operation.
		*									It is intended for such use as automatically scaling a bar graph display.
		* @li EngineeringUnits (optional):	Specifies the units for the DataItem's value (e.g., DEGC, hertz, seconds). */
		class TBC_EXPORT AnalogItem
			: public DataItem
		{
		public:
			/*! Constructs a new AnalogItem instance */
			static ObjectPointer<AnalogItem> create();

			/*! Constructs a new AnalogItem instance with mandatory attributes */
			static ObjectPointer<AnalogItem> create(
				const INodeId& nodeId,
				const NodeId* dataType,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const IRange& EURange);

		protected:
			/*! Default constructor */
			AnalogItem();

			/*! Please use AnalogItem::create(const INodeId&, const ILocalizedText&, const IQualifiedName&) to construct an instance of this type. */
			AnalogItem(const INodeId& nodeId,
				const NodeId* dataType,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const IRange& EURange);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AnalogItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~AnalogItem();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class AnalogItem
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the engineering unit range of the analog item.
			*
			* The EURange defines the value range likely to be obtained in normal operation.
			* It is intended for such use as automatically scaling a bar graph display. */
			EnumStatusCode setEURange(const IRange& EURange);

			/*! Sets the instrument range of the analog item.
			*
			* The InstrumentRange defines the value range that can be returned by the instrument. */
			EnumStatusCode setInstrumentRange(const IRange& instrumentRange);

			/*! Set engineering units of the analog item.
			*
			* The EngineeringUnits property specifies the units for the DataItem's value (e.g., DEGC, hertz, seconds).
			*
			* @see IEUInformation */
			EnumStatusCode setEngineeringUnits(const IEUInformation& engineeringUnits);

			/*! Overridden method ensuring that the written value is within the defined EURange. */
			virtual EnumStatusCode handleWriteRequest(Server::WriteTransaction* transaction, Server::WriteRequest* request);

			/*! @see BaseNode::init() */
			virtual EnumStatusCode init(const INodeId* typeId);

		private:
			/*! Forbid use assignment operator */
			AnalogItem& operator=(const AnalogItem&);
			/*! Forbid use of copy constructor */
			AnalogItem(const AnalogItem&);
		};

		typedef ObjectPointer<AnalogItem> AnalogItemPtr;
		typedef ObjectPointer<const AnalogItem> AnalogItemConstPtr;
	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERANALOGITEM_H
