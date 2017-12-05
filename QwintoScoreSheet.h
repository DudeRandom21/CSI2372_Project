#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "QwintoRow.h"
#include "ScoreSheet.h"


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