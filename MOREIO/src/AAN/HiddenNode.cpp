#include "HiddenNode.h"

HiddenNode::HiddenNode(int _numInputs)
{
	numInputs = _numInputs;

	//All weights initially start random, the threshold is also stored with the weights
	for (int i = 0; i < numInputs + 1; i++)
	{
		weights.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	}
}

HiddenNode::HiddenNode()
{
	
}

HiddenNode::~HiddenNode()
{
}

