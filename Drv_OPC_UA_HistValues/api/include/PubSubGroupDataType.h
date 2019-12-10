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

#ifndef PUBSUBGROUPDATATYPE_H
#define PUBSUBGROUPDATATYPE_H

#include "IPubSubGroupDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "InnerEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The PubSubGroupDataType is an abstract base type to store configuration data of a PubSub::Group.
	*
	* Concrete subclasses are WriterGroupDataType and ReaderGroupDataType, which are used e.g. in
	* @li structure class PubSubConnectionDataType
	* @li UA method AddWriterGroup
	*
	* @note For additional information on the members see also PubSub::Group */
	class TBC_EXPORT PubSubGroupDataType
		: public IPubSubGroupDataType
	{
	public:
		/*! Default constructor */
		PubSubGroupDataType();
		/*! Constructs a copy of the given instance @p cp */
		PubSubGroupDataType(const IPubSubGroupDataType* cp);
		/*! @overload */
		PubSubGroupDataType(const IPubSubGroupDataType& cp);
		/*! @overload */
		PubSubGroupDataType(const PubSubGroupDataType& cp);

		/*! Destructor */
		virtual ~PubSubGroupDataType();

		/*! Assigns the contents of @p cp to this instance */
		PubSubGroupDataType& operator=(const IPubSubGroupDataType* cp);
		/*! @overload */
		PubSubGroupDataType& operator=(const IPubSubGroupDataType& cp);
		/*! @overload */
		PubSubGroupDataType& operator=(const PubSubGroupDataType& cp);

		/* see IPubSubGroupDataType::compare(IPubSubGroupDataType*) */
		virtual int compare(const IPubSubGroupDataType* other) const;
		/*! @overload */
		virtual int compare(const IPubSubGroupDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubGroupDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubGroupDataType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPubSubGroupDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubGroupDataType& pSrc);

		/* see IPubSubGroupDataType::setName */
		virtual void setName(const tstring& name);
		/* see IPubSubGroupDataType::setName */
		virtual tstring getName() const;

		/* see IPubSubGroupDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IPubSubGroupDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/* see IPubSubGroupDataType::setSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode);
		/* see IPubSubGroupDataType::getSecurityMode */
		virtual EnumMessageSecurityMode getSecurityMode() const;

		/* see IPubSubGroupDataType::setSecurityGroupId */
		virtual void setSecurityGroupId(const tstring& securityGroupId);
		/* see IPubSubGroupDataType::getSecurityGroupId */
		virtual tstring getSecurityGroupId() const;

		/* see IPubSubGroupDataType::addSecurityKeyService */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService);
		/* see IPubSubGroupDataType::getSecurityKeyServices */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const;

		/* see IPubSubGroupDataType::setMaxNetworkMessageSize */
		virtual void setMaxNetworkMessageSize(const OTUInt32& maxNetworkMessageSize);
		/* see IPubSubGroupDataType::getMaxNetworkMessageSize */
		virtual OTUInt32 getMaxNetworkMessageSize() const;

		/* see IPubSubGroupDataType::addGroupProperty */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty);
		/* see IPubSubGroupDataType::getGroupProperties */
		virtual std::vector<KeyValuePair> getGroupProperties() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pGroupProperties)

		PubSubGroupDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
