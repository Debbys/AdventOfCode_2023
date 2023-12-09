// AdventOfCode_2023.h: Header for the main class used to solve the AdventOfCode_2023 tasks
#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>

using namespace std;

/// <summary>
/// Main Class to collect all the functions needed to solve the AdventOfCode_2023 challenges
/// </summary>
class AdventOfCode_2023
{

public:
	AdventOfCode_2023() {};

	~AdventOfCode_2023() {};

	/// <summary>
	/// solve the task of getting the first and the last digit out of every line of day1Input.txt
	/// to build the 2-digit numbers and add them up to the final value
	/// </summary>
	/// <param name=""></param>
	/// <returns>final accumulated number</returns>
	uint16_t getResultForDay1ChallengeLevel1(void);	

private:

	/// <summary>
	/// get the 2-digit number for the requested string
	/// </summary>
	/// <param name="line">one line of the day1Input.txt</param>
	/// <returns>2-digit number consisting out of the first and the last digit contained in the file</returns>
	uint8_t getNumberResultForLine(string line);

	/// <summary>
	/// get the first digit that is contained in a given string
	/// </summary>
	/// <param name="line">given string</param>
	/// <returns>the first digit in the string</returns>
	uint8_t getFirstDigit(string line);

	/// <summary>
	/// get the last digit that is contained in a given string
	/// </summary>
	/// <param name="line">given string</param>
	/// <returns>the last digit in the string</returns>
	uint8_t getLastDigit(string line);
};
