#ifndef QWINTO_SCORE_SHEET
#define QWINTO_SCORE_SHEET

#include "Dice.h"
#include "Common.h"


class QwintoScoreSheet : public ScoreSheet
{
	QwintoRow<Color::RED> d_red;
	QwintoRow<Color::YELLOW> d_yellow;
	QwintoRow<Color::BLUE> d_blue;

public:
	QwintoScoreSheet();
	~QwintoScoreSheet();
	friend std::ostream& operator<<(std::ostream& _out, QwintoScoreSheet _sS);
}


#endif