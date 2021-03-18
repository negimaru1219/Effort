#pragma once

namespace Effort
{
	template<class T>
	class Singleton 
	{
	public:
		/** インスタンスを作成 */
		template<class ...Args>
		static void Create(Args&& ...args)
		{
			if (mInstance != nullptr)
			{
				// MC_LOG(LogType::eInfo, "既にインスタンス化されています 型名 = %s", typeid(T).name());
			}

			mInstance = new T(std::forward<Args>(args)...);
		}

		/** インスタンスを作成 */
		template<class CreateType, class ...Args>
		static void Create(Args&& ...args)
		{
			if (mInstance != nullptr)
			{
				// MC_LOG(LogType::eInfo, "既にインスタンス化されています 型名 = %s", typeid(T).name());
			}

			mInstance = new CreateType(std::forward<Args>(args)...);
		}

		/** インスタンスを解放 */
		static void Destroy()
		{
			delete mInstance;
			mInstance = nullptr;
		}

		/** インスタンスを返す */
		static T& GetInstance()
		{
			return *mInstance;
		}

		/** インスタンスを持っていたらtrueを返す */
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