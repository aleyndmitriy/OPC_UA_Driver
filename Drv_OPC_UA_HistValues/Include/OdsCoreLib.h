/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Export declarations for dll that will provide basic types, services, etc
*/

#pragma once

#ifndef ODS_CORE_LIB_IMPL
	#define ODS_CORE_LIB_EXP __declspec(dllimport)
#else
	#define ODS_CORE_LIB_EXP __declspec(dllexport)
#endif