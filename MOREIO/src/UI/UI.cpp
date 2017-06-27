#include "UI.h"

UI::UI(bool** loadNew, bool** loadPre, bool** loadRecent, int** score, int** generation, int** network)
{
	ofColor oColor = ofColor(255, 255, 255);
	ofColor bColor = ofColor(32, 32, 32);
	ofColor tColor = ofColor(255, 0, 0);

	ofTrueTypeFont font;
	font.loadFont("verdana.ttf", 14);


	//Adds a button container to the top left of the screen
	uiElements.push_back(new Container(0, 0, 640, 80, "", oColor, bColor, tColor, font));
	((Container*)uiElements[0])->addButton("Load Pre Trained \nNetwork", loadPre);
	((Container*)uiElements[0])->addButton("Load Fresh \nNetwork", loadNew);
	((Container*)uiElements[0])->addButton("Load Most Recent \nNetwork", loadRecent);

	//Adds the information boxes to the right of the screen
	uiElements.push_back(new Container(650, 0, 640, 80, "", oColor, bColor, tColor, font));
	((Container*)uiElements[1])->addTextBox("Score: ", score);
	((Container*)uiElements[1])->addTextBox("Generation: ", generation);
	((Container*)uiElements[1])->addTextBox("Network: ", network);
}

UI::UI()
{
}

UI::~UI()
{
}

void UI::draw()
{
	for (int i = 0; i < uiElements.size(); i++)
	{
		uiElements[i]->draw();
	}
}

void UI::clicked(int x, int y)
{
	for (int i = 0; i < uiElements.size(); i++)
	{
		uiElements[i]->clicked(x, y);
	}
}
