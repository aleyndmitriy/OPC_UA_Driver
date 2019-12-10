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

#ifndef EXPANDEDNODEID_H
#define EXPANDEDNODEID_H

#include "IExpandedNodeId.h"
#include "NodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ExpandedNodeId data type extends the NodeId data type by elements that allow addressing across server borders.
	* ExpandedNodeIds allow the namespace to be specified explicitly as a string or with an index in the server's
	* namespace table. */
	class TBC_EXPORT ExpandedNodeId
		: public IExpandedNodeId
	{
	public:
		/*! Default constructor */
		ExpandedNodeId();
		/*! Constructs an ExpandedNodeId with a numeric identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table
		* @param identifier			The numeric identifier */
		ExpandedNodeId(OTUInt16 namespaceIndex, OTUInt32 identifier);
		/*! Constructs an ExpandedNodeId with a string identifier.
		*
		* @param namespaceIndex		The index in the server's namespace table
		* @param identifier			The string identifier */
		ExpandedNodeId(OTUInt16 namespaceIndex, const tstring& identifier);
		/*! Constructs a copy of the given instance */
		ExpandedNodeId(const IExpandedNodeId*);
		/*! @overload */
		ExpandedNodeId(const IExpandedNodeId&);
		/*! @overload */
		ExpandedNodeId(const ExpandedNodeId&);
		/*! @overload */
		ExpandedNodeId(const INodeId*);
		/*! @overload */
		ExpandedNodeId(const INodeId&);

		/*! Destructor */
		virtual ~ExpandedNodeId();

		/*! Assigns the contents of @p cp to this instance */
		ExpandedNodeId& operator=(const IExpandedNodeId*);
		/*! @overload */
		ExpandedNodeId& operator=(const IExpandedNodeId&);
		/*! @overload */
		ExpandedNodeId& operator=(const ExpandedNodeId&);

		/* see IExpandedNodeId::set */
		virtual EnumStatusCode set(const IExpandedNodeId* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IExpandedNodeId& pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const INodeId* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const INodeId& pSrc);

		/* see IExpandedNodeId::compare */
		virtual int compare(const IExpandedNodeId*) const;
		/*! @overload */
		virtual int compare(const IExpandedNodeId&) const;
		/*! @overload */
		virtual int compare(const INodeId* other) const;
		/*! @overload */
		virtual int compare(const INodeId& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IExpandedNodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IExpandedNodeId& other) const;
		/*! Compares two instances for equality */
		virtual bool operator==(const INodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeId& other) const;

		/* see IExpandedNodeId::getServerIndex */
		virtual OTUInt32 getServerIndex() const;
		/* see IExpandedNodeId::setServerIndex */
		virtual void setServerIndex(OTUInt32 value);

		/* see IExpandedNodeId::getNamespaceUri */
		virtual tstring getNamespaceUri() const;
		/* see IExpandedNodeId::setNamespaceUri */
		virtual void setNamespaceUri(const tstring& value);

		/* see IExpandedNodeId::getNamespaceIndex */
		virtual OTUInt16 getNamespaceIndex() const;
		/* see IExpandedNodeId::setNamespaceIndex */
		virtual void setNamespaceIndex(OTUInt16 value);

		/* see IExpandedNodeId::getIdentifierType */
		virtual EnumIdentifierType getIdentifierType() const;

		/* see IExpandedNodeId::getIdentifier */
		virtual Value getIdentifier() const;
		/* see INodeId::getNumericIdentifier */
		virtual EnumStatusCode getNumericIdentifier(OTUInt32* pId) const;
		/* see INodeId::getStringIdentifier */
		virtual EnumStatusCode getStringIdentifier(tstring* pId) const;
		/* see INodeId::getGuidIdentifier */
		virtual EnumStatusCode getGuidIdentifier(Guid* pId) const;
		/* see INodeId::getOpaqueIdentifier */
		virtual EnumStatusCode getOpaqueIdentifier(ByteString* pId) const;

		/* see IExpandedNodeId::setNumeric */
		virtual EnumStatusCode setNumeric(OTUInt16 namespaceIndex, OTUInt32 identifier);
		/* see IExpandedNodeId::setString */
		virtual EnumStatusCode setString(OTUInt16 namespaceIndex, const tstring& identifier);
		/* see IExpandedNodeId::setGuid */
		virtual EnumStatusCode setGuid(OTUInt16 namespaceIndex, const IGuid* identifier);
		/* see IExpandedNodeId::setOpaque */
		virtual EnumStatusCode setOpaque(OTUInt16 namespaceIndex, const ByteString& identifier);

		/* see IExpandedNodeId::isNull */
		virtual bool isNull() const;
		/* see IExpandedNodeId::setNull */
		virtual EnumStatusCode setNull();

		/* see IExpandedNodeId::getNodeId */
		virtual NodeId getNodeId() const;

		/* see IExpandedNodeId::toString */
		virtual tstring toString() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId nodeId;
		ExpandedNodeIdStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// EXPANDEDNODEID_H
