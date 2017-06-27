/*
This class is a UIElement Button which allows users to interact
with the program, primarily for loading new networks
*/
#ifndef BUTTON_H
#define BUTTON_H

#include "UIElement.h"

class Button : public UIElement 
{
public:
	Button(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font, bool** _action);
	Button();
	~Button();

	void clicked(int x, int y);

	void draw();

	bool action;//Toggles when the button is pressed

private:
	int timer = 0;//Used to time the buttons flash when clicked
};

#endif
