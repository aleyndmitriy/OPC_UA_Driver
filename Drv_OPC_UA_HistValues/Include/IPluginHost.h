/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file  IPluginHost.h
	@brief IPluginHost interface
*/

#pragma once

#include <windows.h>
#include <tchar.h>

#include "IExtensible.h"

#pragma pack(8)

/**
   @addtogroup ods_sdk
   @{
*/

namespace ODS
{

class IPluginObjectFactory;
class IPropertySet;
class ObjectCreationParam;

struct PluginApiVer
{
	int m_nMajor;
	int m_nMinor;
};

struct RegisterInfo
{
	PluginApiVer          m_Version;             /** version of plugin api supported by the plugin object */
	TCHAR                 m_szObjKey[MAX_PATH];  /** object key is unique in the plugin dll, this key will be passed to factory */
	IPropertySet*         m_pPropertySet;        /** property set that describes the object, to present in UI for example */
	IPluginObjectFactory* m_pFactory;            /** pointer to factory that will be used to create objects */
	void*                 m_pObjCreationParam;   /** pointer to some creation parameters, this pointer will be passed to factory */
};

class IPluginHost : public IExtensible
{
public:

	static const int IID_LOG                 = 500; // interface ODS::System::ILog
	static const int IID_PROJECT_DEF         = 600; // interface ODS::System::IProjectDef
	static const int IID_UI_FACTORY			 = 700; // interface ODS::UI::IAbstractUIFacrory

	
	virtual void GetVersion(PluginApiVer* pVersion) = 0;
	/**<
		@brief Retrieve the version of plugin api that is provided by host

		@param[out] pVersion Pointer to struct to be filled on output

		@return VOID
	*/

	
	virtual int RegisterObject(void* pParam, RegisterInfo* pRegInfo) = 0;
	/**<
		@brief This method is called by plugin when InitPlugin entry point has been
		       called by loader. This method will be called for each object which is
				 supported in the plugin dll.

		@param[in] pParam Pointer to some parameter that was passed in InitPlugin() entry point
	   @param[in] pRegInfo Pointer to filled by plugin registration structure

		@return Error code
	*/
};

}

/** @} */

#pragma pack()