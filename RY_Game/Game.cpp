#include "Game.h"


Game::Game()
{
	SetKeyPressedCallBack([this](const mystic::KeyPressed& e) {OnKeyPress(e);  });
	SetKeyReleasedCallBack([this](const mystic::KeyReleased& e) {OnKeyRelease(e); });
	mState = State::stopped;
}



void Game::OnKeyPress(const mystic::KeyPressed& e)
{
	if (e.GetKeyCode() == MYSTIC_KEY_RIGHT)
	{
		//mCharacterX += mCharacterSpeed;
		mDirection = Direction::right;
		mState = State::moving;
	}
	else if (e.GetKeyCode() == MYSTIC_KEY_LEFT)
	{
		//mCharacterX -= mCharacterSpeed;
		mDirection = Direction::left;
		mState = State::moving;
	}
	else if (e.GetKeyCode() == MYSTIC_KEY_UP)
	{
		//mCharacterY += mCharacterSpeed;
		mDirection = Direction::up;
		mState = State::moving;
	}
	else if (e.GetKeyCode() == MYSTIC_KEY_DOWN)
	{
		//mCharacterY -= mCharacterSpeed;
		mDirection = Direction::down;
		mState = State::moving;
	}
	else if (e.GetKeyCode() == MYSTIC_KEY_I)
		showInventory = true;

	else if (e.GetKeyCode() == MYSTIC_KEY_ESCAPE)
		showInventory = false;
}

void Game::UpdateMovement()
{
	if (mState == State::moving and switchBackGround2 == false) {
		if (mDirection == Direction::up and mState == State::moving)
			mCharacterY += mCharacterSpeed;
		else if (mDirection == Direction::down and mState == State::moving)
			mCharacterY -= mCharacterSpeed;
		else if (mDirection == Direction::left and mState == State::moving)
			mCharacterX -= mCharacterSpeed;
		else if (mDirection == Direction::right and mState == State::moving)
			mCharacterX += mCharacterSpeed;
	}
	else 
	{
		if (mDirection == Direction::up and mState == State::moving)
			mCharacterYBackground2 += mCharacterSpeed;
		else if (mDirection == Direction::down and mState == State::moving)
			mCharacterYBackground2 -= mCharacterSpeed;
		else if (mDirection == Direction::left and mState == State::moving)
			mCharacterXBackground2 -= mCharacterSpeed;
		else if (mDirection == Direction::right and mState == State::moving)
			mCharacterXBackground2 += mCharacterSpeed;
	}
}

bool Game::CollideWithBlueTile(int characterCoordinateX, int characterCoordinateY, mystic::Picture& character, int objectCoordinateX, int objectCoordinateY, mystic::Picture& object)
{
	int leftCharacter = mCharacterX;
	int rightCharacter = mCharacterX + character.GetWidth();

	int topCharacter = mCharacterY + character.GetHeight();
	int bottomCharacter = mCharacterY;

	
	int leftTile = objectCoordinateX;
	int rightTile = objectCoordinateX + object.GetWidth();

	int topTile = objectCoordinateY + object.GetHeight();
	int bottomTile = objectCoordinateY;

	
	bool xCollision = (leftCharacter < rightTile && rightCharacter > leftTile);
	bool yCollision = (topCharacter > bottomTile && bottomCharacter < topTile);

	return xCollision && yCollision;
}

void Game::UpdateBackGround()
{
	switchBackGround2 = true;
	Draw(0, 0, mBackground2);
}

void Game::DrawInventory()
{
	if (showInventory == true)
	{
		Draw(250, 200, Inventory);
	}
}



void Game::OnKeyRelease(const mystic::KeyReleased& e)
{
	mState = State::stopped;
	if (e.GetKeyCode() == MYSTIC_KEY_DOWN)
		mDirection = Direction::down;
	else if (e.GetKeyCode() == MYSTIC_KEY_UP)
		mDirection = Direction::up;
	else if (e.GetKeyCode() == MYSTIC_KEY_LEFT)
		mDirection = Direction::left;
	else if (e.GetKeyCode() == MYSTIC_KEY_RIGHT)
		mDirection = Direction::right;
}

void Game::OnUpdate()
{


	if (switchBackGround2)
	{
		UpdateBackGround();

		//Draw(mCharacterX, mCharacterY, mCharacterUp);

		UpdateMovement();

		DrawInventory();

		if (mDirection == Direction::up)
		{
			Draw(mCharacterXBackground2, mCharacterYBackground2, mCharacterUp);

		}
		else if (mDirection == Direction::down)
		{
			Draw(mCharacterXBackground2, mCharacterYBackground2, mCharacterDown);

		}
		else if (mDirection == Direction::right)
		{
			Draw(mCharacterXBackground2, mCharacterYBackground2, mCharacterRight);

		}
		else if (mDirection == Direction::left)
		{
			Draw(mCharacterXBackground2, mCharacterYBackground2, mCharacterLeft);

		}
	}
	else {


		Draw(0, 0, mBackground1);
		Draw(3, 220, BlueTile);
		Draw(3, 255, BlueTile);

		UpdateMovement();

		DrawInventory();

		if (mDirection == Direction::up)
		{
			Draw(mCharacterX, mCharacterY, mCharacterUp);

		}
		else if (mDirection == Direction::down)
		{
			Draw(mCharacterX, mCharacterY, mCharacterDown);

		}
		else if (mDirection == Direction::right)
		{
			Draw(mCharacterX, mCharacterY, mCharacterRight);

		}
		else if (mDirection == Direction::left)
		{
			Draw(mCharacterX, mCharacterY, mCharacterLeft);

		}

		if (CollideWithBlueTile(mCharacterX, mCharacterY, mCharacterUp, -105, 220, BlueTile) or
			CollideWithBlueTile(mCharacterX, mCharacterY, mCharacterUp, -105, 255, BlueTile))
		{
			UpdateBackGround();
		}
	}
	

}

void Game::Run()
{
	//Draw(0, 0, mBackground1);


	while (true)
	{
		OnUpdate();
	}
}


