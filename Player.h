#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>

#include "Dice.h"
#include "Common.h"

class Player
{
protected:
	bool d_active = false;
	ScoreSheet *d_ScoreSheet;

public:
	Player(ScoreSheet *_ss);
	virtual ~Player() = default;
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual void inputAfterRoll(RollOfDice& _roll) = 0;	
};

#endif