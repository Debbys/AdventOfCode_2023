#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>

using namespace std;

/// <summary>
/// Class to collect the functions specifically needed to solve the Day1 challenges
/// </summary>
class Day1
{

public:
	Day1() {};

	~Day1() {};

	/// <summary>
	/// solve the task of getting the first and the last digit out of every line of day1Input.txt
	/// to build the 2-digit numbers and add them up to the final value
	/// </summary>
	/// <param name="withWords">shall spelled out digits also be considered?</param>
	/// <returns>final accumulated number</returns>
	uint16_t getResultForDay1Challenge(bool withWords);


private:

	string wordDigits[9] = { "one", "two", "three" , "four", "five", "six", "seven", "eight", "nine" };
	string revWordDigits[9] = { "eno", "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin" };
	string actualDigits[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	/// <summary>
	/// get the 2-digit number for the requested string
	/// </summary>
	/// <param name="line">one line of the day1Input.txt</param>
	/// <param name="withWords">shall spelled out digits also be considered?</param>
	/// <returns>2-digit number consisting out of the first and the last digit contained in the file</returns>
	uint8_t getNumberResultForLine(string line, bool withWords);

	/// <summary>
	/// returns the first digit in the provided line,
	/// depending on the bool input spelled out digits will also be considered
	/// </summary>
	/// <param name="line">line that shall be searched for digits</param>
	/// <param name="withWords">shall spelled out digits also be considered?</param>
	/// <returns>the first digit in the string</returns>
	uint8_t getFirstDigit(string line, bool withWords);

	/// <summary>
	/// returns the last digit in the provided line,
	/// depending on the bool input spelled out digits will also be considered
	/// </summary>
	/// <param name="line">line that shall be searched for digits</param>
	/// <param name="withWords">shall spelled out digits also be considered</param>
	/// <returns>the last digit in the string</returns>
	uint8_t getLastDigit(string line, bool withWords);

	/// <summary>
	/// get the first digit that is contained in a given string
	/// </summary>
	/// <param name="line">given string</param>
	/// <returns>the first digit in the string</returns>
	uint8_t getFirstDigitInString(string line);

};