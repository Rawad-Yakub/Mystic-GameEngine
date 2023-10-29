set(HEADER_FILES
	include/Mystic.h
	MysticApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFW/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFW/GLFWImplementation.cpp
)

add_definitions(-DMYS_DEBUG=2)
add_definitions(-DMYSTIC_LIB)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(../glfw/include)

add_library(Mystic SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Mystic PRIVATE pch.h)

target_link_libraries(Mystic glfw)