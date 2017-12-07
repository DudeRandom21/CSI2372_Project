#ifndef TESTING

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Dice.h"

#include "QwintoPlayer.h"
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"

#include "QwixxPlayer.h"
#include "QwixxRow.h"
#include "QwixxScoreSheet.h"


int main(int argc, char const *argv[])
{
	std::vector<Player*> players;
	RollOfDice rd;

	std::cout << "Welcome to Qwinto/Qwixx" << std::endl;

	std::cout << "Please select game version" << std::endl;
	std::cout << "Qwinto (1), Qwixx(2)" << std::endl;
	//TODO: loop back if input is invalid
	int gameVers = 0;
	std::cin >> gameVers;
	std::cin.ignore(256, '\n');

	int playerNum = 0;
	std::cout << "How many players?" << std::endl;
	std::cin >> playerNum;
	std::cin.ignore(256, '\n');

	std::vector<std::string> playerNames;
	std::string name;
    std::cout << std::endl;

	for (int i = 0; i < playerNum; i++) {
		std::cout << "Player " << i + 1 << " Name: " << std::flush;
		std::cin >> name;
		std::cin.ignore(256, '\n');
		playerNames.push_back(name);
	}
    std::cout << std::endl;

	players.reserve(playerNum);

	// Qwinto Game
	if (gameVers == 1)
	{
		for (auto name : playerNames) {
			players.push_back(new QwintoPlayer(name));
		}
		rd.push_back(Dice(Color::RED));
		rd.push_back(Dice(Color::YELLOW));
		rd.push_back(Dice(Color::BLUE));
	}

	 // Qwixx Game
	 else if (gameVers == 2)
	 {
	 	for (auto name : playerNames) {
	 		players.push_back(new QwixxPlayer(name));
	 	}
	 	rd.push_back(Dice(Color::RED));
	 	rd.push_back(Dice(Color::YELLOW));
	 	rd.push_back(Dice(Color::GREEN));
	 	rd.push_back(Dice(Color::BLUE));
	 	rd.push_back(Dice(Color::WHITE_1));
	 	rd.push_back(Dice(Color::WHITE_2));
	 }
    bool endCond = false;
	while (!endCond) {
        
		for(auto active_player : players)
		{
			RollOfDice current_roll = active_player->inputBeforeRoll(rd);
			for(auto player : players)
			{
                player->inputAfterRoll(current_roll);
			}
		}
        
        //Checking end Condition
        for(auto player : players){
            endCond = endCond || !*player;
        }        
	}

	//print ScoreSheets and Display Winner
	int max = 0, score;
	std::string winner;
	for(auto player : players)
	{
		score = player->printScoreSheet();
		if (score > max)
		{
			max = score;
			winner = player->getName();
		}
	}

	std::cout << "Winner :" << winner << '!' << std::endl;

	//delete players
	for(auto player : players)
		delete player;

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
	
	return 0;
}

#endif