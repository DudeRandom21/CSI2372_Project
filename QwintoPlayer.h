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
	virtual int convert_to_index(const Color _color) const;

public:
	QwintoPlayer(const std::string _name);
	virtual ~QwintoPlayer();
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	virtual void inputAfterRoll(const RollOfDice& _roll);
};

#endif