#ifndef QWIXX_SCORE_SHEET
#define QWIXX_SCORE_SHEET

#include "Dice.h"
#include "QwixxRow.h"
#include "ScoreSheet.h"



class QwixxScoreSheet : public ScoreSheet
{

protected:
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	virtual Row& operator[](Color _color);

public:
	QwixxScoreSheet(std::string _name);
	~QwixxScoreSheet();
	virtual bool operator!();

};

#endif