/*
This class is the parent to all ui elements
*/
#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <string>
#include "ofMain.h"

class UIElement 
{
public:
	UIElement();
	virtual ~UIElement();

	virtual void clicked(int x, int y);

	virtual void draw()=0;//All ui elements are drawn in slightly different ways

protected:
	int x;
	int y;
	int width;
	int height;

	//The text displayed in the element
	string label;

	//Colors of the box the ui is drawn in
	ofColor outlineColor;
	ofColor backgroundColor;
	ofColor textColor;

	ofTrueTypeFont font;
};

#endif
