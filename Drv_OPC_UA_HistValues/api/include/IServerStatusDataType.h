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

#ifndef ISERVERSTATUSDATATYPE_H
#define ISERVERSTATUSDATATYPE_H

#include "ServerStatusDataTypeStruct.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "BuildInfo.h"
#include "IBuildInfo.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The ServerStatusDataType is used to describe the status of the server. */
	class TBC_EXPORT IServerStatusDataType
	{
	public:
		/*! Destructor */
		virtual ~IServerStatusDataType(){};

		/*! Returns the time (UTC) the server was started.
		*
		* This is constant for the server instance and is not reset when the server changes state.
		* Each instance of a server should keep the time when the process started. */
		virtual const IDateTime* getStartTime() const = 0;
		/*! Sets the time (UTC) the server was started
		*
		* @param value The time (UTC) the server was started
		*
		* @see getStartTime() */
		virtual EnumStatusCode setStartTime(const IDateTime* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setStartTime(const DateTime& value) = 0;

		/*! Returns the current time (UTC) as known by the server */
		virtual const IDateTime* getCurrentTime() const = 0;
		/*! Sets the current time (UTC) as known by the server
		*
		* @param value The current time value */
		virtual EnumStatusCode setCurrentTime(const IDateTime* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCurrentTime(const DateTime& value) = 0;

		/*! Returns the current state of the server */
		virtual EnumServerState getState() const = 0;
		/*! Sets the current state of the server
		*
		* @param value The current state */
		virtual void setState(const EnumServerState& value) = 0;

		/*! Returns the information that describes the build of the software. */
		virtual const IBuildInfo* getBuildInfo() const = 0;
		/*! Sets the information that describes the build of the software.
		*
		* @param value The build information. */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setBuildInfo(const BuildInfo& value) = 0;

		/*! Returns the approximate number of seconds until the server will be shut down.
		*
		* The value is only relevant once the state changes into EnumServerState_Shutdown. */
		virtual OTUInt32 getSecondsTillShutdown() const = 0;
		/*! Sets the approximate number of seconds until the server will be shut down.
		*
		* @param value The number of seconds till shutdown. */
		virtual void setSecondsTillShutdown(const OTUInt32& value) = 0;

		/*! Returns the optional localized text indicating the reason for the shutdown.
		*
		* The value is only relevant once the state changes into EnumServerState_Shutdown. */
		virtual const ILocalizedText* getShutdownReason() const = 0;
		/*! Sets the optional localized text indicating the reason for the shutdown.
		*
		* @param value The reason for shutdown. */
		virtual EnumStatusCode setShutdownReason(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setShutdownReason(const LocalizedText& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IServerStatusDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IServerStatusDataType& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IServerStatusDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IServerStatusDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IServerStatusDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IServerStatusDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IServerStatusDataType
} // end namespace

#endif	// ISERVERSTATUSDATATYPE_H
