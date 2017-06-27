#include "GeneticAlgorithm.h"

#define RANDOM_NUMBER ((float) rand() / (RAND_MAX + 1))

GeneticAlgorithm::GeneticAlgorithm()
{
}


GeneticAlgorithm::~GeneticAlgorithm()
{
}

//Finds a parent network 
int GeneticAlgorithm::roulette(vector<float> fitnesses)
{
	float totalFitness = 0.0f;//Hold the total fitness of the current set of networks
	for (int i = 0; i < fitnesses.size(); i++)
	{
		totalFitness += fitnesses[i];
	}

	float currentTotalFitness = 0.0f;

	//The number that needs to be passed to be selected, it is random because that will
	//provide genetic diversity
	float slice = RANDOM_NUMBER * totalFitness;

	for (int i = 0; i < fitnesses.size(); i++)
	{
		currentTotalFitness += fitnesses[i];

		if (currentTotalFitness >= slice)
		{
			return i;
		}
	}

	return -1;
}

//Create two child networks from two parent networks
void GeneticAlgorithm::crossover(vector<float> node1, vector<float> node2, vector<float>* new1, vector<float>* new2)
{
	vector<float> newNetwork1;
	vector<float> newNetwork2;

	if (RANDOM_NUMBER < crossOverRate)
	{
		//What portion of each parent network will make up each child network
		int crossover = (int)(RANDOM_NUMBER * (float) node1.size());

		//Creates first offspring
		for (int i = 0; i < crossover; i++)
		{
			newNetwork1.push_back(node1[i]);
		}
		for (int i = crossover; i < node2.size(); i++)
		{
			newNetwork1.push_back(node2[i]);
		}

		//Creates second offspring
		for (int i = 0; i < crossover; i++)
		{
			newNetwork2.push_back(node2[i]);
		}
		for (int i = crossover; i < node1.size(); i++)
		{
			newNetwork2.push_back(node1[i]);
		}

		*new1 = newNetwork1;
		*new2 = newNetwork2;
	}
}

//Adds small mutations to the new netowkrs
vector<float> GeneticAlgorithm::mutate(vector<float> nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (RANDOM_NUMBER < mutationRate)
		{
			nodes[i] = RANDOM_NUMBER;
		}
	}

	return nodes;
}