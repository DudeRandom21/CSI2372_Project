#ifndef COMMON
#define COMMON

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Dice.h"
#include "Row.h"


class ScoreSheet
{
protected:
	std::string d_name;
	int d_failedThrows;
	int d_points;

	std::vector<Row*> d_row;
	
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1) = 0;
	virtual int calcTotal() = 0;
	virtual Row& operator[](Color _color) = 0;

public:

	ScoreSheet(std::string _name);
	virtual ~ScoreSheet() = default;
	bool score(RollOfDice _dice, Color _color, int _pos = -1);
	int setTotal();
	virtual bool operator!();
	
	friend std::ostream& operator<<(std::ostream& _out, const ScoreSheet& _sS);
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