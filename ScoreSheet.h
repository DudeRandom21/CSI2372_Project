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

	virtual bool validate(const RollOfDice _dice, const Color _color, const int _pos = -1) const = 0;
	virtual int calcTotal() const = 0;
	virtual Row& operator[](const Color _color) = 0;

public:

	ScoreSheet(const std::string _name);
	virtual ~ScoreSheet() = default;
	virtual bool score(RollOfDice _dice, Color _color, int _pos = -1) = 0;
	int setTotal();
	virtual bool operator!() const;
	void addFailedThrow();
    
    //TODO make this part of the score function
    void addLockedRow();
    virtual std::vector<Color> getUnlockedColorsVector() const;
    std::string getName() const { return d_name; }
    
	friend std::ostream& operator<<(std::ostream& _out, const ScoreSheet& _sS);
};


#endif
