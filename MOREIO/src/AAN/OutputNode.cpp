#include "OutputNode.h"

OutputNode::OutputNode(int numInputs)
{
	//All weights initially start random
	for (int i = 0; i < numInputs + 1; i++)//One more to store the threshold, maybe change this
	{
		weights.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	}
}

OutputNode::OutputNode()
{
}


OutputNode::~OutputNode()
{
}