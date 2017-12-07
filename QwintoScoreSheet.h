#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "QwintoRow.h"
#include "ScoreSheet.h"


class QwintoScoreSheet : public ScoreSheet
{

protected:
	virtual bool validate(const RollOfDice _dice, const Color _color, const int _pos = -1) const;
	virtual int calcTotal() const;
	virtual Row& operator[](const Color _color);

public:
	QwintoScoreSheet(const std::string _name);
	~QwintoScoreSheet();
	virtual bool score(RollOfDice _dice, Color _color, int _pos = -1);
	virtual bool operator!() const;

};


#endif