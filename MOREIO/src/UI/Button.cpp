#include "Button.h"

Button::Button(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font, bool** _action)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	label = _label;
	outlineColor = _oColor;
	backgroundColor = _bColor;
	textColor = _tColor;
	font = _font;

	//The action is stored in the UI and a pointer is stored somewhere else so that it can
	//be changed in the button easily and accesed elsewhere
	action = false;
	*_action = &action;
}

Button::Button() 
{
}

Button::~Button()
{
}

void Button::draw()
{
	//Times the button flash when clicked
	if (timer == 0) {
		ofSetColor(backgroundColor);
	}
	else
	{
		ofSetColor(ofColor(128, 128, 128));
		timer--;
	}

	ofDrawRectangle(x, y, width, height);//Draws main box

	ofSetColor(outlineColor);
	ofNoFill();
	ofDrawRectangle(x, y, width, height);//Draws outloine of box
	ofFill();

	ofSetColor(textColor);
	font.drawString(label, x + 12, y + height / 3);//Draws text
}

void Button::clicked(int mouseX, int mouseY)
{
	if (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height) {
		action = true;
		timer = 5;
	}
}
