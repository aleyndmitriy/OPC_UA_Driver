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

#ifndef IEXPANDEDNODEID_H
#define IEXPANDEDNODEID_H

#include "ExpandedNodeIdStruct.h"
#include "INodeId.h"
#include "NodeId.h"
#include "InnerNodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The ExpandedNodeId data type extends the NodeId data type by elements that allow addressing across server borders.
	* ExpandedNodeIds allow the namespace to be specified explicitly as a string or with an index in the server's
	* namespace table. */
	class TBC_EXPORT IExpandedNodeId
		: public INodeId
	{
	public:
		/*! Destructor */
		virtual ~IExpandedNodeId(){};

		/*! Returns the index that identifies the server that contains the target node.
		* This server may be the local server or a remote server.
		*
		* This index is the index of that server in the local server's server table. The index of the
		* local server in the server table is always 0. All remote servers have indexes greater than 0.
		* The server table is contained in the well-known "Server" object in the AddressSpace. */
		virtual OTUInt32 getServerIndex() const = 0;
		/*! Returns the index that identifies the server that contains the target node.
		*
		* @see getServerIndex() */
		virtual void setServerIndex(OTUInt32 value) = 0;

		/*! Returns the URI of the namespace. If this parameter is specified then the
		* namespace index is ignored. */
		virtual tstring getNamespaceUri() const = 0;
		/*! Sets the URI of the namespace. If this parameter is specified then the
		* namespace index is ignored. */
		virtual void setNamespaceUri(const tstring& value) = 0;

		/*! Returns the index in the server's namespace table. This parameter shall be 0 and is
		* ignored in the server if the namespace URI is specified. */
		virtual OTUInt16 getNamespaceIndex() const = 0;
		/*! Sets the index in the server's namespace table. This parameter shall be 0 and is
		* ignored in the server if the namespace URI is specified. */
		virtual void setNamespaceIndex(OTUInt16 value) = 0;

		/*! Returns the identifier type of the NodeId (see EnumIdentifierType). */
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

		/*! Initializes the ExpandedNodeId with a numeric identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table. This parameter shall be 0
		*							and is ignored in the server if the NamespaceUri is specified.
		* @param identifier			The numeric identifier */
		virtual EnumStatusCode setNumeric(OTUInt16 namespaceIndex, OTUInt32 identifier) = 0;
		/*! Initializes the ExpandedNodeId with a string identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table. This parameter shall be 0
		*							and is ignored in the server if the NamespaceUri is specified.
		* @param identifier			The string identifier */
		virtual EnumStatusCode setString(OTUInt16 namespaceIndex, const tstring& identifier) = 0;
		/*! Initializes the ExpandedNodeId with a GUID identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table. This parameter shall be 0
		*							and is ignored in the server if the NamespaceUri is specified.
		* @param identifier			The GUID identifier */
		virtual EnumStatusCode setGuid(OTUInt16 namespaceIndex, const IGuid* identifier) = 0;
		/*! Initializes the ExpandedNodeId with an opaque identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table. This parameter shall be 0
		*							and is ignored in the server if the NamespaceUri is specified.
		* @param identifier			The opaque identifier */
		virtual EnumStatusCode setOpaque(OTUInt16 namespaceIndex, const ByteString& identifier) = 0;

		/*! Returns whether the NodeId component of the ExpandedNodeId is the designated */
		virtual bool isNull() const = 0;
				/*! Sets the NodeId (namespace index, identifier) component of the ExpandedNodeId to the
		* designated "null" NodeId. */
		virtual EnumStatusCode setNull() = 0;

		/*! Returns the NodeId component of the ExpandedNodeId.
		* The result of this method is only defined if the NamespaceIndex (and not the NamespaceUri) is specified. */
		virtual NodeId getNodeId() const = 0;

		/*! Returns a string representation of the ExpandedNodeId for debugging purposes */
		virtual tstring toString() const = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IExpandedNodeId* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const INodeId*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IExpandedNodeId& cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const INodeId&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IExpandedNodeId* other) const = 0;
		/*! @overload */
		virtual int compare(const INodeId* other) const = 0;
		/*! @overload */
		virtual int compare(const IExpandedNodeId& other) const = 0;
		/*! @overload */
		virtual int compare(const INodeId& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IExpandedNodeId& other) const = 0;
		/*! @overload */
		virtual bool operator==(const INodeId& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IExpandedNodeId& other) const = 0;
		/*! @overload */
		virtual bool operator!=(const INodeId& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IExpandedNodeId
} // end namespace
#endif	// IEXPANDEDNODEID_H
