#include "pch.h"
#include "Shader.h"
#include "GLFWCode/OpenGLShader.h"

namespace mystic
{
	Shader::Shader(const std::string& vertextSFile, const std::string fragmentSFile)
	{
#ifdef MYSTIC_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertextSFile, fragmentSFile)};
#elif MYSTIC_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertextSFile, fragmentSFile) };
#elif MYSTIC_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertextSFile, fragmentSFile) };
#endif
	}
	void Shader::Bind()
	{
		mImplementation->Bind();
	}
	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}
	void Shader::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(std::move(uniformName), val1, val2);
	}
}