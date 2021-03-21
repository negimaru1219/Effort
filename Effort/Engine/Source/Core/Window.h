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

		/** �E�B���h�E���쐬 */
		bool Create(const WNDCLASSEX& windowClassEx, const std::wstring& aWindowName, int32 showCmd = SW_SHOW);

		/** �E�B���h�E�n���h����Ԃ� */
		HWND GetHandle() { return mHandle; }

		/** �E�B���h�E�̍������ɍ��W��ύX */
		void SetPosition(int32 x, int32 y) { SetWindowPos(mHandle, nullptr, x, y, NULL, NULL, SWP_NOSIZE | SWP_NOZORDER); }

		/**
		* @brief �E�B���h�E�̍���̍��W��Ԃ�
		* @retval ���W
		*/
		Vector2 GetPosition()const;

		/** �E�B���h�E�̃T�C�Y��ύX */
		void SetWindowSize(int32 x, int32 y) { SetWindowPos(mHandle, nullptr, NULL, NULL, x, y, SWP_NOMOVE | SWP_NOZORDER); }

		/**
		* @brief �E�B���h�E�̃T�C�Y���
		* @retval ���W
		*/
		Vector2 GetWindowSize()const;

		/** �N���C�A���g�̈�̃T�C�Y��ύX */
		void SetClientSize(int32 x, int32 y);

		/**
		* @brief �N���C�A���g�̈�̃T�C�Y��Ԃ�
		* @retval ���W
		*/
		Vector2 GetClientSize()const;

	private:
		HWND mHandle;
		/** UnRegisterClass�Ŏg�p */
		std::wstring mClassName;
		/** UnRegisterClass�Ŏg�p */
		HINSTANCE mHinstance;
	};
}