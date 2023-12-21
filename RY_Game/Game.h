#pragma once

#include "Mystic.h"
#include <iostream>

class Game : public mystic::MysticApp<Game>
{
public:

	Game();

	void OnUpdate();

	void Run();
	//void UpdatePosition(int changeX, int changeY);

	void OnKeyPress(const mystic::KeyPressed& e);

	void OnKeyRelease(const mystic::KeyReleased& e);

	void UpdateMovement();

	bool CollideWithBlueTile(int characterCoordinateX, int characterCoordinateY, mystic::Picture& character, int objectCoordinateX, int objectCoordinateY, mystic::Picture& object);

	void UpdateBackGround();
	
	void DrawInventory();


private:
	enum class Direction { up = 0, left = 1, down = 2, right = 3 } mDirection;
	enum class State { moving = 0, stopped = 1} mState;

	mystic::Picture mBackground1{ "../Assets/Pictures/Background1.png" };
	mystic::Picture mBackground2{ "../Assets/Pictures/Background2.png" };
	//mystic::Picture Inventory{ "../Assets/Pictures/Inventory.png" };//Tried to make my own inventory but couldnt load it in
	mystic::Picture Inventory{ "../Assets/Pictures/GameInventory.png" };


	bool switchBackGround2{ false };

	mystic::Picture mCharacterUp{ "../Assets/Pictures/CharacterUp.png" };
	mystic::Picture mCharacterRight{ "../Assets/Pictures/CharacterRight.png" };
	mystic::Picture mCharacterLeft{ "../Assets/Pictures/CharacterLeft.png" };
	mystic::Picture mCharacterDown{ "../Assets/Pictures/CharacterDown.png" };

	mystic::Picture BlueTile{ "../Assets/Pictures/BlueTile.png" };

	//mystic::Picture LoadingScreen{ "../Assests/Pictures/loading.png" }; doesnt work!!!
	
	bool showInventory{ false };

	int mCharacterX{ 500 }; // Initial X position of the character
	int mCharacterY{ 25 };  // Initial Y position of the character
	int mCharacterSpeed{ 5 }; // Character speed

	int mCharacterXBackground2{ 765 }; // Initial X position on Background 2
	int mCharacterYBackground2{ 350 };
};