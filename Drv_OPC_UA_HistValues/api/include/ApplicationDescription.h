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

#ifndef APPLICATIONDESCRIPTION_H
#define APPLICATIONDESCRIPTION_H

#include "IApplicationDescription.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ApplicationDescription data type is used to characterize an OPC UA application.
	* The application type (see setApplicationType()) defines whether the application
	* is a server and/or client application and is used during initialization (see Application::initialize()). */
	class TBC_EXPORT ApplicationDescription
		: public IApplicationDescription
	{
	public:
		/*! Default constructor */
		ApplicationDescription();
		/*! Constructs a copy of the given instance */
		ApplicationDescription(const IApplicationDescription*);
		/*! @overload */
		ApplicationDescription(const IApplicationDescription&);
		/*! @overload */
		ApplicationDescription(const ApplicationDescription&);

		/*! Destructor */
		virtual ~ApplicationDescription();

		/*! Assigns the contents of @p cp to this instance */
		ApplicationDescription& operator=(const IApplicationDescription* cp);
		/*! @overload */
		ApplicationDescription& operator=(const IApplicationDescription& cp);
		/*! @overload */
		ApplicationDescription& operator=(const ApplicationDescription& cp);

		/* see IApplicationDescription::set */
		virtual EnumStatusCode set(const IApplicationDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IApplicationDescription& pSrc);

		/* see IApplicationDescription::compare */
		virtual int compare(const IApplicationDescription*) const;
		/*! @overload */
		virtual int compare(const IApplicationDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IApplicationDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IApplicationDescription& other) const;

		/* see IApplicationDescription::getApplicationUri */
		virtual tstring getApplicationUri() const;
		/* see IApplicationDescription::setApplicationUri */
		virtual void setApplicationUri(const tstring& value);

		/* see IApplicationDescription::getProductUri */
		virtual tstring getProductUri() const;
		/* see IApplicationDescription::setProductUri */
		virtual void setProductUri(const tstring& value);

		/* see IApplicationDescription::getApplicationName */
		virtual const ILocalizedText* getApplicationName() const;
		/*! @overload */
		virtual ILocalizedText* getApplicationName();
		/* see IApplicationDescription::setApplicationName */
		virtual void setApplicationName(const ILocalizedText* value);
		/*! @overload */
		virtual void setApplicationName(const LocalizedText& value);

		/* see IApplicationDescription::getApplicationType */
		virtual EnumApplicationType getApplicationType() const;
		/* see IApplicationDescription::setApplicationType */
		virtual void setApplicationType(EnumApplicationType value);

		/* see IApplicationDescription::getGatewayServerUri */
		virtual tstring getGatewayServerUri() const;
		/* see IApplicationDescription::setGatewayServerUri */
		virtual void setGatewayServerUri(const tstring& value);

		/* see IApplicationDescription::getDiscoveryProfileUri */
		virtual tstring getDiscoveryProfileUri() const;
		/* see IApplicationDescription::setDiscoveryProfileUri */
		virtual void setDiscoveryProfileUri(const tstring& value);

		/* see IApplicationDescription::getDiscoveryUrls */
		virtual std::vector<tstring> getDiscoveryUrls() const;
		/* see IApplicationDescription::setDiscoveryUrls */
		virtual EnumStatusCode setDiscoveryUrls(const std::vector<tstring>&);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerLocalizedText m_ApplicationName;
		ApplicationDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// APPLICATIONDESCRIPTION_H
