#pragma once

//#include "Picture.h"

namespace mystic
{
	class PictureImplementation
	{
	public:
		virtual void Bind() = 0;
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual ~PictureImplementation() {};

	};
}