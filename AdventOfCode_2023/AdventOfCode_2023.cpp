// AdventOfCode_2023.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "AdventOfCode_2023.h"

using namespace std;

uint8_t main()
{
	cout << "Press enter to get the result for the first Level of the day1 Challenge." << endl;
	system("pause");

	AdventOfCode_2023 advent = AdventOfCode_2023();
	uint16_t result = advent.getResultForDay1ChallengeLevel1();

	cout << "final result: " << result << endl;

	system("pause");

	return 0;
}


uint16_t AdventOfCode_2023::getResultForDay1ChallengeLevel1(void)
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
			accumulatedResult += getNumberResultForLine(line);
		}
		day1Input.close();
	}
	else
	{
		cout << "could not open file" << endl;
	}

	return accumulatedResult;
}

uint8_t AdventOfCode_2023::getNumberResultForLine(string line)
{
	uint8_t firstDigit	= getFirstDigit(line);
	uint8_t lastDigit	= getLastDigit(line);

	return (firstDigit * 10U) + lastDigit;
}

uint8_t AdventOfCode_2023::getFirstDigit(string line)
{
	regex re("\\d");
	smatch digits;

	regex_search(line, digits, re);

	if (digits.size() != 0)
	{
		return (uint8_t) stoi(digits[0].str()); //since we know that the match will always be a digit
	}
	else
	{
		return 0;
	}

	
}

uint8_t AdventOfCode_2023::getLastDigit(string line)
{
	regex re("\\d");
	smatch digits;
	string revline = line;

	// reverse the input string to search from back to front
	reverse(revline.begin(), revline.end());

	regex_search(revline, digits, re);

	if (digits.size() != 0)
	{
		return (uint8_t) stoi(digits[0].str()); //since we know that the match will always be a digit
	}
	else
	{
		return 0;
	}
}
