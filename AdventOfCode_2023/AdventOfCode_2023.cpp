#include "AdventOfCode_2023.h"

using namespace std;

int main()
{
	Day1 day1 = Day1();

	cout << "Press enter to get the result for the first Level of the day1 Challenge." << endl;
	system("pause");

	uint16_t result1_1 = day1.getResultForDay1Challenge(false);
	cout << "final result: " << result1_1 << endl;

	cout << "Press enter to get the result for the second Level of the day1 Challenge." << endl;
	system("pause");

	uint16_t result1_2 = day1.getResultForDay1Challenge(true);
	cout << "final result: " << result1_2 << endl;

	cout << "Press enter to get the result for the first Level of the day2 Challenge." << endl;
	system("pause");

	Day2 day2 = Day2();

	unsigned result2_1 = day2.sumAllIdsOfValidGames(12U, 13U, 14U);
	cout << "final result: " << result2_1 << endl;
	system("pause");

	return 0;
}
