#ifndef COMMON
#define COMMON

#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"

class ScoreSheet
{
protected:
	std::string d_name;
	int d_failedThrows;
	int d_points;
	
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1) = 0;
	virtual int calcTotal() = 0;

public:

	ScoreSheet(std::string _name);
	~ScoreSheet();
	bool score(RollOfDice _dice, Color _color, int _pos = -1);
	int setTotal();
	virtual bool operator!();
	// virtual friend std::ostream& operator<<(std::ostream& _out, ScoreSheet* _sS); // TODO shore up how the polymophism works for the << operator
};


class Player
{
protected:
	bool d_active;

public:
	Player();
	~Player();
	virtual void inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual void inputAfterRoll(RollOfDice& _roll) = 0;	
};

#endif