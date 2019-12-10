/*	Copyright (c) 2005 Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/*! 
	yterrloggerinterface.h: contains all exported API of Error Logger
	Author: Roman Reznikov
	Version: 3.11
	Date: 2005
*/

#ifndef _YTERRLOGGER_
#define _YTERRLOGGER_
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the YTERRLOGGER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// YTERRLOGGER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef YTERRLOGGER_EXPORTS
#define YTERRLOGGER_API __declspec(dllexport)
#else
#define YTERRLOGGER_API __declspec(dllimport)
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "..\Include\ytstlsupport.h"
#include "DreamReportInterface.h"

// Filter Definition
typedef USHORT  FILTER;
#define MAX_FILE_LEN  1024
#define MAX_STR_LEN   1024

#define MAX_LOG_MSG_LEN 1024

#define FILE_SIZE_CHECK_RATE  20

using namespace ErrLogFile;

/*
enum LEVEL
{
	LEVEL_LOW_INFORM = 1,
	LEVEL_NORMAL,
	LEVEL_DEBUG
};
*/

enum MSG_TYPE
{
	INFO,
	WARNING,
	ERROR_MSG
};

// This class is exported from the yterrlogger.dll
class YTERRLOGGER_API CYterrlogger {
public:
	static CYterrlogger* GetInstance();
	// TODO: add your methods here.
public:
	bool m_bMultisession;
	void WriteToFile(TCHAR* msg);
	void SetDefaultValues();

	enum
	{
		DEFAULT_FLAGS  = 0x00000000,
		PRINT_LAST_ERR = 0x00000001
	};

	enum HIST_LIMIT_TYPE
	{
		LIMIT_BY_SIZE,
		LIMIT_BY_SESIONS
	};

	int Shut();

	int Init(TCHAR* ModuleName = NULL);
	int Shut(TCHAR* ModuleName);

	void SetMaxFileSize(int nSize);
	void GetMaxFileSize(int* pnSize);
	void SetMaxHistFileSize(int nSize, HIST_LIMIT_TYPE HistLimitType);
	void GetMaxHistSize(int* pnSize);
	void SetLevel(ErrLogFile::LEVEL level);
	void GetLevel(ErrLogFile::LEVEL* pLevel);

	void PrepareString(char* szInputStr,YTString& szOutStr, MSG_TYPE MsgType); /// Format Output string to log
	int Log(LEVEL level,FILTER Filter, MSG_TYPE MsgType, /*ULONG flags,*/ char* szMessage);
	void SetFilter(FILTER Filter);
	void GetFilter(FILTER* pFilter);
	int SetCurrentDir(TCHAR* curDir);
	int SetFileName(TCHAR* fileName);
	TCHAR* GetFileName(void);
	void SetLogEnable(BOOL enable);

	void MoveLogToHis();

	void PrintLevel(void);

	void WelcomePrint();
	void WelcomePrint(TCHAR* ModuleName);
	int GetLogFileSize(DWORD* size);
	void SetFileLimit(DWORD limit);
	void DumpSystemInfo(void);
	///  Member Variables
	char m_FileName[MAX_FILE_LEN];
	char m_DirName[MAX_STR_LEN];
	char m_ModuleName[MAX_STR_LEN];

	FILE* m_pErrFile;
	BOOL m_bEnableLog;

	int   m_MaxFileSize; /// Max.size of online log file
	int   m_MaxHistFileSize; /// Max.size oh hist.log file

	HIST_LIMIT_TYPE m_HistLimitType;
	LEVEL m_CurrentLevel;
	FILTER m_Filter;
	DWORD m_sizeLimit;
	
	bool bRun;

	CYterrlogger(bool bMultisession=false);
	~CYterrlogger(void);

private:

   VOID CreatePrefix(YTString& rPrefix);

	static CYterrlogger* m_pInstance;

   CRITICAL_SECTION m_Synch;

   CHAR* m_pSeparator;
};


#endif //YTERRLOGGER_
