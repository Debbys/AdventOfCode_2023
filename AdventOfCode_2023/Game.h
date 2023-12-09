#pragma once

#include <cmath>

using namespace std;

/// <summary>
/// class to store the id and the maximum amount of cubes per color and game
/// </summary>
class Game
{
public:
	Game(unsigned ID);
	~Game() {};

	/// <summary>
	/// Getter for the game ID
	/// </summary>
	/// <param name=""></param>
	/// <returns>ID of the game</returns>
	unsigned getID(void);

	/// <summary>
	/// Getter for the max amount of red cubes pulled in this game
	/// </summary>
	/// <param name=""></param>
	/// <returns>max amount of red cubes pulled in this game</returns>
	unsigned getMaxAmountRed(void);

	/// <summary>
	/// Getter for the max amount of green cubes pulled in this game
	/// </summary>
	/// <param name=""></param>
	/// <returns>max amount of green cubes pulled in this game</returns>
	unsigned getMaxAmountGreen(void);

	/// <summary>
	/// Getter for the max amount of blue cubes pulled in this game
	/// </summary>
	/// <param name=""></param>
	/// <returns>max amount of blue cubes pulled in this game</returns>
	unsigned getMaxAmountBlue(void);

	/// <summary>
	/// Setter for the max amount of red cubes pulled in this game.
	/// This setter does not set the value of the parameter automatically. 
	/// Instead it first compared whether the previous value is actually higher and then stores the higher value of both.
	/// </summary>
	/// <param name="redCubes">current amount of red cubes, from current game round</param>
	void setMaxAmountRed(unsigned redCubes);

	/// <summary>
	/// Setter for the max amount of green cubes pulled in this game.
	/// This setter does not set the value of the parameter automatically. 
	/// Instead it first compared whether the previous value is actually higher and then stores the higher value of both.
	/// </summary>
	/// <param name="redCubes">current amount of green cubes, from current game round</param>
	void setMaxAmountGreen(unsigned greenCubes);

	/// <summary>
	/// Setter for the max amount of blue cubes pulled in this game.
	/// This setter does not set the value of the parameter automatically. 
	/// Instead it first compared whether the previous value is actually higher and then stores the higher value of both.
	/// </summary>
	/// <param name="redCubes">current amount of blue cubes, from current game round</param>
	void setMaxAmountBlue(unsigned blueCubes);

private:
	unsigned ID;
	unsigned maxAmountRed{ 0 };
	unsigned maxAmountGreen{ 0 };
	unsigned maxAmountBlue{ 0 };
};