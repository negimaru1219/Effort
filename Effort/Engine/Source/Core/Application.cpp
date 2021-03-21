#include "Application.h"

namespace Effort
{
	// �萔
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
		// COM������
		CoInitializeEx(nullptr, COINIT_MULTITHREADED);

		// ������
		if (Initialize() == false) { return static_cast<WPARAM>(0); }

		// ���b�Z�[�W���[�v
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

		// �I������
		Finalize();

		// COM���
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
		// �X�V
		if (Update() == false) { PostQuitMessage(0); }
		// �`��
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
			NULL, // ������ς����ImGui�̃E�B���h�E���E�̑I�����o�O��
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