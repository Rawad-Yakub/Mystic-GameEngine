#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"


namespace mystic
{
	Picture::Picture(const std::string& pic)
	{
#ifdef MYSTIC_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif MYSTIC_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#elif MYSTIC_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pic) };
#endif
	}


	Picture::~Picture()
	{
		mImplementation->~PictureImplementation();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}


}