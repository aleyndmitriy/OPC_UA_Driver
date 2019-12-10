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

#ifndef SERVERREFERENCETYPE_H
#define SERVERREFERENCETYPE_H
#include "Base.h"
#include "Enums.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The ReferenceType class is used to define a ReferenceType node in the address space of a server.
		*
		* References are defined as instances of ReferenceType nodes. ReferenceType nodes are visible in
		* the address space of a server. In contrast, a reference is an inherent part of a node (see BaseNode::addReference() et al.)
		* and no separate class is used to represent references.
		*
		* The SDK defines constants for all well-known reference types in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes). */
		class TBC_EXPORT ReferenceType
			: public BaseNode
		{
		public:
			/*! Constructs a new ReferenceType instance */
			static ObjectPointer<ReferenceType> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ReferenceType(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ReferenceType();
			/*! For internal use only */
			ReferenceType(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ReferenceType();

			/*! If true, indicates that references of this type may NOT be used in the address space of the server. */
			bool getIsAbstract() const;
			/*! Defines whether references of this type may be used to create references between nodes in the address space.
			* If true, this reference type cannot be used by nodes. */
			EnumStatusCode setIsAbstract(bool isAbstract);

			/*! Returns whether the meaning of the reference type is the same as seen from both the source
			* node and the target node.
			*
			* @see setIsSymmetric() */
			bool getIsSymmetric() const;
			/*! Defines whether the meaning of the reference type is the same as seen from both the source
			* node and the target node. If false, the reference is asymmetric and getInverseName() returns the
			* name of the reference as seen from the target node. */
			EnumStatusCode setIsSymmetric(bool isSymmetric);

			/*! Returns the (localized) inverse name of the reference.
			*
			* @see setInverseName() */
			const ILocalizedText* getInverseName() const;
			/*! Sets the (localized) inverse name of the reference.
			*
			* The inverse name is the name of the reference as seen from the target node.
			* The inverse name is only used for non-symmetric references.
			*
			* Example: The asymmetric reference type "Uses" could define an inverse name "UsedBy". */
			EnumStatusCode setInverseName(const ILocalizedText* inverseName);
			/*! @overload */
			EnumStatusCode setInverseName(const ILocalizedText& inverseName);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			InnerLocalizedText m_InverseName;

			/*! Forbid use assignment operator */
			ReferenceType& operator=(const ReferenceType&);
			/*! Forbid use of copy constructor */
			ReferenceType(const ReferenceType&);
		};
		typedef ObjectPointer<ReferenceType> ReferenceTypePtr;
		typedef ObjectPointer<const ReferenceType> ReferenceTypeConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERREFERENCETYPE_H
