#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "Common.h"
#include "QwintoRow.h"


class QwintoScoreSheet : public ScoreSheet
{


public:
	QwintoScoreSheet(std::string _name);
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	virtual bool operator!();


	friend std::ostream& operator<<(std::ostream& _out, const QwintoScoreSheet& _sS);
};


#endif