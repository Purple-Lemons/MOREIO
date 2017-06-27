/*
This class performs the operations of each indvidual network
*/
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "InputNode.h"
#include "HiddenNode.h"
#include "OutputNode.h"
#include "GenericNode.h"

class Network
{
public:
	Network(int inputSize, int hiddenSize, int outputSize);
	Network();
	~Network();

	void controlOutput(int, bool);

	void inputLayer(vector<float> inputs);
	void hiddenLayer(vector<float> inputs);
	void outputLayer(vector<float> inputs);

	void setNewWeights(vector<float> weights);

	void setFitness(int _fitness)
	{
		fitness = _fitness;
	}

	vector<float> getAllWeights();

	float getFitness()
	{
		return fitness;
	}

	vector<bool> getOutputs()
	{
		return outputs;
	}

	vector<GenericNode>* getNodes()
	{
		return &nodes;
	}

	int getInputSize()
	{
		return inputSize;
	}

	int getHiddenSize()
	{
		return hiddenSize;
	}

private:
	vector<GenericNode> nodes;
	int inputSize;
	int hiddenSize;
	int outputSize;

	vector<bool> outputs;//Stores the outputs from the ANN, in this case these represent the controls for the game

	float fitness = 0;
};

#endif

