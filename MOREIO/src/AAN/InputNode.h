/*
The input node layer handles and interprets input from the game
and passes it to the hidden layer
*/
#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <iostream>
#include "GenericNode.h"

using namespace std;

class InputNode : public GenericNode
{
public:
	InputNode();
	~InputNode();

	void output();

private:

	float value;

};

#endif

