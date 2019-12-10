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

#ifndef NODETYPEDESCRIPTION_H
#define NODETYPEDESCRIPTION_H
#if TB5_QUERY

#include "INodeTypeDescription.h"
#include "ExpandedNodeId.h"
#include "IExpandedNodeId.h"
#include "InnerExpandedNodeId.h"
#include "QueryDataDescription.h"
#include "IQueryDataDescription.h"
#include "InnerQueryDataDescription.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The NodeTypeDescription data type is used by the Query services (see Client::Session::queryFirst()
	* and Client::Session::queryNext()) to describe the node types that are to be queried in the
	* server's AddressSpace. */
	class TBC_EXPORT NodeTypeDescription
		: public INodeTypeDescription
	{
	public:
		/*! Default constructor */
		NodeTypeDescription();
		/*! Constructs a copy of the given instance */
		NodeTypeDescription(const INodeTypeDescription*);
		/*! @overload */
		NodeTypeDescription(const INodeTypeDescription&);
		/*! @overload */
		NodeTypeDescription(const NodeTypeDescription&);

		/*! Destructor */
		virtual ~NodeTypeDescription();

		/*! Assigns the contents of @p cp to this instance */
		NodeTypeDescription& operator=(const INodeTypeDescription* cp);
		/*! @overload */
		NodeTypeDescription& operator=(const INodeTypeDescription& cp);
		/*! @overload */
		NodeTypeDescription& operator=(const NodeTypeDescription& cp);

		/* see INodeTypeDescription::set */
		virtual EnumStatusCode set(const INodeTypeDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const INodeTypeDescription& pSrc);

		/* see INodeTypeDescription::compare */
		virtual int compare(const INodeTypeDescription*) const;
		/*! @overload */
		virtual int compare(const INodeTypeDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeTypeDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeTypeDescription& other) const;

		/* see INodeTypeDescription::getTypeDefinitionNode */
		virtual const IExpandedNodeId* getTypeDefinitionNode() const;
		/* see INodeTypeDescription::setTypeDefinitionNode */
		virtual EnumStatusCode setTypeDefinitionNode(const IExpandedNodeId* value);
		/*! @overload */
		virtual EnumStatusCode setTypeDefinitionNode(const ExpandedNodeId& value);

		/* see INodeTypeDescription::getIncludeSubTypes */
		virtual bool getIncludeSubTypes() const;
		/* see INodeTypeDescription::setIncludeSubTypes */
		virtual void setIncludeSubTypes(const bool& value);

		/* see INodeTypeDescription::getDataToReturn */
		virtual std::vector<QueryDataDescription> getDataToReturn() const;
		/* see INodeTypeDescription::addDataToReturn */
		virtual EnumStatusCode addDataToReturn(const IQueryDataDescription* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerExpandedNodeId m_typeDefinitionNode;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerQueryDataDescription> m_pDataToReturn)

		NodeTypeDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif

#endif	// NODETYPEDESCRIPTION_H
