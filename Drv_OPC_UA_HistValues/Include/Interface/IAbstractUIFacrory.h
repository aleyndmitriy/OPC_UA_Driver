#pragma once
#include <vector>
#include <vector>
#include <OdsErr.h>
#include <OdsString.h>

namespace ODS
{
	namespace Resources
	{
		class IDbBrowser;
		class IOpcBrowser;
	}
	namespace VQB
	{
		struct QueryStatistic;
	}
	namespace UI
	{
		class IFsBrowserUi;
		class CAbstractDriversEnumerator;
		class CAbstractDriver;
		class IPanelAnimation;

		class IAbstractUIFacrory
		{
		public:
			enum class Mode
			{
				Local,
				Remote
			};
			virtual ~IAbstractUIFacrory(){};
			virtual Mode GetMode() = 0;
			virtual int OpenVqb(const OdsString& rConnStr,
				const OdsString& rQueryIn,
				const OdsString& rUiLang, 
				OdsString& pQueryOut,
				VQB::QueryStatistic& pQs)=0;
			virtual CAbstractDriversEnumerator* CreateDriversEnumerator()=0;
			virtual CAbstractDriver* CreateDABrowser()=0;
			virtual CAbstractDriver* CreateGroupsBrowser() = 0;
			virtual CAbstractDriver* CreateHDABrowser()=0;
			virtual IFsBrowserUi*	 CreateFSBrowserUi()=0;
			virtual Resources::IDbBrowser*		 CreateSqlBrowser() = 0;
			virtual Resources::IDbBrowser*		 CreateOdbcBrowser() = 0;
			virtual Resources::IDbBrowser*		 CreateOledbBrowser() = 0;
			virtual Resources::IOpcBrowser*		 CreateOpcBrowser() = 0;
			virtual IPanelAnimation* CreatePanelAnimation() = 0;
		};
	}
}