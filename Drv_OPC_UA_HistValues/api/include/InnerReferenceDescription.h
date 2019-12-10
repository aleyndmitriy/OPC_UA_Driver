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

#ifndef INNERREFERENCEDESCRIPTION_H
#define INNERREFERENCEDESCRIPTION_H

#include "IReferenceDescription.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerReferenceDescription
	class TBC_EXPORT InnerReferenceDescription
		: public IReferenceDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerReferenceDescription();

		/*! The NodeId of the used reference type of this reference type. */
		virtual const INodeId* getReferenceTypeId() const;
		virtual INodeId* getReferenceTypeId();
		virtual void setReferenceTypeId(const INodeId* value);
		virtual void setReferenceTypeId(const NodeId& value);

		/*! Signals in case of a true, that the returned reference is pointing to the returned Node. If false, the
		* returned Node is the Source of the returned reference. */
		virtual bool getIsForward() const;
		virtual void setIsForward(bool value);

		/*! The NodeId of the related Node of this reference. */
		virtual const IExpandedNodeId* getNodeId() const;
		virtual IExpandedNodeId* getNodeId();
		virtual void setNodeId(const IExpandedNodeId* value);
		virtual void setNodeId(const ExpandedNodeId& value);

		/*! The browse name of the referenced node. */
		virtual const IQualifiedName* getBrowseName() const;
		virtual IQualifiedName* getBrowseName();
		virtual void setBrowseName(const IQualifiedName* value);
		virtual void setBrowseName(const QualifiedName& value);

		/*! The DisplayName of the related Node of this reference. */
		virtual const ILocalizedText* getDisplayName() const;
		virtual ILocalizedText* getDisplayName();
		virtual void setDisplayName(const ILocalizedText* value);
		virtual void setDisplayName(const LocalizedText& value);

		/*! The NodeClass of the related Node of this reference. */
		virtual EnumNodeClass getNodeClass() const;
		virtual void setNodeClass(EnumNodeClass value);

		/*! The NodeId of the type definition of the related Node of this reference. */
		virtual const IExpandedNodeId* getTypeDefinition() const;
		virtual IExpandedNodeId* getTypeDefinition();
		virtual void setTypeDefinition(const IExpandedNodeId* value);
		virtual void setTypeDefinition(const ExpandedNodeId& value);


		// init from otb handle
		void initInner(ReferenceDescriptionStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IReferenceDescription* other) const;
		/*! @overload */
		virtual int compare(const IReferenceDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReferenceDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReferenceDescription& other) const;

		// set from interface
		EnumStatusCode set(const IReferenceDescription* pSrc);
		EnumStatusCode set(const IReferenceDescription& pSrc);

		// protected:
		// the handle to the related core object
		ReferenceDescriptionStruct* m_pReferenceDescription_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerNodeId m_ReferenceTypeId;
		InnerExpandedNodeId m_NodeId;
		InnerQualifiedName m_BrowseName;
		InnerLocalizedText m_DisplayName;
		InnerExpandedNodeId m_TypeDefinition;
	};
}
#endif	// INNERREFERENCEDESCRIPTION_H
