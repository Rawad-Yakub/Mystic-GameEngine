#pragma once

#include "Utilities.h"
#include "GameWindow.h"


namespace mystic
{

	template<typename T>
	class MysticApp
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

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
}

#include "MysticApp.cpp"