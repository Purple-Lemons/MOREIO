/*
The Hidden nodes take input from the input layer and determine wheter or
not to pass a signal to the output layer
*/
#ifndef HIDDENNODE_H
#define HIDDENNODE_H

#include <vector>
#include "GenericNode.h"
#include <iostream>

using namespace std;

class HiddenNode : public GenericNode
{
public:
	HiddenNode(int _numInputs);
	HiddenNode();
	~HiddenNode();

private:
	int numInputs;
};
#endif
