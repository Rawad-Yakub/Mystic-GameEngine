#include "pch.h"

#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace mystic
{
	GameWindow::GameWindow()
	{
#ifdef MYSTIC_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif MYSTIC_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif MYSTIC_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
	}


	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}


	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}


	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}


	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}


	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}

	void GameWindow::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc)
	{
		mImplementation->SetKeyPressedCallBack(callbackfunc);
	}

	void GameWindow::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc)
	{
		mImplementation->SetKeyReleasedCallBack(callbackfunc);
	}

	void GameWindow::SetWindowCloseCallBack(std::function<void()> callbackfunc)
	{
		mImplementation->SetWindowCloseCallBack(callbackfunc);
	}

}