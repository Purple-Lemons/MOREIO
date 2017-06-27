#ifndef TEXTRECOGNITION_H
#define TEXTRECOGNITION_H

#include "ofMain.h"
#include "../AAN/AANController.h"

class TextRecognition
{
public:
	TextRecognition();
	~TextRecognition();


private:
	void loadImage();

	ofPixels pixels;
};

#endif