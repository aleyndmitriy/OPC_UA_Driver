#include"pch.h"
#include"DataAccessAssembly.h"

DrvOPCUAHistValues::DataAccessAssembly::DataAccessAssembly():settingsDataSource(std::make_shared<XMLSettingsDataSource>()), softingDataSource(std::make_shared<SoftingServerInteractor>())
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

std::shared_ptr<SoftingServerInteractor> DrvOPCUAHistValues::DataAccessAssembly::GetSoftingDataSource() const
{
	return softingDataSource;
}

std::shared_ptr<DrvOPCUAHistValues::ISettingsDataSource> DrvOPCUAHistValues::DataAccessAssembly::GetSettingDataSource() const
{
	return settingsDataSource;
}

void DrvOPCUAHistValues::DataAccessAssembly::ClearAssemblies()
{
	settingsDataSource.reset();
	softingDataSource.reset();
}