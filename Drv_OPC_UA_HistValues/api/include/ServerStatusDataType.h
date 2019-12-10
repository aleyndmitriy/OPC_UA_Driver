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

#ifndef SERVERSTATUSDATATYPE_H
#define SERVERSTATUSDATATYPE_H

#include "IServerStatusDataType.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "InnerDateTime.h"
#include "BuildInfo.h"
#include "IBuildInfo.h"
#include "InnerBuildInfo.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ServerStatusDataType is used to describe the status of the server. */
	class TBC_EXPORT ServerStatusDataType
		: public IServerStatusDataType
	{
	public:
		/*! Default constructor */
		ServerStatusDataType();
		/*! Constructs a copy of the given instance @p cp */
		ServerStatusDataType(const IServerStatusDataType* cp);
		/*! @overload */
		ServerStatusDataType(const IServerStatusDataType& cp);
		/*! @overload */
		ServerStatusDataType(const ServerStatusDataType& cp);

		/*! Destructor */
		virtual ~ServerStatusDataType();

		/*! Assigns the contents of @p cp to this instance */
		ServerStatusDataType& operator=(const IServerStatusDataType* cp);
		/*! @overload */
		ServerStatusDataType& operator=(const IServerStatusDataType& cp);
		/*! @overload */
		ServerStatusDataType& operator=(const ServerStatusDataType& cp);

		/* see IServerStatusDataType::set */
		virtual EnumStatusCode set(const IServerStatusDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IServerStatusDataType& pSrc);

		/* see IServerStatusDataType::compare */
		virtual int compare(const IServerStatusDataType* other) const;
		/*! @overload */
		virtual int compare(const IServerStatusDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IServerStatusDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IServerStatusDataType& other) const;

		/* see IServerStatusDataType::getStartTime */
		virtual const IDateTime* getStartTime() const;
		/* see IServerStatusDataType::setStartTime */
		virtual EnumStatusCode setStartTime(const IDateTime* value);
		/*! overload */
		virtual EnumStatusCode setStartTime(const DateTime& value);

		/* see IServerStatusDataType::getCurrentTime */
		virtual const IDateTime* getCurrentTime() const;
		/* see IServerStatusDataType::setCurrentTime */
		virtual EnumStatusCode setCurrentTime(const IDateTime* value);
		/* overload */
		virtual EnumStatusCode setCurrentTime(const DateTime& value);

		/* see IServerStatusDataType::getState */
		virtual EnumServerState getState() const;
		/* see IServerStatusDataType::setState */
		virtual void setState(const EnumServerState& value);

		/* see IServerStatusDataType::getBuildInfo */
		virtual const IBuildInfo* getBuildInfo() const;
		/* see IServerStatusDataType::setBuildInfo */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* value);
		/* overload */
		virtual EnumStatusCode setBuildInfo(const BuildInfo& value);

		/* see IServerStatusDataType::getSecondsTillShutdown */
		virtual OTUInt32 getSecondsTillShutdown() const;
		/* see IServerStatusDataType::setSecondsTillShutdown */
		virtual void setSecondsTillShutdown(const OTUInt32& value);

		/* see IServerStatusDataType::getShutdownReason */
		virtual const ILocalizedText* getShutdownReason() const;
		/* see IServerStatusDataType::setShutdownReason */
		virtual EnumStatusCode setShutdownReason(const ILocalizedText* value);
		/* overload */
		virtual EnumStatusCode setShutdownReason(const LocalizedText& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerDateTime m_startTime;
		InnerDateTime m_currentTime;
		InnerBuildInfo m_buildInfo;
		InnerLocalizedText m_shutdownReason;

		ServerStatusDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SERVERSTATUSDATATYPE_H
