#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"


namespace mystic
{
	class MYSTIC_API Picture
	{
	public:
		Picture(const std::string& pic);
		~Picture();
		int GetHeight() const;
		int GetWidth() const;
		void Bind();

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
		//int height;
		//int width;

	};
}