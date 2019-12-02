#pragma once
#include"IEnvironment.h"
#include <sql.h>
#include <sqlext.h>

namespace DrvOPCUAHistValues
{
	class SQLServerEnvironment final : public IEnvironment {
	public:
		SQLServerEnvironment();
		~SQLServerEnvironment() override;
		SQLServerEnvironment(SQLServerEnvironment&& rhs) = delete;
		SQLServerEnvironment& operator=(SQLServerEnvironment&& rhs) = delete;
		SQLServerEnvironment(const SQLServerEnvironment& src) = default;
		SQLServerEnvironment& operator=(const SQLServerEnvironment& rhs) = default;
		void* GetInterface([[maybe_unused]] int nIfcId) override;
	private:
		SQLHENV m_sqlEnvironment;
	};
}