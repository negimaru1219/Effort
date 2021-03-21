#include "Application.h"

namespace Effort
{
	// 定数
	constexpr wchar_t kWindowName[] = L"Effort";
	constexpr wchar_t kClassName[] = L"Effort";
	constexpr int32 kClientSizeX = 1280;
	constexpr int32 kClientSizeY = 720;

	LRESULT APIENTRY WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// GetInput().SendWindowMessage(msg, wParam, lParam);
		// ::ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);

		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	
	WPARAM Application::Run()
	{
		// COM初期化
		CoInitializeEx(nullptr, COINIT_MULTITHREADED);

		// 初期化
		if (Initialize() == false) { return static_cast<WPARAM>(0); }

		// メッセージループ
		MSG msg;
		while (true)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) { break; }

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else 
			{
				MainLoop();
			}
		}

		// 終了処理
		Finalize();

		// COM解放
		CoUninitialize();

		return msg.wParam;
	}

	bool Application::Initialize()
	{
		if (CreateMainWindow() == false) { return false; }

		return true;
	}

	void Application::Finalize()
	{
	}

	void Application::MainLoop()
	{
		// 更新
		if (Update() == false) { PostQuitMessage(0); }
		// 描画
		if (Render() == false) { PostQuitMessage(0); }
	}

	bool Application::Update()
	{
		return true;
	}

	bool Application::Render()
	{
		return true;
	}

	bool Application::CreateMainWindow()
	{
		WNDCLASSEX wc = {
			sizeof(WNDCLASSEX),
			CS_CLASSDC,
			&WndProc,
			0L, 0L,
			GetModuleHandle(NULL),
			NULL, // LoadIcon(wc.hInstance, TEXT("IDI_ICON")),
			NULL, // ここを変えるとImGuiのウィンドウ境界の選択がバグる
			NULL,
			NULL,
			kClassName,
			NULL 
		};

		mWindow = std::make_unique<Window>();
		if (mWindow->Create(wc, kWindowName) == false) { return false; }
		mWindow->SetClientSize(kClientSizeX, kClientSizeY);

		return true;
	}
}