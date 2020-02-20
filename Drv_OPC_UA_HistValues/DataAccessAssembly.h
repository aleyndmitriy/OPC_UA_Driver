#pragma once
#include "XMLSettingsDataSource.h"
#include"SoftingApplication.h"

namespace DrvOPCUAHistValues
{
	class DataAccessAssembly  {
	public:
		std::shared_ptr<SoftingApplication> GetSoftingAppInstance() const;
		std::shared_ptr<ISettingsDataSource> GetSettingDataSource() const;
		~DataAccessAssembly();
		void ClearAssemblies();
		DataAccessAssembly(const DataAccessAssembly& src) = delete;
		DataAccessAssembly& operator=(const DataAccessAssembly& src) = delete;
		DataAccessAssembly(DataAccessAssembly&& rhs) = delete;
		DataAccessAssembly& operator=(DataAccessAssembly&& rhs) = delete;
		static DataAccessAssembly& Instance();
	private:
		std::shared_ptr<XMLSettingsDataSource> settingsDataSource;
		std::shared_ptr<SoftingApplication> softingAppInstance;
		DataAccessAssembly();
	};
}