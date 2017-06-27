#include "TextBox.h"

TextBox::TextBox(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font, int** _labelVar)
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

	//label is stored in the UI and can be accesed from elsewhere
	*_labelVar = &labelVar;
}

TextBox::TextBox()
{
}

TextBox::~TextBox()
{
}

void TextBox::draw()
{
	//Draws main box
	ofSetColor(backgroundColor);
	ofDrawRectangle(x, y, width, height);

	//Draws box outline
	ofSetColor(outlineColor);
	ofNoFill();
	ofDrawRectangle(x, y, width, height);
	ofFill();

	//Draws text
	ofSetColor(textColor);

	int lV = labelVar;
	string full = label + std::to_string(lV);
	font.drawString(full, x + 12, y + height / 3);
}
