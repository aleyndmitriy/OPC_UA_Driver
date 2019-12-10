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

#ifndef INNERNODEID_H
#define INNERNODEID_H

#include "INodeId.h"
#include "InnerValue.h"
#include "Value.h"
#include "Guid.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerNodeId
	class TBC_EXPORT InnerNodeId
		: public INodeId
	{
	public:
		/*! Destructor */
		virtual ~InnerNodeId();

		/* see INodeId::setNumeric */
		virtual EnumStatusCode setNumeric(OTUInt16 nameSpaceIndex, OTUInt32 identifier);

		/* see INodeId::setString */
		virtual EnumStatusCode setString(OTUInt16 nameSpaceIndex, const tstring& identifier);

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

		/* see INodeId::toString */
		virtual tstring toString() const;

		/* see INodeId::setGuid */
		virtual EnumStatusCode setGuid(OTUInt16 nameSpaceIndex, const IGuid* identifier);

		/* see INodeId::setOpaque */
		virtual EnumStatusCode setOpaque(OTUInt16 nameSpaceIndex, const ByteString& identifier);

		/* see INodeId::setNull */
		virtual EnumStatusCode setNull();

		/* see INodeId::isNull */
		virtual bool isNull() const;

		/*! The namespace index of the namespace the related node belongs to. */
		virtual OTUInt16 getNamespaceIndex() const;
		virtual void setNamespaceIndex(OTUInt16 value);

		/*! The identifier type of the nodeId (see enumeration type for possible values). */
		virtual EnumIdentifierType getIdentifierType() const;

		// init from otb handle
		void initInner(NodeIdStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INodeId* other) const;
		/*! @overload */
		virtual int compare(const INodeId& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeId& other) const;

		// set from interface
		EnumStatusCode set(const INodeId* pSrc);
		EnumStatusCode set(const INodeId& pSrc);

		// protected:
		// the handle to the related core object
		NodeIdStruct* m_pNodeId_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERNODEID_H
