#include "Game.h"

Game::Game() {
	levelWidth = 88;
	levelHeight = 18;

	cellWidth = 64;
	cellHeight = 64;

	//Creates the level from the block data
	for (int i = 0; i <= levelWidth * levelHeight; i++)
	{
		float x = (i % levelWidth) * cellWidth;
		float y = (i / levelWidth) * cellWidth;

		if (blockData[i] == 1)//Solid block
		{
			blocks.push_back(new Block(true, x, y, cellWidth, cellHeight));
		}
		if (blockData[i] == 2)//Spike
		{
			spikes.push_back(new Spike(x, y, cellWidth, cellHeight));
			blocks.push_back(new Block(false, x, y, cellWidth, cellHeight));
		}
		else//Empty space
		{
			blocks.push_back(new Block(false, x, y, cellWidth, cellHeight));
		}
	}

	font.loadFont("verdana.ttf", 16);

	reset();

	int inputSize = getSurroundingBlocks().size();//The size of the information the AAN sees
	AAN = AANController(inputSize, false);

	ui = UI(&loadNew, &loadPre, &loadRecent, &scoreUIPointer, &generationUIPointer, &networkUIPointer);
	*scoreUIPointer = 0;
}

Game::~Game() {
}

void Game::reset()
{
	player = Player(64 * 9 + 1, 7 * 64, 64, 64);

	score = 0;

	//Places camera on the player
	cameraX = 64 * 9 + 1;
	cameraY = 200;

	//Adds an offset so that player is more central on screen
	xOffset = 300;
	yOffset = 100;

	//Resets lastTime (used for timing out the game after inactivity
	lastTime = time(NULL) + 10;

	gameOver = false;
}

void Game::hardReset(int loadFile)
{
	player = Player(64 * 9 + 1, 7 * 64, 64, 64);

	score = 0;

	//Places camera on the player
	cameraX = 64 * 9 + 1;
	cameraY = 200;

	//Adds an offset so that player is more central on screen
	xOffset = 300;
	yOffset = 100;

	//Resets lastTime (used for timing out the game after inactivity
	lastTime = time(NULL) + 10;

	gameOver = false;

	int inputSize = getSurroundingBlocks().size();
	AAN = AANController(inputSize, loadFile);
}

//--------------------------------------------------------------
void Game::calculate() {
	if (!gameOver)
	{
		cameraX = player.getX();//Moves the level along with player movement

		AAN.calculate(getSurroundingBlocks());//The ANN determines what to do next

		networkControl();

		bool collidedVert = false;
		bool collidedHorz = false;
		collisions(&collidedVert, &collidedHorz);

		if (!collidedVert) {
			player.fall();
		}
		else
		{
			player.stopFalling();
		}

		player.calculate(collidedHorz);

		if (player.getX() - (64 * 9) > score)
		{
			score = player.getX() - (64 * 9);
			lastTime = time(NULL);
		}
		else
		{
			//If the player hasn't moved in a while, the game times out
			if (time(NULL) - lastTime > 2)
			{
				cout << "Timed Out" << endl;
				gameOver = true;
			}
		}
	}

	if (gameOver)
	{
		AAN.gameOver(score);
		reset();
	}

	//If the UI buttons have been pressed
	if (*loadNew)
	{
		hardReset(0);
		*loadNew = false;
	}
	else if (*loadPre)
	{
		hardReset(2);
		*loadPre = false;
	}
	else if (*loadRecent)
	{
		hardReset(1);
		*loadRecent = false;
	}

	//Updates the text boxes in the UI
	*scoreUIPointer = score;
	*generationUIPointer = AAN.getGenerationPos();
	*networkUIPointer = AAN.getNetworkPos();
}

//Gets control inputs from the network after calculation
void Game::networkControl()
{
	vector<bool> states = AAN.getCurrentNetwork()->getOutputs();

	//Act upon the keys the network has pressed
	if (states[1])//Move left
	{
		player.move(-10, 0);
	}
	if (states[2])//Move right
	{
		player.move(10, 0);
	}
	if (states[0])//jump
	{
		if (!player.getFalling())
		{
			player.jump();
		}
	}
	if (!states[1] && !states[2])
	{
		player.move(0, 0);
	}
}

//Checks if the player has collided with blocks or spikes
void Game::collisions(bool *collidedVert, bool *collidedHorz)
{
	//Vertical block collisions
	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i]->collisionDetectionVert(player.getX(), player.getY() + player.getYSpeed(), player.getWidth(), player.getHeight()))
		{
			*collidedVert = true;
		}
	}

	//Horizontal block collisions
	for (int i = 0; i < blocks.size(); i++)
	{
		if ((blocks[i]->getY() / cellHeight) - (player.getY() / cellHeight) < 1)
		{
			if (blocks[i]->collisionDetectionHorz(player.getX() + player.getXSpeed(), player.getY() + player.getYSpeed(), player.getWidth(), player.getHeight() - 10))
			{
				*collidedHorz = true;
			}
		}
	}

	//Spikes collisions
	for (int i = 0; i < spikes.size(); i++)
	{
		if (spikes[i]->collisionDetection(player.getX() + player.getXSpeed(), player.getY() + player.getYSpeed(), player.getWidth(), player.getHeight()))
		{
			gameOver = true;
		}
	}
}

//--------------------------------------------------------------
void Game::draw() {

	ofBackground(0);

	if (!gameOver) {
		player.draw(xOffset - cameraX, yOffset - cameraY);

		for (int i = 0; i < blocks.size(); i++)
		{
			blocks[i]->draw(xOffset - cameraX, yOffset - cameraY);
		}

		for (int i = 0; i < spikes.size(); i++)
		{
			spikes[i]->draw(xOffset - cameraX, yOffset - cameraY);
		}
	}
	else
	{
		font.drawString("GAME OVER", 400, 400);
	}

	drawNetwork();

	ui.draw();
}

//Draws the nodes of the network on screen
void Game::drawNetwork()
{
	vector<GenericNode>* nodes = AAN.getCurrentNetwork()->getNodes();

	ofSetColor(255, 255, 255, 128);
	int y = 190;

	int i = 0;

	//Draws input layer
	for (i = 0; i < AAN.getCurrentNetwork()->getInputSize(); i++)
	{
		if ((*nodes)[i].getState())//If the node is activated it lights up
		{
			ofSetColor(255, 255, 255, 255);
			ofDrawCircle(100, y, 4, 4);
			ofSetColor(255, 255, 255, 128);
		}
		else
		{
			ofDrawCircle(100, y, 4, 4);
		}

		y += 12;
	}

	y = 100;

	//Draws hidden layer
	for (i = i; i < AAN.getCurrentNetwork()->getInputSize() + AAN.getCurrentNetwork()->getHiddenSize(); i++)
	{
		if ((*nodes)[i].getState())
		{
			ofSetColor(255, 255, 255, 255);
			ofDrawCircle(500, y, 4, 4);
			ofSetColor(255, 255, 255, 128);
		}
		else
		{
			ofDrawCircle(500, y, 4, 4);
		}

		y += 12;
	}

	y = 325;

	//Draws outputlayer
	for (i = i; i < nodes->size(); i++)
	{
		if ((*nodes)[i].getState())
		{
			ofSetColor(255, 255, 255, 255);
			ofDrawCircle(900, y, 4, 4);
			ofSetColor(255, 255, 255, 128);
		}
		else
		{
			ofDrawCircle(900, y, 4, 4);
		}

		y += 12;
	}
}

//--------------------------------------------------------------
//Gets all of the block around the player - used to tell the AAN what's around it
vector<float> Game::getSurroundingBlocks()
{
	vector<float> surroundingBlocks;

	//The bounds for the surrounding blocks
	int minX = player.getX() - cellWidth * 3;
	int minY = player.getY() - cellWidth * 3;

	int maxX = player.getX() + cellWidth * 3;
	int maxY = player.getY() + cellWidth * 3;

	for (int i = 0; i < levelWidth * levelHeight; i++)
	{
		//The absolutes position of the block
		int x = (i % levelWidth) * cellWidth;
		int y = (i / levelWidth) * cellWidth;

		if (x > minX && x < maxX && y > minY && y < maxY)
		{
			//No block = 0.1, Block = 0.5, Spike = 1.0
			if (blockData[i] == 0)
			{
				surroundingBlocks.push_back(0.1f);
			}
			else
			{
				surroundingBlocks.push_back((float)blockData[i] / 2);
			}
		}
	}

	return surroundingBlocks;
}

void Game::keyPressed(int key)
{
}

void Game::mousePressed(int x, int y)
{
	ui.clicked(x, y);
}
