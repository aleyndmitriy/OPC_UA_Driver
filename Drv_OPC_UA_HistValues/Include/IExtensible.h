/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief Basic interfaces for extensibility.
*/


#pragma once

#pragma pack(8)

/**
   @addtogroup ods_sdk
   @{
*/

namespace ODS
{

class IExtensible
{
public:

	virtual ~IExtensible() {}
	virtual void* GetInterface(int nIfcId) = 0;
};

}

/** @} */

#pragma pack()