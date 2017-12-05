#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Dice.h"

#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"

// #include "Qwixx.h"
// #include "QwixxRow.h"
// #include "QwixxScoreSheet.h"

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to Qwinto/Qwixx" << std::endl;

	std::cout << "Please select game version" << std::endl;
	std::cout << "Qwinto (1), Qwixx(2)" << std::endl;
	int gameVers = 0;
	std::cin >> gameVers;

	int playerNum = 0;
	std::cout << "How many players?" << std::endl;
	std::cin >> playerNum;

	std::vector<std::string> playerNames;
	std::string name;


	for (int i = 0; i < playerNum; i++) {
		std::cout << "Player " << i + 1 << " Name: " << std::flush;
		std::cin >> name;
		playerNames.push_back(name);
	}



	// Qwinto Game
	if (gameVers == 0) {
		for (auto vObj : playerNames) {
			QwintoPlayer player(vObj);
		}

		while (false) { // TODO End condition?

		}
	}


//TODO: uncomment this
	// // Qwixx Game
	// else if (gameVers == 1) {
	// 	for (auto vObj : playerNames) {
	// 		QwixxPlayer player(vObj);
	// 	}

	// 	while () { // TODO End condition?

	// 	}
	// }

	



		/*
		Ask player to choose game version, number of players and names of players.
			Create the corresponding players and RollOfDice for the game.
			while end condition is not reached
				next player takes a turn i.e., becomes active
				get input from active player before roll
				roll dice and show result
				print scoresheet of active player
				get input from active player after roll
				score dice according to input from active player
				loop over all non - active players
				print scoresheet of non - active player
				get input from non - active player
				score dice according to input
				loop over all players
				calculate points for player
				print scoresheet
				print overall winner
		*/
}
	