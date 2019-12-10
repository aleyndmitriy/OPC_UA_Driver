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

#ifndef SERVERDISCRETEITEM_H
#define SERVERDISCRETEITEM_H

#include "ServerDataItem.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents a variable that may take on only a certain number of possible values (e.g. 'Opened' and 'Closed').
		* This class is abstract and used as base for other discrete item classes e.g. TwoStateItem or MultiStateItem.
		* The DiscreteItem class defines no additional properties. */
		class TBC_EXPORT DiscreteItem
			: public DataItem
		{
		protected:
			/*! Default constructor is protected. Use DiscreteItem::create() instead */
			DiscreteItem();

			/*! For internal use only */
			DiscreteItem(bool suppressCoreInstanceCreate);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DiscreteItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~DiscreteItem();

		private:
			/*! Forbid use assignment operator */
			DiscreteItem& operator=(const DiscreteItem&);
			/*! Forbid use of copy constructor */
			DiscreteItem(const DiscreteItem&);
		};

		typedef ObjectPointer<DiscreteItem> DiscreteItemPtr;
		typedef ObjectPointer<const DiscreteItem> DiscreteItemConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDISCRETEITEM_H
