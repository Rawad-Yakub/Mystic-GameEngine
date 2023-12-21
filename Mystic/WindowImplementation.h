#pragma once

#include "pch.h"
#include "Events.h"

namespace mystic
{
	class WindowImplementation
	{
	public:
		virtual void Create(const std::string& name, int width, int height) = 0;
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc) = 0;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc) = 0;
		virtual void SetWindowCloseCallBack(std::function<void()> callbackfunc) = 0;

		virtual ~WindowImplementation() {};

	};
}