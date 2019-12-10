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

#ifndef SIMPLETYPEDESCRIPTION_H
#define SIMPLETYPEDESCRIPTION_H

#include "ISimpleTypeDescription.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SimpleTypeDescription data type provides the information for DataTypes derived from built-in DataTypes. */
	class TBC_EXPORT SimpleTypeDescription
		: public ISimpleTypeDescription
	{
	public:
		/*! Default constructor */
		SimpleTypeDescription();
		/*! Constructs a copy of the given instance @p cp */
		SimpleTypeDescription(const ISimpleTypeDescription* cp);
		/*! @overload */
		SimpleTypeDescription(const ISimpleTypeDescription& cp);
		/*! @overload */
		SimpleTypeDescription(const SimpleTypeDescription& cp);

		/*! Destructor */
		virtual ~SimpleTypeDescription();

		/*! Assigns the contents of @p cp to this instance */
		SimpleTypeDescription& operator=(const ISimpleTypeDescription* cp);
		/*! @overload */
		SimpleTypeDescription& operator=(const ISimpleTypeDescription& cp);
		/*! @overload */
		SimpleTypeDescription& operator=(const SimpleTypeDescription& cp);

		/*! @see ISimpleTypeDescription::compare(ISimpleTypeDescription*) */
		virtual int compare(const ISimpleTypeDescription* other) const;
		/*! @overload */
		virtual int compare(const ISimpleTypeDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISimpleTypeDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISimpleTypeDescription& other) const;

		/*! @see ISimpleTypeDescription::set(ISimpleTypeDescription*) */
		virtual EnumStatusCode set(const ISimpleTypeDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISimpleTypeDescription& pSrc);

		/*! Gets the BaseDataType member of the class */
		virtual const INodeId* getBaseDataType() const;
		/*! Sets the BaseDataType member in the class */
		virtual EnumStatusCode setBaseDataType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& value);

		/*! Gets the BuiltInType member of the class */
		virtual OTUInt8 getBuiltInType() const;
		/*! Sets the BuiltInType member in the class */
		virtual void setBuiltInType(const OTUInt8& value);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNodeId m_baseDataType;

		SimpleTypeDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
