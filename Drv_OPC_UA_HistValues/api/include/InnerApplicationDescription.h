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

#ifndef INNERAPPLICATIONDESCRIPTION_H
#define INNERAPPLICATIONDESCRIPTION_H

#include "IApplicationDescription.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerApplicationDescription
	class TBC_EXPORT InnerApplicationDescription
		: public IApplicationDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerApplicationDescription();

		/*! The global unique identifier for the application instance. */
		virtual tstring getApplicationUri() const;
		virtual void setApplicationUri(const tstring& value);

		/*! The global unique identifier for the product. */
		virtual tstring getProductUri() const;
		virtual void setProductUri(const tstring& value);

		/*! A localized descriptive name for the application. */
		virtual const ILocalizedText* getApplicationName() const;
		virtual ILocalizedText* getApplicationName();
		virtual void setApplicationName(const ILocalizedText* value);
		virtual void setApplicationName(const LocalizedText& value);

		/*! The type of the application (whether Client, Server or Both). */
		virtual EnumApplicationType getApplicationType() const;
		virtual void setApplicationType(EnumApplicationType value);

		/*! If a server can be accessed via a Gateway Server the value shall specify that. */
		virtual tstring getGatewayServerUri() const;
		virtual void setGatewayServerUri(const tstring& value);

		/*! A URI that identifies the discovery profile supported by the URLs provided.
		* The field is not used in case of client only applications.
		* If the value is not specified then the Endpoints shall support the standard DiscoveryServices. */
		virtual tstring getDiscoveryProfileUri() const;
		virtual void setDiscoveryProfileUri(const tstring& value);

		/*! These URLs belong to the Gateway Server.
		* Some Discovery Servers may return multiple records for the same Server if that Server can be accessed
		* via multiple paths. */
		virtual std::vector<tstring> getDiscoveryUrls() const;
		virtual EnumStatusCode setDiscoveryUrls(const std::vector<tstring>&);


		// init from otb handle
		void initInner(ApplicationDescriptionStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IApplicationDescription* other) const;
		/*! @overload */
		virtual int compare(const IApplicationDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IApplicationDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IApplicationDescription& other) const;

		// set from interface
		EnumStatusCode set(const IApplicationDescription* pSrc);
		EnumStatusCode set(const IApplicationDescription& pSrc);

		// protected:
		// the handle to the related core object
		ApplicationDescriptionStruct* m_pApplicationDescription_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerLocalizedText m_ApplicationName;
	};
}
#endif	// INNERAPPLICATIONDESCRIPTION_H
