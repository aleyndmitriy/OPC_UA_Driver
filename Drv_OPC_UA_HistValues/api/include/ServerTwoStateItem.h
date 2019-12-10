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

#ifndef SERVERTWOSTATEITEM_H
#define SERVERTWOSTATEITEM_H

#include "ServerDiscreteItem.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents a variable that may take on only two different values (e.g. 'Opened' and 'Closed').
		*
		* Properties of the TwoStateItem:
		* @li TrueState (mandatory):	Contains a string to be associated with this DataItem when it is TRUE.
		*								This is typically used for a contact when it is in the closed (non-zero) state.
		*								Example: "RUN", "CLOSE", "ENABLE", "SAFE", etc.
		* @li FalseState (mandatory):	Contains a string to be associated with this DataItem when it is FALSE.
		*								This is typically used for a contact when it is in the open (zero) state.
		*								Example: "STOP", "OPEN", "DISABLE", "UNSAFE", etc. */
		class TBC_EXPORT TwoStateItem
			: public DiscreteItem
		{
		public:
			/*! Constructs a new TwoStateItem instance */
			static ObjectPointer<TwoStateItem> create();

			/*! Constructs a new TwoStateItem instance with mandatory attributes */
			static ObjectPointer<TwoStateItem> create(
				const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& trueStateText,
				const ILocalizedText& falseStateText);

		protected:
			/*! Default constructor */
			TwoStateItem();

			/*! Constructor with mandatory attributes */
			TwoStateItem(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& trueStateText,
				const ILocalizedText& falseStateText);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TwoStateItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~TwoStateItem();

			/*! Sets the property 'TrueState' of TwoStateItem. */
			EnumStatusCode setTrueText(const ILocalizedText& stateText);

			/*! Sets the property 'FalseState' of TwoStateItem. */
			EnumStatusCode setFalseText(const ILocalizedText& stateText);

			/*! @see BaseNode::init() */
			virtual EnumStatusCode init(const INodeId* typeId);

		private:
			/*! Forbid use assignment operator */
			TwoStateItem& operator=(const TwoStateItem&);
			/*! Forbid use of copy constructor */
			TwoStateItem(const TwoStateItem&);
		};

		typedef ObjectPointer<TwoStateItem> TwoStateItemPtr;
		typedef ObjectPointer<const TwoStateItem> TwoStateItemConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTWOSTATEITEM_H
