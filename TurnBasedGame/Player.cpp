#include "Player.h"

Player::Player(float aX, float aY) : GameObject()
{
	myX = aX;
	myY = aY;
	mySprite.SetTexture("Sprites/spr_link_sheet.png", 9);
}

Player::~Player()
{
}

void Player::Update()
{
	if (KeyboardCheck('a'))
	{
		myX--;
	}
	if (KeyboardCheck('w'))
	{
		myY--;
	}
	if (KeyboardCheck('s'))
	{
		myY++;
	}
	if (KeyboardCheck('d'))
	{
		myX++;
	}
}

void Player::Draw()
{
	GameObject::Draw();
}
