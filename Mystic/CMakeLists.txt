set(HEADER_FILES
	include/Mystic.h
	MysticApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	Events.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLShader.h
	GLFWCode/OpenGLRenderer.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	Events.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DMYS_DEBUG=2)
add_definitions(-DMYSTIC_LIB)

include_directories(../Mystic)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Mystic SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Mystic PRIVATE pch.h)

target_link_libraries(Mystic glfw)
target_link_libraries(Mystic glad)
target_link_libraries(Mystic stbi)