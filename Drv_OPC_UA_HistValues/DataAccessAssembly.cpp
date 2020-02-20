#include"pch.h"
#include"DataAccessAssembly.h"

DrvOPCUAHistValues::DataAccessAssembly::DataAccessAssembly():settingsDataSource(std::make_shared<XMLSettingsDataSource>()), softingAppInstance(std::make_shared<SoftingApplication>())
{

}

DrvOPCUAHistValues::DataAccessAssembly::~DataAccessAssembly()
{
	ClearAssemblies();
}

DrvOPCUAHistValues::DataAccessAssembly& DrvOPCUAHistValues::DataAccessAssembly::Instance()
{
	static DataAccessAssembly shared;
	return shared;
}

std::shared_ptr<DrvOPCUAHistValues::SoftingApplication> DrvOPCUAHistValues::DataAccessAssembly::GetSoftingAppInstance() const
{
	return softingAppInstance;
}

std::shared_ptr<DrvOPCUAHistValues::ISettingsDataSource> DrvOPCUAHistValues::DataAccessAssembly::GetSettingDataSource() const
{
	return settingsDataSource;
}

void DrvOPCUAHistValues::DataAccessAssembly::ClearAssemblies()
{
	settingsDataSource.reset();
	softingAppInstance.reset();
}