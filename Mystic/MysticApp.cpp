//#include "pch.h"
//#include "MysticApp.h"

//#include "../glad/include/glad/glad.h"
//#include "../glfw/include/GLFW/glfw3.h"

//#include "../stbi/stb_image.h"

#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"

namespace mystic 
{
	template<typename T>
	MysticApp<T>::MysticApp()
	{
		mWindow.Create("RY Game", 1000, 800);

		mRenderer.Init();
	}

	template<typename T>
	void MysticApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void MysticApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void MysticApp<T>::Run()
	{
	

		/////////////////SHADERS/////////////////


		////////////////TEXTURES/////////////////

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/test.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipMap(GL_TEXTURE_2D);
		}
		else
		{
			MYS_ERROR("Failed to load a picture from file!!!");
		}
		stbi_image_free(data);



		mystic::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultVertexShader.glsl" };

		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void MysticApp<T>::OnUpdate()
	{
	}

	template<typename T>
	void MysticApp<T>::Draw(int x, int y, Picture& pic) 
	{
		mRenderer.Draw(100, 200, pic);
	}
}