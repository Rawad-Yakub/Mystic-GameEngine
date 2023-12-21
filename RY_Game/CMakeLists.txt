set(HEADER_FILES
	Game.h
)

set(SOURCE_FILES
	main.cpp
	Game.cpp
)

add_executable(RY_Game ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(RY_Game Mystic)

include_directories(../Mystic/include)