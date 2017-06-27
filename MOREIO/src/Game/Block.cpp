#include "Block.h"

Block::Block(bool _solid, float _x, float _y, float _width, float _height)
	: solid(_solid), x(_x), y(_y), width(_width), height(_height)
{
}

Block::Block()
{
}


Block::~Block()
{
}

void Block::draw(float xOffset, float yOffset)
{
	if (solid)//Empty space is reprenseted by none solid blocks
	{
		ofSetColor(128, 128, 128);
		ofRect(x + xOffset, y + yOffset, width, height);//Draws outer square
		ofSetColor(64, 64, 64);
		ofRect(x + (width / 4) + xOffset, y + (height / 4) + yOffset, width / 2, height / 2);//Draws inner square
	}
}

bool Block::collisionDetectionVert(float pX, float pY, float pWidth, float pHeight)
{
	return pX + pWidth > x && pX < x + width && pY + pHeight > y && pY < y + height && solid;
}

bool Block::collisionDetectionHorz(float pX, float pY, float pWidth, float pHeight)
{
	return pX + pWidth > x && pX < x + width && pY + pHeight > y && pY < y + height && solid;
}
