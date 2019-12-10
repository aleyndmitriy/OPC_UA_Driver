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

#ifndef BROWSEDESCRIPTION_H
#define BROWSEDESCRIPTION_H

#include "IBrowseDescription.h"
#include "InnerNodeId.h"
#include "NodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BrowseDescription data type is used by the Browse service (see Client::Session::browse()) to
	* specify the node to browse and to define restrictions on browsed references. */
	class TBC_EXPORT BrowseDescription
		: public IBrowseDescription
	{
	public:
		/*! Default constructor */
		BrowseDescription();
		/*! Constructs a copy of the given instance */
		BrowseDescription(const IBrowseDescription*);
		/*! @overload */
		BrowseDescription(const IBrowseDescription&);
		/*! @overload */
		BrowseDescription(const BrowseDescription&);

		/*! Destructor */
		virtual ~BrowseDescription();

		/*! Assigns the contents of @p cp to this instance */
		BrowseDescription& operator=(const IBrowseDescription* cp);
		/*! @overload */
		BrowseDescription& operator=(const IBrowseDescription& cp);
		/*! @overload */
		BrowseDescription& operator=(const BrowseDescription& cp);

		/* see IBrowseDescription::set */
		virtual EnumStatusCode set(const IBrowseDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBrowseDescription& pSrc);

		/* see IBrowseDescription::compare */
		virtual int compare(const IBrowseDescription*) const;
		/*! @overload */
		virtual int compare(const IBrowseDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowseDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowseDescription& other) const;

		/* see IBrowseDescription::getNodeId */
		virtual const INodeId* getNodeId() const;
		/*! @overload */
		virtual INodeId* getNodeId();
		/* see IBrowseDescription::setNodeId */
		virtual void setNodeId(const INodeId* value);
		/*! @overload */
		virtual void setNodeId(const NodeId& value);

		/* see IBrowseDescription::getBrowseDirection */
		virtual EnumBrowseDirection getBrowseDirection() const;
		/* see IBrowseDescription::setBrowseDirection */
		virtual void setBrowseDirection(EnumBrowseDirection value);

		/* see IBrowseDescription::getReferenceTypeId */
		virtual const INodeId* getReferenceTypeId() const;
		/*! @overload */
		virtual INodeId* getReferenceTypeId();
		/* see IBrowseDescription::setReferenceTypeId */
		virtual void setReferenceTypeId(const INodeId* value);
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value);

		/* see IBrowseDescription::getIncludeSubtypes */
		virtual bool getIncludeSubtypes() const;
		/* see IBrowseDescription::setIncludeSubtypes */
		virtual void setIncludeSubtypes(bool value);

		/* see IBrowseDescription::getNodeClassMask */
		virtual EnumNodeClass getNodeClassMask() const;
		/* see IBrowseDescription::setNodeClassMask */
		virtual void setNodeClassMask(EnumNodeClass value);

		/* see IBrowseDescription::getResultMask */
		virtual EnumResultMask getResultMask() const;
		/* see IBrowseDescription::setResultMask */
		virtual void setResultMask(EnumResultMask value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_NodeId;
		InnerNodeId m_ReferenceTypeId;

		BrowseDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BROWSEDESCRIPTION_H
