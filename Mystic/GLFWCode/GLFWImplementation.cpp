#include "pch.h"
#include "GLFWImplementation.h"

#include "GLFW/glfw3.h"


namespace mystic
{
	GLFWImplementation::GLFWImplementation()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	}


	void GLFWImplementation::Create(const std::string& name, int width, int height)
	{
		mWindow = glfwCreateWindow(800, 600, "RY_Game", NULL, NULL);

		if (mWindow == NULL)
		{
			MYS_ERROR("Failed to create GLFW window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_PRESS)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
			});
		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowCloseFunc();
			});
	}
	
	int GLFWImplementation::GetHeight() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}


	int GLFWImplementation::GetWidth() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}


	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}


	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}

	void GLFWImplementation::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc)
	{
		mCallbacks.keyPressedFunc = callbackfunc;
	}

	void GLFWImplementation::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc)
	{
		mCallbacks.keyReleasedFunc = callbackfunc;
	}

	void GLFWImplementation::SetWindowCloseCallBack(std::function<void()> callbackfunc)
	{
		mCallbacks.windowCloseFunc = callbackfunc;
	}


}