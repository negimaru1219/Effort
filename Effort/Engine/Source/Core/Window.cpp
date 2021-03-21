#include "Window.h"

namespace Effort
{
	bool Window::Create(const WNDCLASSEX& windowClassEx, const std::wstring& windowName, int32 showCmd)
	{
		constexpr int32 kWindowWidth = 1280;
		constexpr int32 kWindowHeight = 720;

		RegisterClassEx(&windowClassEx);

		// ウィンドウの生成
		mHandle = CreateWindow(
			windowClassEx.lpszClassName, windowName.c_str(), WS_OVERLAPPEDWINDOW,
			0, 0,
			kWindowWidth, kWindowHeight,
			nullptr, nullptr,
			windowClassEx.hInstance, nullptr);
		if (mHandle == nullptr) { return false; }

		mClassName = windowClassEx.lpszClassName;
		mHinstance = windowClassEx.hInstance;

		//ShowWindow(mHandle, showCmd);
		//UpdateWindow(mHandle);

		return true;
	}

	Vector2 Window::GetPosition() const
	{
		RECT r;
		GetWindowRect(mHandle, &r);
		return { static_cast<float>(r.left), static_cast<float>(r.top) };
	}

	Vector2 Window::GetWindowSize() const
	{
		RECT r;
		GetWindowRect(mHandle, &r);
		return { static_cast<float>(r.right - r.left), static_cast<float>(r.bottom - r.top) };
	}

	void Window::SetClientSize(int32 x, int32 y)
	{
		const auto WinSize = GetWindowSize();
		const auto CliSize = GetClientSize();
		const int32 NewX = static_cast<int32>(WinSize.x - CliSize.x + x);
		const int32 NewY = static_cast<int32>(WinSize.y - CliSize.y + y);

		SetWindowPos(mHandle, nullptr, NULL, NULL, NewX, NewY, SWP_NOMOVE | SWP_NOZORDER);
	}

	Vector2 Window::GetClientSize() const
	{
		RECT r;
		GetClientRect(mHandle, &r);
		return { static_cast<float>(r.right), static_cast<float>(r.bottom) };
	}

}