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

#ifndef ENUMDESCRIPTION_H
#define ENUMDESCRIPTION_H

#include "IEnumDescription.h"
#include "EnumDefinition.h"
#include "IEnumDefinition.h"
#include "InnerEnumDefinition.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EnumDescription data type provides the concrete DataTypeDescription for Enumeration DataTypes. */
	class TBC_EXPORT EnumDescription
		: public IEnumDescription
	{
	public:
		/*! Default constructor */
		EnumDescription();
		/*! Constructs a copy of the given instance @p cp */
		EnumDescription(const IEnumDescription* cp);
		/*! @overload */
		EnumDescription(const IEnumDescription& cp);
		/*! @overload */
		EnumDescription(const EnumDescription& cp);

		/*! Destructor */
		virtual ~EnumDescription();

		/*! Assigns the contents of @p cp to this instance */
		EnumDescription& operator=(const IEnumDescription* cp);
		/*! @overload */
		EnumDescription& operator=(const IEnumDescription& cp);
		/*! @overload */
		EnumDescription& operator=(const EnumDescription& cp);

		/* see IEnumDescription::compare */
		virtual int compare(const IEnumDescription* other) const;
		/*! @overload */
		virtual int compare(const IEnumDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEnumDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEnumDescription& other) const;

		/* see IEnumDescription::set */
		virtual EnumStatusCode set(const IEnumDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEnumDescription& pSrc);

		/* see IEnumDescription::setEnumDefinition */
		virtual EnumStatusCode setEnumDefinition(const IEnumDefinition* enumDefinition);
		/*! @overload */
		virtual EnumStatusCode setEnumDefinition(const EnumDefinition& enumDefinition);
		/* see IEnumDescription::getEnumDefinition */
		virtual const IEnumDefinition* getEnumDefinition() const;

		/* see IEnumDescription::setBuiltInType */
		virtual void setBuiltInType(const OTUInt8& builtInType);
		/* see IEnumDescription::getBuiltInType */
		virtual OTUInt8 getBuiltInType() const;

		/* see IEnumDescription::setDataTypeId */
		virtual EnumStatusCode setDataTypeId(const INodeId* dataTypeId);
		/*! @overload */
		virtual EnumStatusCode setDataTypeId(const NodeId& dataTypeId);
		/* see IEnumDescription::getDataTypeId */
		virtual const INodeId* getDataTypeId() const;

		/* see IEnumDescription::setName */
		virtual EnumStatusCode setName(const IQualifiedName* name);
		/*! @overload */
		virtual EnumStatusCode setName(const QualifiedName& name);
		/* see IEnumDescription::getName */
		virtual const IQualifiedName* getName() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerEnumDefinition m_enumDefinition;
		InnerNodeId m_dataTypeId;
		InnerQualifiedName m_name;

		EnumDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
