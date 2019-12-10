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

#ifndef INNEREXPANDEDNODEID_H
#define INNEREXPANDEDNODEID_H

#include "IExpandedNodeId.h"
#include "NodeId.h"
#include "InnerNodeId.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerExpandedNodeId
	class TBC_EXPORT InnerExpandedNodeId
		: public IExpandedNodeId
	{
	public:
		/*! Destructor */
		virtual ~InnerExpandedNodeId();

		/* see IExpandedNodeId::getNodeId */
		virtual NodeId getNodeId() const;

		/* see IExpandedNodeId::setNumeric */
		virtual EnumStatusCode setNumeric(OTUInt16 nameSpaceIndex, OTUInt32 identifier);

		/* see IExpandedNodeId::setString */
		virtual EnumStatusCode setString(OTUInt16 nameSpaceIndex, const tstring& identifier);

		/* see IExpandedNodeId::getIdentifier */
		virtual Value getIdentifier() const;

		/* see INodeId::getNumericIdentifier */
		virtual EnumStatusCode getNumericIdentifier(OTUInt32* pId) const;

		/* see INodeId::getStringIdentifier */
		virtual EnumStatusCode getStringIdentifier(tstring* pId) const;

		/* see INodeId::getOpaqueIdentifier */
		virtual EnumStatusCode getOpaqueIdentifier(ByteString* pId) const;

		/* see INodeId::getGuidIdentifier */
		virtual EnumStatusCode getGuidIdentifier(Guid* pId) const;

		/* see IExpandedNodeId::toString */
		virtual tstring toString() const;

		/* see IExpandedNodeId::setGuid */
		virtual EnumStatusCode setGuid(OTUInt16 nameSpaceIndex, const IGuid* identifier);

		/* see IExpandedNodeId::setOpaque */
		virtual EnumStatusCode setOpaque(OTUInt16 nameSpaceIndex, const ByteString& identifier);

		/* see IExpandedNodeId::setNull */
		virtual EnumStatusCode setNull();

		/* see IExpandedNodeId::isNull */
		virtual bool isNull() const;

		/*! The URI of the namespace. If this parameter is specified then the namespace index is ignored. */
		virtual tstring getNamespaceUri() const;
		virtual void setNamespaceUri(const tstring& value);

		/*! Index that identifies the Server that contains the TargetNode. This Server may
		* be the local Server or a remote Server.
		* This index is the index of that Server in the local Server's Server table. The index of the local Server
		* in the Server table is always 0. All remote Servers have
		* indexes greater than 0. The Server table is contained in the Server Object in the AddressSpace. */
		virtual OTUInt32 getServerIndex() const;
		virtual void setServerIndex(OTUInt32 value);

		/*! The namespace index of the namespace the related node belongs to. */
		virtual OTUInt16 getNamespaceIndex() const;
		virtual void setNamespaceIndex(OTUInt16 value);

		/*! The identifier type of the nodeId (see enumeration type for possible values). */
		virtual EnumIdentifierType getIdentifierType() const;

		// init from otb handle
		void initInner(ExpandedNodeIdStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INodeId* other) const;
		/*! @overload */
		virtual int compare(const INodeId& other) const;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IExpandedNodeId* other) const;
		/*! @overload */
		virtual int compare(const IExpandedNodeId& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeId& other) const;
		/*! Compares two instances for equality */
		virtual bool operator==(const IExpandedNodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IExpandedNodeId& other) const;

		// set from interface
		EnumStatusCode set(const IExpandedNodeId* pSrc);
		EnumStatusCode set(const IExpandedNodeId& pSrc);

		EnumStatusCode set(const INodeId* pSrc);
		EnumStatusCode set(const INodeId& pSrc);


		// protected:
		// the handle to the related core object
		ExpandedNodeIdStruct* m_pExpandedNodeId_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNEREXPANDEDNODEID_H
