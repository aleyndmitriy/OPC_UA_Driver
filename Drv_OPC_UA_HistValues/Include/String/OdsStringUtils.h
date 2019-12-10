/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief These utils do not belong to any module, can be included and used
*/

#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include "OdsString.h"

namespace ODS
{

namespace OdsStringUtils
{

static void FormatOdsStringFromArgList(const TCHAR* szFormat, va_list args, OdsString* pString)
{
   if (!szFormat)
      return;

   int result = -1, length = 512;

   TCHAR* buffer = 0;
   
   while (result == -1)
   {
      if (buffer)
         delete [] buffer;
      
      buffer = new TCHAR[length + 1];

      memset(buffer, 0, (length + 1) * sizeof(TCHAR));	 

      result = _vsntprintf_s(buffer, (length + 1) * sizeof(TCHAR), length, szFormat, args);

      length *= 2;
   }
   
   *pString = buffer;

   delete [] buffer;
}

class NoCaseComparator
{
public:
   NoCaseComparator(){}
   ~NoCaseComparator(){}

   bool operator()(const OdsString& rLeft, const OdsString& rRight) const
   {
		return (rLeft.CompareNoCase(rRight) < 0);
   }
};

}} // namespace