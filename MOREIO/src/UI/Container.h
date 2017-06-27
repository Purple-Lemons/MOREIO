/*
Containers are used to house other ui elements, it allows thing to be grouped
easily and consistently as it automatically adds elements in a consistent
position
*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include "UIElement.h"
#include "Button.h"
#include "TextBox.h"

class Container : public UIElement
{
public:
	Container(int _x, int _y, int _width, int _height, string _label, ofColor _oColor, ofColor _bColor, ofColor _tColor, ofTrueTypeFont _font);
	Container();
	~Container();

	void clicked(int x, int y);
	void draw();

	//Adds ui elements to the container
	void addButton(string, bool** _action);
	void addTextBox(string, int** labelVar);

private:
	vector<UIElement*> uiElements;
	
	//Parameters for elements house in the container
	int elemWidth;
	int elemHeight;
	int elemMargin;
	int numElems;
};

#endif
