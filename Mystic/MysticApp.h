#pragma once

#include "Utilities.h"
#include "GameWindow.h"
#include "Renderer.h"
#include "Picture.h"
#include "Unit.h"


namespace mystic
{

	constexpr int FPS{ 60 };

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
		void Draw(Unit& item);


		void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc);
		void SetWindowCloseCallBack(std::function<void()> callbackfunc);

		void DeafultWindowCloseHandler();


	private:
		MysticApp();

		inline static MysticApp* sInstance{ nullptr };

		GameWindow mWindow;

		Renderer mRenderer;

		bool mShouldContinue{ true };

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

#include "MysticApp.cpp"