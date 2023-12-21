#include "pch.h"

#include "OpenGLPicture.h"

#include "Utilities.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "../stbi/stb_image.h"


namespace mystic
{
	OpenGLPicture::OpenGLPicture(const std::string& pic)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(pic.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			MYS_ERROR("Failed to load a picture from file!!!");
		}

		stbi_image_free(data);
	}


	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mTexture);
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}

	int OpenGLPicture::GetHeight() const
	{
		return height;
	}

	int OpenGLPicture::GetWidth() const
	{
		return width;
	}




}