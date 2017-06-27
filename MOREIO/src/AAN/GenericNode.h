/*
Each type of node performs fairly similar actions so can inherit
from GenericNode
*/
#ifndef GENERICNODE_H
#define GENERICNODE_H

#include <vector>

using namespace std;

class GenericNode
{
public:
	GenericNode();
	virtual ~GenericNode();

	vector<float>* getWeights()
	{
		return &weights;
	}

	float getThreshold()
	{
		return weights[weights.size() - 1];
	}

	virtual float input(vector<float>* inputs);
	virtual float input(float);
	virtual void setNewWeights(vector<float>);

	bool getState()
	{
		return state;
	}

protected:

	vector<float> weights;
	bool state = false;//This is used to draw the network on the screen

private:
	
};
#endif