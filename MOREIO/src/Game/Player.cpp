#include "Player.h"

Player::Player(float _x, float _y, float _width, float _height)
	:x(_x), y(_y), width(_width), height(_height)
{

}

Player::Player()
{
}


Player::~Player()
{
}

void Player::draw(float xOffset, float yOffset)
{
	ofSetColor(255, 0, 0);
	ofRect(x + xOffset, y + yOffset, width, height);
}

void Player::calculate(bool collided)
{
	y += ySpeed;

	if (!collided)
	{
		x += xSpeed;
	}
}

void Player::move(float dx, float dy)
{
	xSpeed = dx;
}

void Player::fall()
{
	falling = true;
	ySpeed += 0.25;//Accelerated player under gravity
}

void Player::jump()
{
	ySpeed = -7;
	y -= 10;//If the player is clipped into a block it needs to be moved a bit
}

void Player::stopFalling()
{
	falling = false;
	ySpeed = 0;
}
