#include "pch.h"
#include "MysticApp.h"

namespace mystic 
{
	template<typename T>
	MysticApp<T>::MysticApp()
	{
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
		mWindow.Create("RY Game", 1000, 800);

		 
		while (mShouldContinue)
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void MysticApp<T>::OnUpdate()
	{
	}
}