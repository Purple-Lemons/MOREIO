#include "Container.h"

Container::Container(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font)
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

	elemMargin = 10;
	elemWidth = 200;
	elemHeight = height - 2 * elemMargin;
	numElems = 0;
}

Container::Container() 
{
}

Container::~Container()
{
}

void Container::draw()
{
	//Draw the container itself
	ofSetColor(backgroundColor);
	ofDrawRectangle(x, y, width, height);

	ofSetColor(outlineColor);
	ofNoFill();
	ofDrawRectangle(x, y, width, height);
	ofFill();

	ofSetColor(textColor);
	font.drawString(label, x + 12, y + height / 3);

	//Draws the ui elements contained in the container
	for (int i = 0; i < uiElements.size(); i++)
	{
		uiElements[i]->draw();
	}
}

void Container::clicked(int x, int y)
{
	for (int i = 0; i < uiElements.size(); i++)
	{
		uiElements[i]->clicked(x, y);
	}
}

void Container::addButton(string label, bool** action)
{
	int elemX = x + elemMargin + (numElems * elemMargin) + (numElems * elemWidth);
	uiElements.push_back(new Button(elemX, y + 10, elemWidth, elemHeight, label, outlineColor, backgroundColor, textColor, font, action));

	numElems++;
}

void Container::addTextBox(string label, int** labelVar)
{
	int elemX = x + elemMargin + (numElems * elemMargin) + (numElems * elemWidth);
	uiElements.push_back(new TextBox(elemX, y + 10, elemWidth, elemHeight, label, outlineColor, backgroundColor, textColor, font, labelVar));

	numElems++;
}
