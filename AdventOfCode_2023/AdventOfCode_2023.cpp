#include "AdventOfCode_2023.h"

using namespace std;

uint8_t main()
{
	AdventOfCode_2023 advent = AdventOfCode_2023();

	cout << "Press enter to get the result for the first Level of the day1 Challenge." << endl;
	system("pause");

	uint16_t result = advent.getResultForDay1Challenge(false);
	cout << "final result: " << result << endl;

	cout << "Press enter to get the result for the second Level of the day1 Challenge." << endl;
	system("pause");

	uint16_t result2 = advent.getResultForDay1Challenge(true);
	cout << "final result: " << result2 << endl;
	system("pause");

	return 0;
}


uint16_t AdventOfCode_2023::getResultForDay1Challenge(bool withWords)
{
	uint16_t accumulatedResult = 0U;

	//read in the input for the Day1 Challenge
	ifstream day1Input;
	day1Input.open("assets\\day1Input.txt");

	char line[100];
	if (day1Input.is_open())
	{
		// get the 2-digit number out of each line and add the value to the result
		while (day1Input)
		{
			day1Input.getline(line, 100);
			accumulatedResult += getNumberResultForLine(line, withWords);
		}
		day1Input.close();
	}
	else
	{
		cout << "could not open file" << endl;
	}

	return accumulatedResult;
}

uint8_t AdventOfCode_2023::getNumberResultForLine(string line, bool withWords)
{
	uint8_t firstDigit	= getFirstDigit(line, withWords);
	uint8_t lastDigit	= getLastDigit(line, withWords);

	return (firstDigit * 10U) + lastDigit;
}

uint8_t AdventOfCode_2023::getFirstDigitInString(string line)
{
	regex re("\\d");
	smatch digits;

	regex_search(line, digits, re);

	if (digits.size() != 0)
	{
		return (uint8_t)stoi(digits[0].str()); //since we know that the match will always be a digit
	}
	else
	{
		return 0;
	}
}

uint8_t AdventOfCode_2023::getFirstDigit(string line, bool withWords)
{
	string convertedLine = line;

	// if spelled out words need to be considered,
	// convert them into actual digits before searching the string
	if (withWords) 
	{
		regex re("\(one\|two\|three\|four\|five\|six\|seven\|eight\|nine\)");
		smatch digits;

		regex_search(line, digits, re);

		string replaceValue;

		// replace the first word digit in the string if there is one
		if (digits.size() != 0)
		{
			for (uint8_t i = 0U; i < 9U; i++)
			{
				if (digits[0].str() == wordDigits[i])
				{
					replaceValue = actualDigits[i];
					break;
				}
			}

			convertedLine = regex_replace(convertedLine, regex(digits[0].str()), replaceValue);
		}
	}

	return getFirstDigitInString(convertedLine);
}

uint8_t AdventOfCode_2023::getLastDigit(string line, bool withWords)
{
	string convertedLine = line;

	// reverse the input string to search from back to front
	reverse(convertedLine.begin(), convertedLine.end());

	// if spelled out words need to be considered,
	// convert them into actual digits before searching the string
	if (withWords)
	{
		regex reverseRe("\(enin\|thgie\|neves\|xis\|evif\|ruof\|eerht\|owt\|eno\)");
		smatch revDigits;

		regex_search(convertedLine, revDigits, reverseRe);

		string replaceValue;

		// replace the last word digit in the string if there is one
		if (revDigits.size() != 0)
		{
			for (uint8_t i = 0U; i < 9U; i++)
			{
				if (revDigits[0].str() == revWordDigits[i])
				{
					replaceValue = actualDigits[i];
					break;
				}
			}

			convertedLine = regex_replace(convertedLine, regex(revDigits[0].str()), replaceValue);
		}
	}

	return getFirstDigitInString(convertedLine);
}
