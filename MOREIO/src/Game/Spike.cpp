#include "Spike.h"

Spike::Spike(float _x, float _y, float _width, float _height)
	:x(_x), y(_y), width(_width), height(_height)
{
}

Spike::Spike()
{
}


Spike::~Spike()
{
}

void Spike::draw(float xOffset, float yOffset)
{
	ofSetColor(128, 128, 128);
	ofDrawTriangle((x) + xOffset, (y + height) + yOffset, (x + width) + xOffset, (y + height) + yOffset, (x + width / 2) + xOffset, (y) + yOffset);
}

bool Spike::collisionDetection(float pX, float pY, float pWidth, float pHeight)
{
	return pX + pWidth > x && pX < x + width && pY + pHeight > y && pY < y + height;
}
