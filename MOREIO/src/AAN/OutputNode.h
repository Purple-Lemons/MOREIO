#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

/*
The Output layer takes input from the hidden layer and determines
whether or not to perform output actions
*/
#pragma once

#include <vector>
#include "GenericNode.h"
#include <iostream>

using namespace std;

class OutputNode : public GenericNode
{
public:
	OutputNode(int numInputs);
	OutputNode();
	~OutputNode();

	float getThreshold()
	{
		return weights[weights.size() - 1];
	}

private:
	
};

#endif

