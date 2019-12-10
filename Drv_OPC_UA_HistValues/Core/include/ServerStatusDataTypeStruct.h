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

#ifndef _ServerStatusDataTypeStruct_H_
#define _ServerStatusDataTypeStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"
#include "Enums.h"
#include "BuildInfoStruct.h"
#include "LocalizedTextStruct.h"

/*! This structure contains elements that describe the status of the Server. */
//lint -sem(ServerStatusDataTypeStruct::clear, cleanup)
//lint -sem(ServerStatusDataTypeStruct::init, initializer)
typedef struct TBCORE_IF ServerStatusDataTypeStruct
{
	/*! Time (UTC) the server was started.
	* This is constant for the server instance and is not reset when the server changes state.
	* Each instance of a server should keep the time when the process started. */
	DateTimeStruct startTime;

	/*! The current time (UTC) as known by the server. */
	DateTimeStruct currentTime;

	/*! The current state of the server. */
	EnumServerState state;

	/*! Information that describes the build of the software. */
	BuildInfoStruct buildInfo;

	/*! Approximate number of seconds until the server will be shut down.
	* The value is only relevant once the state changes into EnumServerState_Shutdown. */
	OTUInt32 secondsTillShutdown;

	/*! An optional localized text indicating the reason for the shutdown.
	* The value is only relevant once the state changes into EnumServerState_Shutdown. */
	LocalizedTextStruct shutdownReason;


	ServerStatusDataTypeStruct();
	ServerStatusDataTypeStruct(const ServerStatusDataTypeStruct&);

	EnumStatusCode set(const ServerStatusDataTypeStruct&);
	EnumStatusCode get(ServerStatusDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ServerStatusDataType&);
	EnumStatusCode get(OpcUa_ServerStatusDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const ServerStatusDataTypeStruct& operator=(const ServerStatusDataTypeStruct& cp);
	bool operator==(const ServerStatusDataTypeStruct& toCompare) const;
	bool operator!=(const ServerStatusDataTypeStruct& toCompare) const;
	bool operator<(const ServerStatusDataTypeStruct& toCompare) const;
	bool operator>(const ServerStatusDataTypeStruct& toCompare) const;

	int compare(const ServerStatusDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ServerStatusDataTypeStruct(void);
} ServerStatusDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
