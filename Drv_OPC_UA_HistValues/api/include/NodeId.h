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

#ifndef NODEID_H
#define NODEID_H

#include "INodeId.h"
#include "InnerValue.h"
#include "Value.h"
#include "Guid.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

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
	class TBC_EXPORT NodeId
		: public INodeId
	{
	public:
		/*! Default constructor */
		NodeId();
		/*! Constructs a well-known NodeId in the OPC UA namespace (NamespaceIndex 0). */
		NodeId(EnumNumericNodeId id);
		/*! Constructs a NodeId with a numeric identifier.
		*
		* @param namespaceIndex		The index in the server's NamespaceTable
		* @param identifier			The numeric identifier */
		NodeId(OTUInt16 namespaceIndex, OTUInt32 identifier);
		/*! Constructs a NodeId with a string identifier.
		*
		* @param namespaceIndex		The index in the server's NamespaceTable
		* @param identifier			The string identifier */
		NodeId(OTUInt16 namespaceIndex, const tstring& identifier);
		/*! Constructs a copy of the given instance */
		NodeId(const INodeId*);
		/*! @overload */
		NodeId(const INodeId&);
		/*! @overload */
		NodeId(const NodeId&);

		/*! Destructor */
		virtual ~NodeId();

		/*! Assigns the contents of @p cp to this instance */
		NodeId& operator=(const INodeId* cp);
		/*! @overload */
		NodeId& operator=(const INodeId& cp);
		/*! @overload */
		NodeId& operator=(const NodeId& cp);

		/*! Less than operator */
		bool operator<(const NodeId& other) const;
		/*! Greater than operator */
		bool operator>(const NodeId& other) const;

		/* see INodeId::set */
		virtual EnumStatusCode set(const INodeId* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const INodeId& pSrc);

		/* see INodeId::compare */
		virtual int compare(const INodeId*) const;
		/*! @overload */
		virtual int compare(const INodeId&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeId& other) const;

		/* see INodeId::getNamespaceIndex */
		virtual OTUInt16 getNamespaceIndex() const;
		/* see INodeId::setNamespaceIndex */
		virtual void setNamespaceIndex(OTUInt16 value);

		/* see INodeId::getIdentifierType */
		virtual EnumIdentifierType getIdentifierType() const;

		/* see INodeId::getIdentifier */
		virtual Value getIdentifier() const;
		/* see INodeId::getNumericIdentifier */
		virtual EnumStatusCode getNumericIdentifier(OTUInt32* pId) const;
		/* see INodeId::getStringIdentifier */
		virtual EnumStatusCode getStringIdentifier(tstring* pId) const;
		/* see INodeId::getOpaqueIdentifier */
		virtual EnumStatusCode getOpaqueIdentifier(ByteString* pId) const;
		/* see INodeId::getGuidIdentifier */
		virtual EnumStatusCode getGuidIdentifier(Guid* pId) const;

		/* see INodeId::setNumeric */
		virtual EnumStatusCode setNumeric(OTUInt16 namespaceIndex, OTUInt32 identifier);
		/* see INodeId::setString */
		virtual EnumStatusCode setString(OTUInt16 namespaceIndex, const tstring& identifier);
		/* see INodeId::setOpaque */
		virtual EnumStatusCode setOpaque(OTUInt16 namespaceIndex, const ByteString& identifier);
		/*! @overload */
		virtual EnumStatusCode setOpaque(OTUInt16 namespaceIndex, const IByteString* identifier);
		/* see INodeId::setGuid */
		virtual EnumStatusCode setGuid(OTUInt16 namespaceIndex, const IGuid* identifier);

		/* see INodeId::isNull */
		virtual bool isNull() const;
		/* see INodeId::setNull */
		virtual EnumStatusCode setNull();

		/* see INodeId::toString */
		virtual tstring toString() const;

		/*! Parses the given string and constructs a NodeId from it.
		*
		* The string must conform to the following syntax: "ns=<namespaceIndex>;<type>=<value>"
		* @li namespaceIndex:		The NamespaceIndex formatted as a base 10 number. If the index is 0 then the entire 'ns=0;' clause shall be omitted.
		* @li type:					A flag that specifies the identifier type ("n": numeric, "s": string, "g": GUID, "b": opaque)
		* @li value:				The identifier encoded as string. For identifiers of type GUID, the actual value must be enclosed
		*							by curly braces (e.g. "{09087e75-8e5e-499b-954f-f2a9603db28a}").
		* In case of an error, a null NodeId is returned.
		*
		* Examples:
		* @li i=13
		* @li ns=10;i=-1
		* @li ns=10;s=Hello:World
		* @li ns=1;g={09087e75-8e5e-499b-954f-f2a9603db28a}
		*
		* @note Opaque NodeIds have an identifier which is - according to specification - a string encoded by Base64 encoding (e.g. "ns=1;b=M/RbKBsRVkePCePcx24oRA==").
		*		This parse method however expects a "hex-dump" encoded string, where each byte is encoded as two characters [0-9,A-F] (e.g. "ns=1;b=0D16FADC") */
		static NodeId parse(const tstring& identifier);
		/*! @overload */
		static EnumStatusCode parse(const tstring& identifier, INodeId* pNodeId);

		/*! Returns whether two NodeId instances are equal.
		* If this method is applied to two instances @p nodeId1 and @p nodeId2, the result
		* is equivalent to nodeId1.compare(nodeId2) == 0. */
		static bool areEqual(const NodeId& nodeId1, const NodeId& nodeId2);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		NodeIdStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// NODEID_H
