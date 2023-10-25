set(HEADER_FILES
	include/Mystic.h
	MysticApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DMYS_DEBUG=2)
add_definitions(-DMYSTIC_LIB)

if(WIN32)
	add_definitions(-DMYSTIC_MSCPP)
elseif(LINUX)
	add_definitions(-DMYSTIC_LINUX)
elseif(APPLE)
	add_definitions(-DMYSTIC_APPLE)
endif()

add_library(Mystic SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Mystic PRIVATE pch.h)