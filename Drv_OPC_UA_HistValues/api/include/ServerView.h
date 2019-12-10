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

#ifndef SERVERVIEW_H
#define SERVERVIEW_H
#include "Base.h"
#include "Enums.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The View class is used to define a view node in the address space.
		*
		* A view node can be used to reduce results of client browse and query requests (if specified).
		*
		* @note A server cannot use views to restrict client access in general.
		*		If a client browses without specified view the complete address space is visible and accessible.
		*
		* @note The OPC UA SDK gives no support of view filters in this version.
		*		The implementation of view filters has to be implemented completely in the server application. */
		class TBC_EXPORT View
			: public BaseNode
		{
		public:
			/*! Constructs a new View instance */
			static ObjectPointer<View> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			View(TBHandle otbHandle);

			/*! Returns the 'EventNotifier' attribute of this view.
			*
			* @see setEventNotifier() */
			EnumEventNotifier getEventNotifier() const;
			/*! Sets the 'EventNotifier' attribute of this view.
			*
			* The EventNotifier attribute is used to indicate if the node can be used
			* to subscribe to events or to read/write historical events.
			*
			* By default, the event notifier attribute contains 0.
			*
			* @see EnumEventNotifier */
			EnumStatusCode setEventNotifier(EnumEventNotifier eventNotifier);

			/*! Returns the 'ContainsNoLoops' attribute of this view.
			*
			* @see setContainsNoLoops() */
			OTBoolean getContainsNoLoops() const;
			/*! Sets the 'ContainsNoLoops' attribute of this view.
			*
			* If set to true this attribute indicates that following references in the
			* context of the View contains no loops, i.e. starting from a Node "A"
			* contained in the View and following the forward References in the
			* context of the View Node "A" will not be reached again. It does not
			* specify that there is only one path starting from the View Node to
			* reach a Node contained in the View.
			*
			* If set to false this Attribute indicates that following References in the
			* context of the View may lead to loops.
			*
			* By default, the ContainsNoLoops attribute contains false. */
			EnumStatusCode setContainsNoLoops(OTBoolean containsNoLoops);

		protected:
			/*! Default constructor */
			View();
			/*! For internal use only */
			View(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~View();

		private:
			/*! Forbid use assignment operator */
			View& operator=(const View&);
			/*! Forbid use of copy constructor */
			View(const View&);
		};
		typedef ObjectPointer<View> ViewPtr;
		typedef ObjectPointer<const View> ViewConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERVIEW_H
