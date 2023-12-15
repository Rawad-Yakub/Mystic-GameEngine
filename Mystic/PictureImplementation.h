#pragma once

#include "Picture.h"

namespace mystic
{
	class PictureImplementation
	{
	public:
		virtual void Bind() = 0;
		virtual int GetHeight() = 0;
		virtual int GetWidth() = 0;

		virtual ~PictureImplementation() {};

	};
}