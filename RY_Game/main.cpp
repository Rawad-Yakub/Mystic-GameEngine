#include "Mystic.h"

#include <iostream>

class MyGame : public mystic::MysticApp<MyGame>
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Mystic Running" << std::endl;
	}
};

MYSTIC_APPLICATION_START(MyGame);