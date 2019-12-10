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

#ifndef INNERENDPOINTDESCRIPTION_H
#define INNERENDPOINTDESCRIPTION_H

#include "IEndpointDescription.h"
#include "ApplicationDescription.h"
#include "IApplicationDescription.h"
#include "InnerApplicationDescription.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"
#include "UserTokenPolicy.h"
#include "IUserTokenPolicy.h"
#include "InnerUserTokenPolicy.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerEndpointDescription
		: public IEndpointDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerEndpointDescription();

		/* see IEndpointDescription::getEndpointUrl */
		virtual tstring getEndpointUrl() const;

		/* see IEndpointDescription::getServer */
		virtual const IApplicationDescription* getServer() const;
		/*! @overload */
		virtual IApplicationDescription* getServer();

		/* see IEndpointDescription::getServerCertificate */
		virtual ByteString getServerCertificate() const;

		/* see IEndpointDescription::getMessageSecurityMode */
		virtual EnumMessageSecurityMode getMessageSecurityMode() const;

		/* see IEndpointDescription::getSecurityPolicy */
		virtual tstring getSecurityPolicy() const;

		/* see IEndpointDescription::getUserIdentityTokenCount */
		virtual unsigned getUserIdentityTokenCount() const;
		/* see IEndpointDescription::getUserIdentityToken */
		virtual const IUserTokenPolicy* getUserIdentityToken(unsigned index) const;
		/* see IEndpointDescription::getUserIdentityTokens */
		virtual std::vector<UserTokenPolicy> getUserIdentityTokens() const;

		/* see IEndpointDescription::getTransportProfile */
		virtual tstring getTransportProfile() const;

		/* see IEndpointDescription::getSecurityLevel */
		virtual unsigned char getSecurityLevel() const;

		/*! For internal use only */
		void initInner(EndpointDescriptionStruct* pHandle);

		virtual EnumStatusCode set(const IEndpointDescription* pSrc);
		virtual EnumStatusCode set(const IEndpointDescription& pSrc);

		virtual int compare(const IEndpointDescription* other) const;
		virtual int compare(const IEndpointDescription& other) const;

		virtual bool operator==(const IEndpointDescription& other) const;
		virtual bool operator!=(const IEndpointDescription& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerApplicationDescription m_server;
		InnerByteString m_serverCertificate;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerUserTokenPolicy> m_UserIdentityTokens)

		EndpointDescriptionStruct* m_pContent;
	};
} // end namespace

#endif
