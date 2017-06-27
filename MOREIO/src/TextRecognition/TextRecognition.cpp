#include "TextRecognition.h"

TextRecognition::TextRecognition()
{
	loadImage();
}

TextRecognition::~TextRecognition()
{

}

void TextRecognition::loadImage()
{
	ofImage img;
	img.loadImage("images/1.png");
	pixels = img.getPixelsRef();

	ofColor black = ofColor(0, 0, 0, 255);
	ofColor white = ofColor(255, 255, 255, 255);

	for (int i = 0; i < img.getWidth() * img.getHeight(); i++)
	{
		if (pixels.getColor(i) == black)
		{
			cout << i << " - black";
		}
		if (pixels.getColor(i) == white)
		{
			cout << i << " - white";
		}
		cout << endl;
	}
}