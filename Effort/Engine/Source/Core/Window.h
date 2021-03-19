#pragma once

namespace Effort
{
	class Window
	{
	public:
		~Window()
		{
			UnregisterClass(mClassName.c_str(), mHinstance);
			DestroyWindow(mHandle);
		}

		// ウィンドウを生成します
		bool Create(const WNDCLASSEX& windowClassEx, const std::wstring& aWindowName, int32 showCmd = SW_SHOW);

		// ウィンドウハンドルを返します
		HWND GetHandle() { return mHandle; }

		// ウィンドウの左上を基準に座標を変更します
		void SetPosition(int32 x, int32 y) { SetWindowPos(mHandle, nullptr, x, y, NULL, NULL, SWP_NOSIZE | SWP_NOZORDER); }
		/**
		* brief ウィンドウの左上の座標を返します
		* retval first x
		* retval second y
		*/
		Vector2 GetPosition()const;

		// ウィンドウのサイズを変更します
		void SetWindowSize(int32 x, int32 y) { SetWindowPos(mHandle, nullptr, NULL, NULL, x, y, SWP_NOMOVE | SWP_NOZORDER); }
		/**
		* brief ウィンドウのサイズを返します
		* retval first x
		* retval second y
		*/
		Vector2 GetWindowSize()const;

		// クライアント領域のサイズを変更します
		void SetClientSize(int32 x, int32 y);
		/**
		* brief クライアント領域のサイズを返します
		* retval first x
		* retval second y
		*/
		Vector2 GetClientSize()const;

	private:
		HWND mHandle;
		//UnRegisterClassで使用
		std::wstring mClassName;
		//UnRegisterClassで使用
		HINSTANCE mHinstance;
	};
}