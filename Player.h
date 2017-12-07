#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <sstream>

#include "Dice.h"
#include "ScoreSheet.h"

class Player
{
protected:
	bool d_active = false;
	ScoreSheet *d_ScoreSheet;
	std::vector<Color> get_color_index_vect(std::istream& _in);
	Color convert_to_color(std::string _str);
	virtual int convert_to_index(Color _color) = 0;

public:
	Player(ScoreSheet *_ss);
	virtual ~Player() = default;
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual void inputAfterRoll(RollOfDice& _roll) = 0;	
    bool operator!();
};

#endif
