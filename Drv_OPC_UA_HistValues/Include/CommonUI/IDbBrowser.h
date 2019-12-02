#pragma once
#include <OdsString.h>
#include <vector>
namespace ODS
{
namespace Resources
{

class IDbBrowser
{
public:
	virtual ~IDbBrowser() {};
	virtual int OpenSourcesBrowserDlg(HWND parentWnd, const OdsString &caption, OdsString &res)=0; //create modal dialog for select 
	virtual int EnumerateLocalSources(std::vector<OdsString> &sources) = 0; 
	virtual int EnumerateNetworkSources(std::vector<OdsString> &sources) = 0;
	virtual int EnumerateDatabases(const OdsString &connectString, std::vector<OdsString> &databeses) = 0;
	virtual int EnumerateTables(const OdsString &connectString,  std::vector<std::pair<OdsString,OdsString>> &tables) = 0;
	virtual int EnumerateViews(const OdsString &connectString, std::vector<std::pair<OdsString, OdsString>> &views) = 0;
	virtual int EnumerateColunmns(const OdsString &connectString, const OdsString &query, std::vector<std::pair<OdsString, int>> &columns) = 0;
	virtual int EnumerateDrivers(std::vector<OdsString>& drivers) =0;
	virtual int TestConnection(const OdsString &connectString,OdsString &errMessage) = 0;
	virtual int GetDbmsType(const OdsString &connectString, int* pnType, OdsString* pDbmsName) = 0;
};

class ISqlBrowser:public virtual IDbBrowser
{
public:
	virtual OdsString GetSqlServerDriverName(const OdsString &module) = 0;
};

}
}