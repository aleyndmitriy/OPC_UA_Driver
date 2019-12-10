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

#ifndef SERVERREFERENCEITERATOR_H
#define SERVERREFERENCEITERATOR_H
#include "Base.h"
#include "Enums.h"
#include "InnerReferenceDescription.h"
#include "ReferenceDescription.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The ReferenceIterator is used to iterate through the references of a node. */
		class TBC_EXPORT ReferenceIterator
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ReferenceIterator(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			ReferenceIterator(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ReferenceIterator();

			/*! Moves the iterator to the next reference matching the iterator's configuration. */
			void moveNext();

			/*! Returns true if all references have been iterated.
			*
			* @note Please note that getReferenceDescription() returns an invalid pointer when isEnd() returns true. */
			bool isEnd() const;

			/*! Returns a description for the reference at the iterator's current position.
			*
			* @note Please note that getReferenceDescription() returns an invalid pointer when isEnd() returns true. */
			const IReferenceDescription* getReferenceDescription() const;

		private:
			/*! For internal use only */
			void initMembers();

			InnerReferenceDescription m_referenceDescription;

			/*! Forbid use of default constructor */
			ReferenceIterator();
			/*! Forbid use assignment operator */
			ReferenceIterator& operator=(const ReferenceIterator&);
			/*! Forbid use of copy constructor */
			ReferenceIterator(const ReferenceIterator&);
		};
		typedef ObjectPointer<ReferenceIterator> ReferenceIteratorPtr;
		typedef ObjectPointer<const ReferenceIterator> ReferenceIteratorConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERREFERENCEITERATOR_H
