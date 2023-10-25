#pragma once

#include "Utilities.h"


namespace mystic
{

	template<typename T>
	class MYSTIC_API MysticApp
	{
	public:
		static void Init();
		static void RunInterface();

		friend typename T;

		void Run();
		virtual void OnUpdate();

	private:
		MysticApp();

		inline static MysticApp* sInstance{ nullptr };
		bool mShouldContinue{ true };
	};
}

#include "MysticApp.cpp"