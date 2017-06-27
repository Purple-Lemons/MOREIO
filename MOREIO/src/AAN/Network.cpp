#include "Network.h"

Network::Network(int _inputSize, int _hiddenSize, int outputSize)
{
	inputSize = _inputSize;
	hiddenSize = _hiddenSize;

	//Creates an input layer
	for(int i = 0; i < inputSize; i++)
	{
		nodes.push_back(InputNode());
	}

	//Creates a hidden layer
	for(int i = 0; i < hiddenSize; i++)
	{
		nodes.push_back(HiddenNode(inputSize));
	}

	//Creates and outputlayer
	for(int i = 0; i < outputSize; i++)
	{
		outputs.push_back(false);
		nodes.push_back(OutputNode(hiddenSize));
	}
}

Network::Network()
{
}


Network::~Network()
{
}

void Network::controlOutput(int i, bool state)
{
	outputs[i] = state;
}

//Returns weights of every layer
vector<float> Network::getAllWeights()
{
	vector<float> weights;

	for (int i = inputSize; i < nodes.size(); i++)
	{
		vector<float>* nodeWeights = nodes[i].getWeights();
		for (int j = 0; j < nodeWeights->size(); j++)
		{
			weights.push_back((*nodeWeights)[j]);
		}
	}

	return weights;
}

void Network::inputLayer(vector<float> inputs)
{
	vector<float> outputs;

	for (int i = 0; i < inputSize; i++)
	{
		outputs.push_back(nodes[i].input(inputs[i]));
	}

	hiddenLayer(outputs);
}

void Network::hiddenLayer(vector<float> inputs)
{
	vector<float> outputs;

	for (int i = inputSize; i < inputSize + hiddenSize; i++)
	{
		outputs.push_back(nodes[i].input(&inputs));
	}
	outputLayer(outputs);
}

void Network::outputLayer(vector<float> inputs)
{
	vector<float> outputs;

	for (int i = inputSize + hiddenSize; i < nodes.size(); i++)
	{
		outputs.push_back(nodes[i].input(&inputs));
	}
	
	for (int i = 0; i < outputs.size(); i++)
	{
		if (outputs[i] > nodes[hiddenSize + inputSize + i].getThreshold())
		{
			controlOutput(i, true);
		}
		else {
			controlOutput(i, false);
		}
	}
}

void Network::setNewWeights(vector<float> newWeights)
{
	for (int i = 0; i < hiddenSize * (inputSize + 1); i += inputSize + 1)
	{
		vector<float> hiddenWeights;

		for (int j = 0; j < inputSize + 1; j++)
		{
			hiddenWeights.push_back(newWeights[i + j]);
		}
		nodes[(i / (inputSize + 1)) + inputSize].setNewWeights(hiddenWeights);
	}

	for (int i = hiddenSize * (inputSize + 1); i < newWeights.size(); i += hiddenSize + 1)
	{
		vector<float> outputWeights;
		for (int j = 0; j < hiddenSize + 1; j++)
		{
			outputWeights.push_back(newWeights[i + j]);
		}
		int pos = ((i - (hiddenSize * (inputSize + 1))) / (hiddenSize + 1)) + inputSize + hiddenSize;
		nodes[pos].setNewWeights(outputWeights);
	}
}
