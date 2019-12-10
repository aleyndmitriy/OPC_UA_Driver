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

#ifndef QUERYDATASET_H
#define QUERYDATASET_H
#if TB5_QUERY

#include "IQueryDataSet.h"
#include "ExpandedNodeId.h"
#include "IExpandedNodeId.h"
#include "InnerExpandedNodeId.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The QueryDataSet data type is used by the Query services (see Client::Session::queryFirst()
	* and Client::Session::queryNext()) to return data related to a node. The returned data matches
	* the criteria defined in the NodeTypeDescription provided with the QueryFirst service call. */
	class TBC_EXPORT QueryDataSet
		: public IQueryDataSet
	{
	public:
		/*! Default constructor */
		QueryDataSet();
		/*! Constructs a copy of the given instance */
		QueryDataSet(const IQueryDataSet*);
		/*! @overload */
		QueryDataSet(const IQueryDataSet&);
		/*! @overload */
		QueryDataSet(const QueryDataSet&);

		/*! Destructor */
		virtual ~QueryDataSet();

		/*! Assigns the contents of @p cp to this instance */
		QueryDataSet& operator=(const IQueryDataSet* cp);
		/*! @overload */
		QueryDataSet& operator=(const IQueryDataSet& cp);
		/*! @overload */
		QueryDataSet& operator=(const QueryDataSet& cp);

		/* see IQueryDataSet::set */
		virtual EnumStatusCode set(const IQueryDataSet* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IQueryDataSet& pSrc);

		/* see IQueryDataSet::compare */
		virtual int compare(const IQueryDataSet*) const;
		/*! @overload */
		virtual int compare(const IQueryDataSet&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQueryDataSet& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQueryDataSet& other) const;

		/* see IQueryDataSet::getNodeId */
		virtual const IExpandedNodeId* getNodeId() const;
		/* see IQueryDataSet::setNodeId */
		virtual EnumStatusCode setNodeId(const IExpandedNodeId* value);
		/*! @overload */
		virtual EnumStatusCode setNodeId(const ExpandedNodeId& value);

		/* see IQueryDataSet::getTypeDefinitionNode */
		virtual const IExpandedNodeId* getTypeDefinitionNode() const;
		/* see IQueryDataSet::setTypeDefinitionNode */
		virtual EnumStatusCode setTypeDefinitionNode(const IExpandedNodeId* value);
		/*! @overload */
		virtual EnumStatusCode setTypeDefinitionNode(const ExpandedNodeId& value);

		/* see IQueryDataSet::getValues */
		virtual std::vector<Value> getValues() const;
		/* see IQueryDataSet::addValue */
		virtual EnumStatusCode addValue(const IValue* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerExpandedNodeId m_nodeId;
		InnerExpandedNodeId m_typeDefinitionNode;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_pValues)

		QueryDataSetStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif	// QUERYDATASET_H
