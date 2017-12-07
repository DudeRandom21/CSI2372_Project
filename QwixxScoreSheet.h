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
    virtual bool score(RollOfDice _playDice, Color _rowColor, int _pos = -1);

public:
	QwixxScoreSheet(std::string _name);
    
	~QwixxScoreSheet();
	virtual bool operator!();

};

#endif




