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
	std::vector<Color> get_color_index_vect(std::istream& _in) const;
	Color convert_to_color(const std::string _str) const;
	virtual int convert_to_index(const Color _color) const = 0;

public:
	Player(ScoreSheet *_ss);
	virtual ~Player() = default;
	virtual RollOfDice inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual void inputAfterRoll(const RollOfDice& _roll) = 0;	
    bool operator!() const;
    int printScoreSheet() const;
    std::string getName() const;
};

#endif
