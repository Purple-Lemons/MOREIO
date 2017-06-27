/*
This class contains all of the functions that train the networks, it contains genetic algorithms
that are used to find parent networks, create child networks from them and mutate the child networks
*/
#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include <iostream>
#include "GenericNode.h"

using namespace std;

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	int roulette(vector<float> fitnesses);
	void crossover(vector<float> node1, vector<float> node2, vector<float>* new1, vector<float>* new2);
	vector<float> mutate(vector<float> nodes);

private:
	float crossOverRate = 0.7;
	float mutationRate = 0.1;
};
#endif
