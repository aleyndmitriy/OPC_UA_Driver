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

#ifndef SERVEROBJECTTYPE_H
#define SERVEROBJECTTYPE_H
#include "Base.h"
#include "Enums.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The ObjectType class is used to define an ObjectType node in the address space of a server.
		*
		* An ObjectType provides definitions for an Object in the address space, i.e. it defines a
		* blueprint for objects (instances of the ObjectType). Clients use the ObjectType to learn
		* about the references, components, and properties that an Object instance provides.
		*
		* All object types finally derive from the object type "BaseObjectType".
		*
		* Example: The ObjectType "FolderType" is a well-known object type that a server may use
		* to organize information (e.g. variables and/or objects).
		*
		* @note Each Object must be assigned to an ObjectType using BaseNode::init(). */
		class TBC_EXPORT ObjectType
			: public BaseNode
		{
		public:
			/*! Constructs a new ObjectType instance */
			static ObjectPointer<ObjectType> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ObjectType(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ObjectType();
			/*! For internal use only */
			ObjectType(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ObjectType();

			/*! Returns the base type of this object type. If there is no base type, a NULL pointer is returned. */
			ObjectPointer<Server::ObjectType> getBaseType();
			/*! @overload */
			ObjectPointer<const Server::ObjectType> getBaseType() const;

			/*! If true, indicates that objects of this type may NOT be exposed in the address space of the server. */
			bool getIsAbstract() const;
			/*! Indicates whether objects of this type may be exposed in the address space of the server.
			* If the object type is abstract, an object of this type must not be exposed in the address space.
			* However, the object type may still be used as event type in event notifications (see EventNotification). */
			EnumStatusCode setIsAbstract(bool isAbstract);

		private:
			/*! Forbid use assignment operator */
			ObjectType& operator=(const ObjectType&);
			/*! Forbid use of copy constructor */
			ObjectType(const ObjectType&);
		};
		typedef ObjectPointer<ObjectType> ObjectTypePtr;
		typedef ObjectPointer<const ObjectType> ObjectTypeConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVEROBJECTTYPE_H
