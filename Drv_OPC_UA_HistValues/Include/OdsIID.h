/*	Copyright (c) 2010 Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/*! @file ID for interfaces
	Author: 
	Version: 4.0
	Date: 2010.10
*/


#pragma once


namespace ODS
{
	namespace IID
	{
		static const int IID_DRIVER = 1001;

		static const int IID_DA_ITEM_BROWSER  = 1101;
		static const int IID_DA_ALARM_DROWSER = 1102;

		static const int IID_HDA_ITEM_BROWSER  = 1103;
		static const int IID_HDA_ALARM_BROWSER = 1104;

		static const int IID_HDA_ALARM_CLIENT_INFO = 1105;

		static const int IID_DA_ITEM_CLIENT = 1201;

		static const int IID_DA_ALARM_CLIENT = 1301;

		static const int IID_HDA_DATA_CLIENT = 1401;
		static const int IID_HDA_ALARM_CLIENT = 1402;

		static const int IID_PROPERTY_SET = 3000;

		static const int IID_PROJECT_INFO = 4000;

		static const int IID_LICENSE_INFO = 5000;
	}
}