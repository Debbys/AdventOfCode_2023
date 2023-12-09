#include "Day2.h"

Day2::Day2(void)
{
	//initialize all Games by reading in the input
	ifstream day2Input;
	day2Input.open("assets\\day2Input.txt");

	char line[255];
	if (day2Input.is_open())
	{
		// get the 2-digit number out of each line and add the value to the result
		while (day2Input)
		{
			day2Input.getline(line, 255);
			string castLine = (string) line;
			unsigned currentGameID = getGameIDfromLine(castLine);
			Game currentGame(currentGameID);
			splitStringPerRound(castLine,currentGame);
			games.push_back(currentGame);
		}
		day2Input.close();
	}
	else
	{
		cout << "could not open file" << endl;
	}
}

unsigned Day2::sumAllIdsOfValidGames(unsigned maxRed, unsigned maxGreen, unsigned maxBlue)
{
	list<Game> validGames = listValidGames(maxRed, maxGreen, maxBlue);
	unsigned accumulatedIds = 0;

	for (Game currentGame : validGames)
	{
		accumulatedIds += currentGame.getID();
	}
	return accumulatedIds;
}

 unsigned Day2::getGameIDfromLine(string &line)
{
	 string delimiter = ":";
	 string game_name = line.substr(0, line.find(delimiter));

	 regex re("\\d\+");
	 smatch game_id;

	 regex_search(game_name, game_id, re);

	 line.erase(0, line.find(delimiter) + delimiter.length()); //erase everything up until the first delimiter

	 if (game_id.size() != 0)
	 {
		 return stoi(game_id.str());
	 }
	 else
	 {
		 return 0;
	 }
}

 void Day2::splitStringPerRound(string& line, Game &currentGame)
 {
	 size_t pos = 0;
	 string delimiter = ";";

	 while ((pos = line.find(delimiter)) != std::string::npos)
	 {
		 string gameRound = line.substr(0, pos); //the round in which the elf pulled cubes from his bag

		 splitStringPerColor(gameRound, currentGame);
		 line.erase(0, line.find(delimiter) + delimiter.length()); //erase everything up until the first delimiter
	 }
	 splitStringPerColor(line, currentGame); // last round of the game without delimiter
 }

 void Day2::splitStringPerColor(string& gameRound, Game& currentGame)
 {
	 size_t pos = 0;
	 string delimiter = ",";

	 while ((pos = gameRound.find(delimiter)) != std::string::npos)
	 {
		 string colorCubes = gameRound.substr(0, pos); //cubes that are pulled in this round

		 setMaxValueForAllColorCubes(colorCubes, currentGame);

		 gameRound.erase(0, gameRound.find(delimiter) + delimiter.length()); //erase everything up until the first delimiter
	 }
	 setMaxValueForAllColorCubes(gameRound, currentGame); //last item of the gameRound where the delimiter is missing
 }

 list<Game> Day2::listValidGames(unsigned maxRed, unsigned maxGreen, unsigned maxBlue)
 {
	 list <Game> gamesToCount;
	 for (Game currentGame : games)
	 {
		 if ((maxRed >= currentGame.getMaxAmountRed()) && (maxGreen >= currentGame.getMaxAmountGreen()) \
			 && (maxBlue >= currentGame.getMaxAmountBlue()))
		 {
			 gamesToCount.push_back(currentGame);
		 }
	 }
	 return gamesToCount;
 }

 void Day2::setMaxValueForAllColorCubes(string &colorCubes, Game &currentGame)
 {
	 regex color("\(red\|green\|blue\)");
	 smatch match_color;

	 regex_search(colorCubes, match_color, color);

	 regex amount("\\d\+");
	 smatch match_amount;

	 regex_search(colorCubes, match_amount, amount);

	 if ((match_color.size() != 0) && (match_amount.size() != 0))
	 {
		 if (match_color[0].str() == "red")
		 {
			 currentGame.setMaxAmountRed(stoi(match_amount[0].str())); //since we know that the match will always be a number
		 }
		 else if (match_color[0].str() == "green")
		 {
			 currentGame.setMaxAmountGreen(stoi(match_amount[0].str())); //since we know that the match will always be a number
		 }
		 else if (match_color[0].str() == "blue")
		 {
			 currentGame.setMaxAmountBlue(stoi(match_amount[0].str())); //since we know that the match will always be a number
		 }
		 else
		 {
			 cout << "unhandled color detected:" << match_color[0].str() << endl;
		 }
	 }
	 else
	 {
		 // nothing to be matched
	 }
 }
