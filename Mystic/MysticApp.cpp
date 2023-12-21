#include "pch.h"
#include "MysticApp.h"
#include "Utilities.h"
#include "Mystic.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"

namespace mystic 
{
	template<typename T>
	MysticApp<T>::MysticApp()
	{
		mWindow.Create("RY Game", 2560, 1440);

		mRenderer.Init();

		SetWindowCloseCallBack([this]() {DeafultWindowCloseHandler(); });
	}

	template<typename T>
	void MysticApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void MysticApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void MysticApp<T>::Run()
	{
	
		mystic::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void MysticApp<T>::OnUpdate()
	{
	}

	template<typename T>
	void MysticApp<T>::Draw(int x, int y, Picture& pic) 
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void mystic::MysticApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}

	template<typename T>
	void MysticApp<T>::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc)
	{
		mWindow.SetKeyPressedCallBack(callbackfunc);
	}

	template<typename T>
	void MysticApp<T>::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc)
	{
		mWindow.SetKeyReleasedCallBack(callbackfunc);
	}

	template<typename T>
	void MysticApp<T>::SetWindowCloseCallBack(std::function<void()> callbackfunc)
	{
		mWindow.SetWindowCloseCallBack(callbackfunc);
	}

	template<typename T>
	void MysticApp<T>::DeafultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

}