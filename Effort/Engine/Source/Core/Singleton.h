#pragma once

namespace Effort
{
	template<class T>
	class Singleton 
	{
	public:
		/** �C���X�^���X���쐬 */
		template<class ...Args>
		static void Create(Args&& ...args)
		{
			if (mInstance != nullptr)
			{
				// MC_LOG(LogType::eInfo, "���ɃC���X�^���X������Ă��܂� �^�� = %s", typeid(T).name());
			}

			mInstance = new T(std::forward<Args>(args)...);
		}

		/** �C���X�^���X���쐬 */
		template<class CreateType, class ...Args>
		static void Create(Args&& ...args)
		{
			if (mInstance != nullptr)
			{
				// MC_LOG(LogType::eInfo, "���ɃC���X�^���X������Ă��܂� �^�� = %s", typeid(T).name());
			}

			mInstance = new CreateType(std::forward<Args>(args)...);
		}

		/** �C���X�^���X����� */
		static void Destroy()
		{
			delete mInstance;
			mInstance = nullptr;
		}

		/** �C���X�^���X��Ԃ� */
		static T& GetInstance()
		{
			return *mInstance;
		}

		/** �C���X�^���X�������Ă�����true��Ԃ� */
		static bool HasInstance()
		{
			return mInstance != nullptr;
		}

	protected:
		Singleton() {}
		virtual ~Singleton() {}

	private:
		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(const Singleton&&) = delete;

		static inline T* mInstance = nullptr;
	};
}