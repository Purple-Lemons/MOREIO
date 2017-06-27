#include "AANController.h"

AANController::AANController(int inputSize, int loadFile)
{
	gA = GeneticAlgorithm();
	currentNetwork = 0;
	currentGeneration = 0;

	//Creates new set of networks
	for(int i = 0; i < population; i++)
	{
		networks.push_back(Network(inputSize, inputSize + inputSize / 2, 3));
	}

	if (loadFile == 1) {//Loads the most recent version
		loadNetwork("weights.txt");
	}
	else if (loadFile == 2) {//Loads a pre prepared version
		loadNetwork("weightsPerma.txt");
	}
}

AANController::AANController()
{
}

AANController::~AANController()
{
}

//This method is called each frame and determines what to do next in the game
void AANController::calculate(vector<float> input)
{
	networks[currentNetwork].inputLayer(input);
}

//When every network in a generation has run this method is called which trains
//the networks so based on how they did in this generation
void AANController::evolve()
{
	currentGeneration++;

	vector<vector<float>> weights;//All of the weights of the current networks
	vector<float> fitnesses;//The game scores of the networks

	vector<vector<float>> newWeights;//The weights that will be generated for the next generation 

	//Get all current weights and fitnesses
	for (int i = 0; i < networks.size(); i++)
	{
		weights.push_back(networks[i].getAllWeights());
		fitnesses.push_back(networks[i].getFitness());
	}

	int currentPop = 0;
	while (currentPop < population)
	{
		//Finds two parent networks to create new ones
		int parent1 = gA.roulette(fitnesses);
		int parent2 = gA.roulette(fitnesses);

		//The weights of the new networks
		vector<float> offSpring1;
		vector<float> offSpring2;

		//Combines the weights as if they were DNA to create two new networks
		gA.crossover(weights[parent1], weights[parent2], &offSpring1, &offSpring2);

		//If the crossover has been succesful
		if (offSpring1.size() > 0 && offSpring2.size() > 0)
		{
			//Adds random changes to the new networks
			offSpring1 = gA.mutate(offSpring1);
			offSpring2 = gA.mutate(offSpring2);

			newWeights.push_back(offSpring1);
			newWeights.push_back(offSpring2);
			currentPop += 2;
		}
	}

	//Sets the weights of the networks to the new weights
	for (int i = 0; i < newWeights.size(); i++)
	{
		networks[i].setNewWeights(newWeights[i]);
	}

	//Write weights to file for future use
	saveNetwork();
}

//Called when the game is lost, steps to the next network
void AANController::gameOver(int score)
{
	//If all networks in this generation have run
	if (currentNetwork == population - 1)
	{
		networks[currentNetwork].setFitness(score);
		currentNetwork = 0;
		evolve();
	}
	else {
		networks[currentNetwork].setFitness(score);
		currentNetwork++;
	}

}

//Saves the weights of the current networks to a text file for future use
void AANController::saveNetwork()
{
	vector<vector<float>> weights;//All weights in the networks

	//Gets all weights
	for (int i = 0; i < networks.size(); i++)
	{
		weights.push_back(networks[i].getAllWeights());
	}

	//Turns the weight data into a string to be written to file
	string data = "";
	for (int i = 0; i < weights.size(); i++)
	{
		for (int j = 0; j < weights[i].size(); j++)
		{
			data += to_string((weights[i])[j]);
			data += "\n";
		}
	}
	
	//Writes the data to text file
	ofstream file;
	file.open("weights.txt", ios::trunc);
	file << data;
	file.close();
}

//Loads previus networks from  file
void AANController::loadNetwork(string path)
{
	vector<vector<float>> weights;
	vector<float> data;

	string line;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			data.push_back(stof(line));
		}
	}

	//Splits the data up into each network
	for (int i = 0; i < population; i++)
	{
		vector<float> weightSet;
		weights.push_back(weightSet);

		int currentStart = (data.size() / population) * i;
		int currentEnd = (data.size() / population) * (i + 1);
		for (int j = currentStart; j < currentEnd; j++)
		{
			weights[i].push_back(data[j]);
		}
	}
	
	//Adds the weights to the networks
	for (int i = 0; i < weights.size(); i++)
	{
		networks[i].setNewWeights(weights[i]);
	}
}
