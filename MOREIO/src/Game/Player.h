/*
This class handles all of the logic for the player in the game
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "ofMain.h"

class Player
{
public:
	Player();
	Player(float _x, float _y, float _width, float _height);
	~Player();

	void draw(float xOffset, float yOffset);
	void calculate(bool collided);

	void move(float dx, float dy);
	void fall();
	void jump();
	void stopFalling();

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

	float getWidth()
	{
		return width;
	}

	float getHeight()
	{
		return height;
	}

	float getYSpeed()
	{
		return ySpeed;
	}

	float getXSpeed()
	{
		return xSpeed;
	}

	bool getFalling()
	{
		return falling;
	}

private:
	float x;
	float y;
	float width;
	float height;

	float ySpeed = 0.0f;
	float xSpeed = 0.0f;

	bool falling = false;//If the player is falling it cannot jump
};

#endif

