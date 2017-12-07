#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"
#include "Row.h"


class ScoreSheet
{
protected:
	std::string d_name;
	int d_failedThrows;
    int d_lockedRows;
	int d_points;

	std::vector<Row*> d_scoreSheetRows;

	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1) = 0;
	virtual int calcTotal() = 0;
	virtual Row& operator[](Color _color) = 0;

public:

	ScoreSheet(std::string _name);
	virtual ~ScoreSheet() = default;
	virtual bool score(RollOfDice _dice, Color _color, int _pos = -1);
	int setTotal();
	virtual bool operator!();
	void addFailedThrow();
    
    //TODO make this part of the score function
    void addLockedRow();
    virtual std::vector<Color> getUnlockedColorsVector();
    std::string getName() { return d_name; }
    
	friend std::ostream& operator<<(std::ostream& _out, const ScoreSheet& _sS);
};


#endif
