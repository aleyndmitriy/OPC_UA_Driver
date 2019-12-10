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

#ifndef REFERENCEDESCRIPTION_H
#define REFERENCEDESCRIPTION_H

#include "IReferenceDescription.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ReferenceDescription data type is used by the Browse service (see Client::Session::browse())
	* to return the description of a reference from one node to another that was encountered during browse. */
	class TBC_EXPORT ReferenceDescription
		: public IReferenceDescription
	{
	public:
		/*! Default constructor */
		ReferenceDescription();
		/*! Constructs a copy of the given instance */
		ReferenceDescription(const IReferenceDescription*);
		/*! @overload */
		ReferenceDescription(const IReferenceDescription&);
		/*! @overload */
		ReferenceDescription(const ReferenceDescription&);

		/*! Destructor */
		virtual ~ReferenceDescription();

		/*! Assigns the contents of @p cp to this instance */
		ReferenceDescription& operator=(const IReferenceDescription* cp);
		/*! @overload */
		ReferenceDescription& operator=(const IReferenceDescription& cp);
		/*! @overload */
		ReferenceDescription& operator=(const ReferenceDescription& cp);

		/* see IReferenceDescription::set */
		virtual EnumStatusCode set(const IReferenceDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IReferenceDescription& pSrc);

		/* see IReferenceDescription::compare */
		virtual int compare(const IReferenceDescription*) const;
		/*! @overload */
		virtual int compare(const IReferenceDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReferenceDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReferenceDescription& other) const;

		/* see IReferenceDescription::getReferenceTypeId */
		virtual const INodeId* getReferenceTypeId() const;
		/*! @overload */
		virtual INodeId* getReferenceTypeId();
		/* see IReferenceDescription::setReferenceTypeId */
		virtual void setReferenceTypeId(const INodeId* value);
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value);

		/* see IReferenceDescription::getIsForward */
		virtual bool getIsForward() const;
		/* see IReferenceDescription::setIsForward */
		virtual void setIsForward(bool value);

		/* see IReferenceDescription::getNodeId */
		virtual const IExpandedNodeId* getNodeId() const;
		/*! @overload */
		virtual IExpandedNodeId* getNodeId();
		/* see IReferenceDescription::setNodeId */
		virtual void setNodeId(const IExpandedNodeId* value);
		/*! @overload */
		virtual void setNodeId(const ExpandedNodeId& value);

		/* see IReferenceDescription::getBrowseName */
		virtual const IQualifiedName* getBrowseName() const;
		/*! @overload */
		virtual IQualifiedName* getBrowseName();
		/* see IReferenceDescription::setBrowseName */
		virtual void setBrowseName(const IQualifiedName* value);
		/*! @overload */
		virtual void setBrowseName(const QualifiedName& value);

		/* see IReferenceDescription::getDisplayName */
		virtual const ILocalizedText* getDisplayName() const;
		/*! @overload */
		virtual ILocalizedText* getDisplayName();
		/* see IReferenceDescription::setDisplayName */
		virtual void setDisplayName(const ILocalizedText* value);
		/*! @overload */
		virtual void setDisplayName(const LocalizedText& value);

		/* see IReferenceDescription::getNodeClass */
		virtual EnumNodeClass getNodeClass() const;
		/* see IReferenceDescription::setNodeClass */
		virtual void setNodeClass(EnumNodeClass value);

		/* see IReferenceDescription::getTypeDefinition */
		virtual const IExpandedNodeId* getTypeDefinition() const;
		/*! @overload */
		virtual IExpandedNodeId* getTypeDefinition();
		/* see IReferenceDescription::setTypeDefinition */
		virtual void setTypeDefinition(const IExpandedNodeId* value);
		/*! @overload */
		virtual void setTypeDefinition(const ExpandedNodeId& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_ReferenceTypeId;
		InnerExpandedNodeId m_NodeId;
		InnerQualifiedName m_BrowseName;
		InnerLocalizedText m_DisplayName;
		InnerExpandedNodeId m_TypeDefinition;

		ReferenceDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// REFERENCEDESCRIPTION_H
