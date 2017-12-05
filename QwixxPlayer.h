#ifndef QWIXXPLAYER
#define QWIXXPLAYER

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Player.h"
#include "Dice.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer : public Player
{
public:
	QwixxPlayer(std::string _name);
	virtual ~QwixxPlayer();
	virtual void clean(std::string _str);
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	virtual void inputAfterRoll(RollOfDice& _roll);	
	virtual int convert_to_index(std::string _str);
	virtual Color convert_to_color(std::string _str);
};

#endif