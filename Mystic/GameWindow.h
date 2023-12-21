#pragma once

#include "pch.h"
#include "Utilities.h"
#include "WindowImplementation.h"
#include "Events.h"

namespace mystic {
	
	class MYSTIC_API GameWindow 
	{
	public:
		GameWindow();
		void Create(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		void SwapBuffers();
		void PollEvents();

		void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackfunc);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackfunc);
		void SetWindowCloseCallBack(std::function<void()> callbackfunc);

	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };

	};
}