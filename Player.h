#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>

#include "Dice.h"
#include "ScoreSheet.h"

class Player
{
protected:
	bool d_active = false;
	ScoreSheet *d_ScoreSheet;
	virtual void clean(std::string _str) = 0;
	virtual int convert_to_index(std::string _str) = 0;
	virtual Color convert_to_color(std::string _str) = 0;

public:
	Player(ScoreSheet *_ss);
	virtual ~Player() = default;
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual void inputAfterRoll(RollOfDice& _roll) = 0;	

	//TODO: Delete this
	virtual void printSS() = 0;
};

#endif