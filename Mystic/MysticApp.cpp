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

		while (mShouldContinue)
		{
			OnUpdate();
		}
	}

	template<typename T>
	void MysticApp<T>::OnUpdate()
	{
	}
}