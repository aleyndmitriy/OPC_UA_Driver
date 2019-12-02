/*	Copyright (c) 2010 Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file AlarmPropertyId.h
	@brief Contains standard alarm property ID.
*/

#pragma once


#pragma pack(8)

/**
	@add to group ods_sdk
	@{
*/

namespace ODS
{

namespace AlarmProperty
{

static const int ID_START_TIME  = 0;  // property id for start time, always presented in alarm, 
                                      // can be VT_UI8 (milliseconds from 1970)
                                      // or VT_DATE (double to be converted with ConvertDateMsecToSystemTime)

static const int ID_ACK_TIME    = 1;  // property id for ack time, always presented but can have empty value
									  // can be VT_UI8 (milliseconds from 1970)
									  // or VT_DATE (double to be converted with ConvertDateMsecToSystemTime)

static const int ID_END_TIME    = 2;  // property id for end time, always presented but can have empty value
									  // can be VT_UI8 (milliseconds from 1970)
									  // or VT_DATE (double to be converted with ConvertDateMsecToSystemTime)

static const int ID_TEXT        = 3;  // property id for text, always presented, but can have empty value 
static const int ID_PRIORITY    = 4;  // property id for priority, always presented but can have empty value
static const int ID_ALARM_ID    = 10; // property id for alarm ID, always presented but can have empty value
static const int ID_ALARM_CAUSE = 11; // property id for alarm cause, always presented but can have empty value
static const int ID_SOURCE_NAME = 12; // property id for alarm source name, always presented, but can have empty value

static const int ID_CUSTOM_PROP_OFFSET = 1001; // offset to start custom property ids

static const int ALARM_CAUSE_START = 1;
static const int ALARM_CAUSE_ACK   = 2;
static const int ALARM_CAUSE_END   = 0;

} //namespace AlarmProperty

} // namespace ODS

/**
	@}
*/

#pragma pack()