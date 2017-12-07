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
protected:
	virtual int convert_to_index(const Color _color) const;

public:
	QwixxPlayer(const std::string _name);
	virtual ~QwixxPlayer();
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll);
	virtual void inputAfterRoll(const RollOfDice& _roll);
};









#endif
