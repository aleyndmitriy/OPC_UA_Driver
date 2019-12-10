/*
	Copyright (c) 2003-2011 Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file   OdsErr.h
	@brief  This file contains error codes
*/


#pragma once

namespace ODS
{

namespace ERR
{
	static const int OK							= 0;
	static const int ACCESS_DENIED				= 1;
	static const int PLUGIN_REINIT_REQUIRED		= 2; // returned from plugin which has configuration when
	                                             // configuration was changed and re-init is required
	static const int MEMORY_ALLOCATION_ERR		= 3;

	static const int BAD_TYPE					= 4;

	static const int BAD_PARAM					= 5;

	static const int NOT_FOUND					= 6;

	static const int CREATE_ERR					= 7;
	static const int INIT_NULL_POINTER			= 71;

	static const int INIT_ERR					= 8;
	static const int INIT_ERR_STORAGE			= 81;
	static const int INIT_ERR_DATASVR_RT		= 82;

	static const int DUPLICATE_ERR				= 9;

	static const int SYSTEM						= 10;

	static const int NOT_SUPPORTED				= 11;

	static const int OUT_OF_RANGE				= 12;

	static const int READY						= 14;

	static const int TIMEOUT					= 15;

	static const int SEQUENCE					= 16;

	static const int FILE						= 17;

	static const int LICENSE_ERR				  = 18;
	static const int LICENSE_PERMISSION_ERR       = 180;
	static const int LICENSE_ITEM_COUNT_VIOLATION = 181;
	
	static const int UNDEFINED					= 19;

	static const int CANCELED					= 20;

	static const int PROTOCOL					= 21;

	static const int PARTIALLY_COMPLETED        = 22;


	//statistic lib errors
	static const int NO_DATA_TO_CALCULATE          = 201;
	static const int NOT_ENOUGH_DATA_TO_CALCULATE  = 202;
	static const int INVALID_CALC_RESULT           = 203;

	/// database errors
	static const int DB_NOT_FOUND            = 301;
	static const int DB_QUERY_FAILED         = 302;
	static const int DB_NO_DATA              = 303;
	static const int DB_CONNECTION_FAILED    = 304;
	static const int DB_CREATE_FAILED		 = 305;
	static const int DB_EXCEPTION   		 = 306;
	static const int MAIN_PROJ_DB_NOT_FOUND  = 307;
	static const int ALL_PROJ_DB_NOT_FOUND   = 308;

	/// Driver errors

	/// IIS config errors
	static const int ERR_WEB_LISENCE		= 401;
	static const int ERR_WEB_NOT_INSTALLED	= 402;
	static const int ERR_MOBILE_WEB_NOT_INSTALLED	= 403;

	/// DBatch errors
	static const int DBATCH_GENERAL = 501;
	static const int DBATCH_NOT_RUNNING = 502;
	static const int DBATCH_INVALID_BATCH_ID = 503;
	static const int DBATCH_INVALID_DATA = 504;
	static const int DBATCH_BATCH_START_FAILED = 505;
	static const int DBATCH_BATCH_STOP_FAILED = 506;
	static const int DBATCH_BATCH_STORE_FAILED = 507;

	//remote dev
	static const int REMOTE_DEV_RESOURCE_CAPTURED     = 600;
	static const int REMOTE_DEV_RESOURCE_NOT_CAPTURED = 601;
}

}