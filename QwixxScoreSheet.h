#ifndef QWIXX_SCORE_SHEET
#define QWIXX_SCORE_SHEET

#include "Dice.h"
#include "QwixxRow.h"
#include "ScoreSheet.h"


class QwixxScoreSheet : public ScoreSheet
{

	//TODO get all the locked Row stuff in here

protected:
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	virtual Row& operator[](Color _color);
    

public:
	QwixxScoreSheet(std::string _name);
	~QwixxScoreSheet();
    virtual bool score(RollOfDice _playDice, Color _rowColor, int _pos = -1);
	virtual bool operator!();
    virtual std::vector<Color> getUnlockedColorsVector();

};

#endif




