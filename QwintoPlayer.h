#ifndef QWINTOPLAYER
#define QWINTOPLAYER

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Player.h"
#include "Dice.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player
{
protected:
	virtual void clean(std::string _str);
	virtual int convert_to_index(std::string _str);
	virtual Color convert_to_color(std::string _str);

public:
	QwintoPlayer(std::string _name);
	virtual ~QwintoPlayer();
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	virtual void inputAfterRoll(RollOfDice& _roll);	
};

#endif