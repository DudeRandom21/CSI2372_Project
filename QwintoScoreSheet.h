#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "Common.h"
#include "QwintoRow.h"


class QwintoScoreSheet : public ScoreSheet
{

protected:
	virtual bool validate(RollOfDice _dice, Color _color, int _pos = -1);
	virtual int calcTotal();
	virtual Row& operator[](Color _color);

public:
	QwintoScoreSheet(std::string _name);
	~QwintoScoreSheet();
	virtual bool operator!();

};


#endif