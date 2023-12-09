#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <list>
#include "Game.h"

using namespace std;

/// <summary>
/// Class to collect the functions specifically needed to solve the Day2 challenges
/// </summary>
class Day2
{
public:
	Day2(void);
	~Day2() {};

	/// <summary>
	/// this function adds up the game Ids of all valid games - this means the max amount of pulled cubes for one color
	/// during the game has to be smaller than the given parameters
	/// </summary>
	/// <param name="maxRed">maximum amount of red cubes</param>
	/// <param name="maxGreen">maximum amount of green cubes</param>
	/// <param name="maxBlue">maximum amount of blue cubes</param>
	/// <returns>the sum of all valid game IDs</returns>
	unsigned sumAllIdsOfValidGames(unsigned maxRed, unsigned maxGreen, unsigned maxBlue);

private:

	list <Game> games;

	/// <summary>
	/// Read one line and extract the game ID for the game item
	/// </summary>
	/// <param name="line">string from the input file</param>
	/// <returns>the Game Id from the line</returns>
	unsigned getGameIDfromLine(string &line);

	/// <summary>
	/// Split the line at the ; to separate each Round of the game
	/// </summary>
	/// <param name="line">remaining string from the input file minus the game Id part</param>
	/// <param name="currentGame">the game object that has been created for this line</param>
	void splitStringPerRound(string &line, Game &currentGame);

	/// <summary>
	/// Split the cube items per color at the , per Round of the game
	/// </summary>
	/// <param name="gameRound">substring from the game for this specific round</param>
	/// <param name="currentGame">the game object that has been created for this line</param>
	void splitStringPerColor(string &gameRound, Game& currentGame);

	/// <summary>
	/// Collect all the valid Games in a list. 
	/// Valid means that this game doesn't contain more items of a color than given by the parameters
	/// </summary>
	/// <param name="maxRed">max valid number of red items</param>
	/// <param name="maxGreen">max valid number of green items</param>
	/// <param name="maxBlue">max valid number of blue items</param>
	/// <returns>a List with all valid Game objects</returns>
	list<Game> listValidGames(unsigned maxRed, unsigned maxGreen, unsigned maxBlue);

	/// <summary>
	/// Extract the number of cubes in this color from the string, and compare it to the previous values for this color
	/// in this Game.
	/// Only the maximum value will be stored
	/// </summary>
	/// <param name="colorCubes">substring from sprintStringPerColor; format <number> <color> </param>
	/// <param name="currentGame">the game object that has been created for the original input line</param>
	void setMaxValueForAllColorCubes(string &colorCubes, Game &currentGame);

	
};