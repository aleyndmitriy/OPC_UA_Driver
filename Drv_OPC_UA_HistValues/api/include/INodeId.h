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

#ifndef INODEID_H
#define INODEID_H

#include "NodeIdStruct.h"
#include "InnerValue.h"
#include "Value.h"
#include "Guid.h"

namespace SoftingOPCToolbox5
{
	/*! The NodeId data type is used to uniquely identify a node within a server's AddressSpace.
	* The NodeId is used by all OPC UA services like Read or Browse for addressing nodes in the
	* server's AddressSpace.
	*
	* A NodeId consists of the following elements:
	* @li	NamespaceIndex:		This index into the server's NamespaceArray defines the namespace of the NodeId.
	*							All identifiers are guaranteed to be unique within a namespace.
	* @li	IdentifierType:		Defines the format and data type of the identifier. OPC UA supports
	*							numeric, string, GUID and opaque (ByteString) identifiers.
	* @li	Identifier:			The actual identifier of a node.
	*
	* The NamespaceArray is a list of namespace URIs. Each URI identifies the naming authority responsible for
	* assigning the identifier element of the NodeId. A server's NamespaceArray always contains the URI
	* http://opcfoundation.org/UA/ at index 0 which is the OPC UA namespace that contains well-known NodeIds.
	*
	* The server's NamespaceArray has the well-known NodeId EnumNumericNodeId_Server_NamespaceArray and can be
	* accessed using the Read service (see Client::Session::read()).
	*
	* Server applications must ensure to provide unique NodeIds for all nodes created in the server. */
	class TBC_EXPORT INodeId
	{
	public:
		/*! Destructor */
		virtual ~INodeId(){};

		/*! Returns the index in the server's namespace table.
		*
		* @see setNamespaceIndex() */
		virtual OTUInt16 getNamespaceIndex() const = 0;
		/*! Sets the index in the server's namespace table. The NamespaceIndex identifies the
		* namespace for the identifier and indicates the naming authority that is responsible for
		* assigning the identifier. */
		virtual void setNamespaceIndex(OTUInt16 value) = 0;

		/*! Returns the identifier type of the NodeId. */
		virtual EnumIdentifierType getIdentifierType() const = 0;

		/*! Returns a variant containing the identifier of the NodeId.
		*
		* Please use the following methods to access the contained identifier:
		* @li	Value::getInt32() for accessing numeric identifiers
		* @li	Value::getString() for accessing string identifiers
		* @li	Value::getGuid() for accessing GUID identifiers
		* @li	Value::getByteString() for accessing opaque identifiers */
		virtual Value getIdentifier() const = 0;
		/*! Returns the numeric identifier of the NodeId.
		* If the identifier is not numeric, the method returns a bad status code. */
		virtual EnumStatusCode getNumericIdentifier(OTUInt32* pId) const = 0;
		/*! Returns the string identifier of the NodeId.
		* If the identifier is not a string, the method returns a bad status code. */
		virtual EnumStatusCode getStringIdentifier(tstring* pId) const = 0;
		/*! Returns the opaque identifier of the NodeId.
		* If the identifier is not opaque, the method returns a bad status code. */
		virtual EnumStatusCode getOpaqueIdentifier(ByteString* pId) const = 0;
		/*! Returns the GUID identifier of the NodeId.
		* If the identifier is not a GUID, the method returns a bad status code. */
		virtual EnumStatusCode getGuidIdentifier(Guid* pId) const = 0;

		/*! Initializes the NodeId with a numeric identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table.
		* @param identifier			The numeric identifier */
		virtual EnumStatusCode setNumeric(OTUInt16 namespaceIndex, OTUInt32 identifier) = 0;
		/*! Initializes the NodeId with a string identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table.
		* @param identifier			The string identifier */
		virtual EnumStatusCode setString(OTUInt16 namespaceIndex, const tstring& identifier) = 0;
		/*! Initializes the NodeId with a GUID identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table.
		* @param identifier			The GUID identifier */
		virtual EnumStatusCode setGuid(OTUInt16 namespaceIndex, const IGuid* identifier) = 0;
		/*! Initializes the NodeId with an opaque identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table.
		* @param identifier			The opaque identifier */
		virtual EnumStatusCode setOpaque(OTUInt16 namespaceIndex, const ByteString& identifier) = 0;

		/*! Returns whether the NodeId is the designated "null" NodeId. */
		virtual bool isNull() const = 0;
		/*! Assigns the NodeId the designated "null" NodeId. */
		virtual EnumStatusCode setNull() = 0;

		/*! Returns a string representation of the NodeId for debugging purposes */
		virtual tstring toString() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const INodeId* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const INodeId& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INodeId* other) const = 0;
		/*! @overload */
		virtual int compare(const INodeId& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeId& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeId& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end INodeId
} // end namespace
#endif	// INODEID_H
