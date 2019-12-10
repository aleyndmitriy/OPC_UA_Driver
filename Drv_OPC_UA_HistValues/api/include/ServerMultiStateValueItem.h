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

#ifndef SERVERMULTISTATEVALUEITEM_H
#define SERVERMULTISTATEVALUEITEM_H

#include "ServerDiscreteItem.h"
#include "EnumValueType.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents a DiscreteItem that can have more than two states and where the state values does not consist of consecutive
		numeric values (may have gaps).
		*
		* The MultiStateValueItem can contain values of any numeric data type.
		*
		* Properties of MultiStateValueItem:
		* @li EnumValues (mandatory):	A list of pairs which map specific discrete values to LocalizedText.
		*								Example: {"1/OPEN", "2/CLOSE", "4/IN TRANSIT"}.
		* @li ValueAsText (mandatory):	A property showing the LocalizedText matching the corresponding value. */
		class TBC_EXPORT MultiStateValueItem
			: public DiscreteItem
		{
		public:
			/*! Constructs a new MultiStateValueItem instance
			*
			* After construction the object has not a single state.
			* Use addState() to add additional states and setState() to set the state to a valid value. */
			static ObjectPointer<MultiStateValueItem> create();

			/*! Constructor with mandatory attributes
			*
			* @param nodeId						NodeId of the MultiStateValueItem to be created
			* @param displayName				The display name of the MultiStateValueItem to be created
			* @param browseName					The browse name of the MultiStateValueItem to be created
			* @param dataTypeNodeId				The data type of the MultiStateValueItem (it has to be numeric)
			* @param enumValuesPropertyNodeId	optional NodeId of the EnumValues property of the MultiStateValueItem to be created.
			*									(If no NodeId is specified, a nodeId will be generated)
			* @param valueAsTextPropertyNodeId	NodeId of the ValueAsText property of the MultiStateValueItem to be created.
			*									(If no NodeId is specified, a nodeId will be generated) */
			static ObjectPointer<MultiStateValueItem> create(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const INodeId* dataTypeNodeId,
				const INodeId* enumValuesPropertyNodeId = NULL,
				const INodeId* valueAsTextPropertyNodeId = NULL);

		protected:
			/*! Default constructor */
			MultiStateValueItem();

			/*! Please use MultiStateValueItem::create(const INodeId&, const ILocalizedText&, const IQualifiedName&, const INodeId& dataTypeNodeId) to construct an instance of this type.
			*
			* Constructor with mandatory attributes */
			MultiStateValueItem(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const INodeId* dataTypeNodeId,
				const INodeId* enumValuesPropertyNodeId = NULL,
				const INodeId* valueAsTextPropertyNodeId = NULL);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			MultiStateValueItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~MultiStateValueItem();

			/*! Adds a new state to the MultiStateValueItem.
			*
			* @param [in]	stateValue	The pair value / text that shall be added as a new state.
			*
			* @return					EnumStatusCode_Good if everything is ok
			*							EnumStatusCode_BadInvalidState if the property EnumValues cannot be found
			*							EnumStatusCode_BadInvalidArgument if a state with this value does already exist */
			EnumStatusCode addState(const EnumValueType& stateValue);

			/*! Sets the actual state of the MultiStateValueItem.
			*
			* The property "ValueAsText" is updated automatically.
			*
			* @param [in]	newState	The new state set to this item.
			*							The value is provided as Value since the instance can have any numeric data type.
			*							The value is validated that a defined state for this value exists.
			*
			* @return					EnumStatusCode_Good if everything is ok
			*							EnumStatusCode_BadInvalidArgument if the value cannot be converted to an OTInt64
			*							EnumStatusCode_BadOutOfRange if there is no state defined for the given value
			*							EnumStatusCode_BadTypeMismatch if the data type of the value does not match the data type of the item */
			EnumStatusCode setState(const Value & newState);

			/*! Overridden method that handles the write request for MultiStateValueItems.
			* The valid range of the value is checked against the available states.
			*
			* @note When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			* mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			* be set, but will not be reported by a subscription. */
			EnumStatusCode handleWriteRequest(Server::WriteTransaction* transaction, Server::WriteRequest* request);

			/*! @see BaseNode::init() */
			virtual EnumStatusCode init(const INodeId* typeId);

		private:
			/*! Forbid use assignment operator */
			MultiStateValueItem& operator=(const MultiStateValueItem&);
			/*! Forbid use of copy constructor */
			MultiStateValueItem(const MultiStateValueItem&);
		};

		typedef ObjectPointer<MultiStateValueItem> MultiStateValueItemPtr;
		typedef ObjectPointer<const MultiStateValueItem> MultiStateValueItemConstPtr;

	} // end Server namespace
} // toolbox namespace end
#endif	// SERVERMULTISTATEVALUEITEM_H
