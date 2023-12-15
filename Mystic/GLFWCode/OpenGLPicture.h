#pragma once

#include "PictureImplementation.h"

namespace mystic
{

	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& pic);

		~OpenGLPicture();

		virtual void Bind() override;
		virtual int GetHeight() override;
		virtual int GetWidth() override;

	private:
		unsigned int mTexture;
		int height;
		int width;
	};

}