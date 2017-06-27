/*
The spike is used to provided something the player must avoid in the game, if the player 
touches the spike, they will die
*/

#ifndef SPIKE_H
#define SPIKE_H

#include "ofMain.h"

class Spike
{
public:
	Spike(float _x, float _y, float _width, float _height);
	Spike();
	~Spike();

	void draw(float xOffset, float yOffset);
	bool collisionDetection(float pX, float pY, float pWidth, float pHeight);

private:
	float x;
	float y;
	float width;
	float height;
};

#endif

