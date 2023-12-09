#include "Day1.h"

uint16_t Day1::getResultForDay1Challenge(bool withWords)
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

uint8_t Day1::getNumberResultForLine(string line, bool withWords)
{
	uint8_t firstDigit = getFirstDigit(line, withWords);
	uint8_t lastDigit = getLastDigit(line, withWords);

	return (firstDigit * 10U) + lastDigit;
}

uint8_t Day1::getFirstDigitInString(string line)
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

uint8_t Day1::getFirstDigit(string line, bool withWords)
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

uint8_t Day1::getLastDigit(string line, bool withWords)
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
