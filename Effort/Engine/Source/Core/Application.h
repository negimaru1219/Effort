#pragma once

#include "Singleton.h"
#include "Window.h"

#define EF_SINGLETON_GETTER(Name) inline Name& Get##Name##() { return Name::GetInstance(); }

namespace Effort
{
	class Application : public Singleton<Application>
	{
	public:
		virtual WPARAM Run();

	protected:
		virtual bool Initialize();
		virtual void Finalize();

		virtual void MainLoop();
		virtual bool Update();
		virtual bool Render();

		bool CreateMainWindow();

	private:
		/** メインウィンドウ */
		UPtr<Window> mWindow;
	};

	EF_SINGLETON_GETTER(Application);
}