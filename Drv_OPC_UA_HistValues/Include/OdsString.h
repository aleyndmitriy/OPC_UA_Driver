/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief OdsString declaration. This string has to be used in every place where string is needed
*/

#pragma once

#include <atlstr.h>

namespace ODS
{
	// definition from <atlstr.h> :
	//typedef CStringT< TCHAR, StrTraitATL< TCHAR, ChTraitsCRT< TCHAR > > > CAtlString;

	typedef ATL::CAtlString OdsString;
}