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

#ifndef READVALUEID_H
#define READVALUEID_H

#include "IReadValueId.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ReadValueId data type is used by the Read service (see Client::Session::read())
	* to specify the items to read. */
	class TBC_EXPORT ReadValueId
		: public IReadValueId
	{
	public:
		/*! Default constructor */
		ReadValueId();
		/*! Constructs a ReadValueId for a node identified by the given
		* @p nodeId and @p attributeId.
		*
		* @param nodeId			The NodeId of the node to read
		* @param attributeId	The attribute of the node to read */
		ReadValueId(const NodeId& nodeId, EnumAttributeId attributeId);
		/*! Constructs a copy of the given instance */
		ReadValueId(const IReadValueId*);
		/*! @overload */
		ReadValueId(const IReadValueId&);
		/*! @overload */
		ReadValueId(const ReadValueId&);

		/*! Destructor */
		virtual ~ReadValueId();

		/*! Assigns the contents of @p cp to this instance */
		ReadValueId& operator=(const IReadValueId*);
		/*! @overload */
		ReadValueId& operator=(const IReadValueId&);
		/*! @overload */
		ReadValueId& operator=(const ReadValueId&);

		/* see IReadValueId::set */
		virtual EnumStatusCode set(const IReadValueId* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IReadValueId& pSrc);

		/* see IReadValueId::compare */
		virtual int compare(const IReadValueId*) const;
		/*! @overload */
		virtual int compare(const IReadValueId&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReadValueId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReadValueId& other) const;

		/* see IReadValueId::getNodeId */
		virtual const INodeId* getNodeId() const;
		/*! @overload */
		virtual INodeId* getNodeId();
		/* see IReadValueId::setNodeId */
		virtual void setNodeId(const INodeId* value);
		/*! @overload */
		virtual void setNodeId(const NodeId& value);

		/* see IReadValueId::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;
		/* see IReadValueId::setAttributeId */
		virtual void setAttributeId(EnumAttributeId value);

		/* see IReadValueId::getIndexRange */
		virtual const INumericRange* getIndexRange() const;
		/* see IReadValueId::setIndexRange */
		virtual void setIndexRange(const INumericRange* value);
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_NodeId;
		InnerNumericRange m_IndexRange;

		ReadValueIdStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// READVALUEID_H
