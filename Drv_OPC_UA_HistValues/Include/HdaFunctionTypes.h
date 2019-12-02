/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file  HdaFunctionTypes.h
	@brief HDA Function Types for public use (IServerHda interface)
*/


#pragma once

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{


namespace HdaFunctionType
{

static const int INVALID                         = 0;

static const int VALUE_LIST                      = 10;
static const int VALUE_LIST_CONDITION            = 20;
static const int LAST_VALUE                      = 30;
static const int FIRST_VALUE                     = 40;
static const int MAX_VALUE                       = 50;
static const int MIN_VALUE                       = 60;
static const int AVG_VALUE                       = 70;
static const int SUM_VALUE                       = 80;
static const int COUNT_OF_LOGGED_VALUES          = 90;
static const int TIMESTAMP_OF_FIRST_VALUE        = 100;
static const int TIMESTAMP_OF_LAST_VALUE         = 110;
static const int TIMESTAMP_OF_MINIMUM_VALUE      = 120;
static const int TIMESTAMP_OF_MAXIMUM_VALUE      = 130;
static const int STANDART_DEVIATION              = 140;
static const int STANDART_DEVIATION_SAMPLE_BASED = 150;
static const int BATCH_ID_LIST                   = 160; // params TYPE_ITEM_ADDRESS, TYPE_BATCH_ID_LIST
static const int BATCH_ID_LIST_WITH_SQC          = 161; // params TYPE_ITEM_ADDRESS, TYPE_BATCH_ID_LIST
static const int BATCH_ID                        = 170; // params: TYPE_ITEM_ADDRESS, TYPE_BATCH_ID_LIST
static const int BATCH_START_END_TIME            = 180; // param: TYPE_ITEM_ADDRESS, TYPE_BATCH_INFO
static const int ALARM_LIST                      = 190;
static const int ALARM_COUNT                     = 200;
static const int LARGE_VALUE                     = 210;
static const int SMALL_VALUE                     = 220;
static const int TIMESTAMP_OF_FIRST_ALARM        = 230;
static const int TIMESTAMP_OF_LAST_ALARM         = 240;
static const int F0                              = 250;
static const int ALARM_MAX_DURATION              = 260;
static const int ALARM_MIN_DURATION              = 270;
static const int ALARM_MAX_RESPONSE              = 280;
static const int ALARM_MIN_RESPONSE              = 290;

static const int SQL_QUERY                       = 300; // special function that is implemented  in internal history driver
                                                        // param: HdaFunctionParamSqlQuery, result: HdaFunctionResultSqlQuery

static const int SQL_QUERY_VALUE                 = 310; // special function that is implemented  in internal history driver
                                                        // param: HdaFunctionParamSqlQuery, result: HdaFunctionResultValueList

static const int SQL_QUERY_STEP                  = 320; // special function that is implemented  in internal history driver
                                                        // param: HdaFunctionParamSqlQuery, result: 

static const int OPEN_SESSION                    = 400; // special function to open session in the driver, support is optional, HdaFunctionResultSession
static const int CLOSE_SESSION                   = 410; // special function to close session in the driver, support is optional, param: 

static const int CUSTOM                          = 1000; // custom function that can be implemented in the drivers
                                                         // result of this function is always HdaFunctionResultObject


}

}

/**
	@}
*/

#pragma pack()