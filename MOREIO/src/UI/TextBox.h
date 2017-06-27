/*
This class is a ui element that simply displays text
*/
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "UIElement.h"

class TextBox : public UIElement
{
public:
	TextBox(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font, int** _labelVar);
	TextBox();
	~TextBox();

	void draw();

private:
	int labelVar;//Used to display changing things in a text box, such as score
};

#endif
