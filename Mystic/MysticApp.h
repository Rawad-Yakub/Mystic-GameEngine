#pragma once

#include "Utilities.h"
#include "GameWindow.h"
#include "Renderer.h"
#include "Picture.h"


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

		void Draw(int x, int y, Picture& pic);

	private:
		MysticApp();

		inline static MysticApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
}

#include "MysticApp.cpp"