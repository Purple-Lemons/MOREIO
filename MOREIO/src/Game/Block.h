/*
This class handles all of the logic for the blocks in the game
*/
#ifndef BLOCK_H
#define BLOCK_H

#include "ofMain.h"

class Block
{
public:
	Block(bool _solid, float _x, float _y, float _width, float _height);
	Block();
	~Block();

	void draw(float xOffset, float yOffset);

	bool collisionDetectionVert(float pX, float pY, float pWidth, float pHeight);
	bool collisionDetectionHorz(float pX, float pY, float pWidth, float pHeight);

	bool getSolid()
	{
		return solid;
	}

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

private:
	bool solid;//A none solid block is just empty space

	float x;
	float y;
	float width;
	float height;
};

#endif

