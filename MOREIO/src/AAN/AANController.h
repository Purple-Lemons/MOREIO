/*
This class handles the whole neural network system, it creates new sets of networks, loads old ones,
cycles them while playing the game and trains them.
*/
#ifndef AANCONTROLLER_H
#define AANCONTROLLER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Network.h"
#include "GeneticAlgorithm.h"

using namespace std;

class AANController
{
public:
	AANController(int, int);
	AANController();
	~AANController();

	void calculate(vector<float> input);
	void evolve();

	Network* getCurrentNetwork()
	{
		return &(networks[currentNetwork]);
	}

	void saveNetwork();
	void loadNetwork(string path);

	void gameOver(int score);

	int getNetworkPos()
	{
		return currentNetwork;
	}

	int getGenerationPos()
	{
		return currentGeneration;
	}

private:
	vector<Network> networks;//The neural networks 

	GeneticAlgorithm gA;//The class that trains the networks

	int population = 20;//The number of networks in each generation

	int currentNetwork;

	int currentGeneration;
};
#endif
