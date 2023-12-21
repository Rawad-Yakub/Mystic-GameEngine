#include "Mystic.h"
#include "Game.h"

/*
#include <iostream>

class MyGame : public mystic::MysticApp<MyGame>
{
public:

	MyGame()
	{
		SetKeyPressedCallBack([this](const mystic::KeyPressed& e) {OnKeyPress(e);  });
	}
	virtual void OnUpdate() override
	{
		//std::cout << "Mystic Running" << std::endl;
		Draw(mUnit);
	}

	void OnKeyPress(const mystic::KeyPressed& e)
	{
		if (e.GetKeyCode() == MYSTIC_KEY_RIGHT)
			mUnit.UpdateXCoords(50);
		else if (e.GetKeyCode() == MYSTIC_KEY_LEFT)
			mUnit.UpdateXCoords(-50);
	}

private:
	mystic::Picture pic{ "../Assets/Pictures/test.png" };

	int x{ 100 };
	int y{ 100 };


	mystic::Unit mUnit{ "../Assets/Pictures/test.png", 100, 500 };


};
*/
MYSTIC_APPLICATION_START(Game);