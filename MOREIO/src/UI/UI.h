/*
This class handles all of the logic for the UI and
stores all of the UI containers, which hold other ui
elements
*/

#ifndef UI_H
#define UI_H

#include <vector>
#include "UIElement.h"
#include "Button.h"
#include "Container.h"

class UI 
{
public:
	UI(bool** loadNew, bool** loadPre, bool** loadRecent, int** score, int** generation, int** network);
	UI();
	~UI();

	void draw();
	void clicked(int x, int y);

private:
	vector<UIElement*> uiElements;
};

#endif
