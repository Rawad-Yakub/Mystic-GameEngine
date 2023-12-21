#pragma once

#include "Utilities.h"

namespace mystic
{
	class MYSTIC_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class MYSTIC_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class MYSTIC_API WindowCLosed
	{
	};
}