#pragma once

namespace nc
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton&) = delete;

		static T& Instance()
		{
			static T s_instance;
			return s_instance;
		}

	protected:
		Singleton() {}
	};

}
