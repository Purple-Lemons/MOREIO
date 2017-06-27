#include "GenericNode.h"

GenericNode::GenericNode()
{
}


GenericNode::~GenericNode()
{
}

//This method is called every frame and determines whether or not to send signal to
//the next layer based on the previous layer
float GenericNode::input(vector<float>* inputs)
{
	float activation = 0.0f;//Current input level

	for (int i = 0; i < inputs->size(); i++)
	{
		activation += (*inputs)[i] * weights[i];
	}

	activation = activation / inputs->size();

	//If the activation is greater than the threshold the signal is send
	if (activation > weights[inputs->size()])
	{
		state = true;
		return 1.0f;
	}

	state = false;
	return 0.0f;
}

void GenericNode::setNewWeights(vector<float> newWeights)
{
	weights = newWeights;
}