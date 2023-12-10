#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"


mystic::Renderer::Renderer()
{
#ifdef MYSTIC_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif MYSTIC_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif MYSTIC_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void mystic::Renderer::Init()
{
	mImplementation->Init();
}

void mystic::Renderer::Draw(int x, int y, Picture& pic)
{
	mImplementation->Draw(x, y, pic);
}

void mystic::Renderer::Clear()
{
	mImplementation->Clear();
}




