#ifndef QWIXX_SCORE_SHEET
#define QWIXX_SCORE_SHEET

#include "Dice.h"
#include "QwixxRow.h"
#include "ScoreSheet.h"


class QwixxScoreSheet : public ScoreSheet
{

	std::vector<Color> unlockedColorsVector;
	//TODO get all the locked Row stuff in here

protected:
	virtual bool validate(const RollOfDice _dice, const Color _color, const int _pos = -1) const;
	virtual int calcTotal() const;
	virtual Row& operator[](const Color _color);
    

public:
	QwixxScoreSheet(const std::string _name);
	~QwixxScoreSheet();
    virtual bool score(RollOfDice _playDice, Color _rowColor, int _pos = -1);
	virtual bool operator!() const;
    virtual std::vector<Color> getUnlockedColorsVector() const;

};

#endif




