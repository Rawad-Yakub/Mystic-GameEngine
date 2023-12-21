#pragma once

#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace mystic
{
	class GLFWImplementation : public WindowImplementation
	{
	public:
		GLFWImplementation(); 

		virtual void Create(const std::string& name, int width, int height) override;
		virtual int GetHeight() const override;
		virtual int GetWidth() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc) override;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc) override;
		virtual void SetWindowCloseCallBack(std::function<void()> callbackfunc) override;

	private:
		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> keyReleasedFunc{ [](const KeyReleased&) {} };
			std::function<void()> windowCloseFunc{ []() {} };
		} mCallbacks;


		GLFWwindow* mWindow;

	};
}