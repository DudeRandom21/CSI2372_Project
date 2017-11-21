#include "QwintoScoreSheet.h"

// QwintoScoreSheet::QwintoScoreSheet(std::string _name)
// {
// 	QwintoRow<Color::RED> rowR;
// 	QwintoRow<Color::YELLOW> rowY;
// 	QwintoRow<Color::BLUE> rowB;

// }

bool QwintoScoreSheet::validate(RollOfDice _dice, Color _color, int _pos)
{
	switch (_color)
	{
		case Color::RED:
		return d_rowR.validate(_pos, _dice);

		case Color::YELLOW:
		return d_rowY.validate(_pos, _dice);

		case Color::BLUE:
		return d_rowB.validate(_pos, _dice);
	}
}


int QwintoScoreSheet::calcTotal()
{
	int current_score = 0;
	current_score -= d_failedThrows * 5;


	//essentially this should be a loop over the three rows but I can't seem to figure how to loop over templates
	int filed_cells;
	for (int i = 0; i < 10; ++i)
	{
		if (d_rowR[i] > 0)
			++filed_cells;
	}
	if (filed_cells == 9)
		current_score += d_rowR[9];
	else
		current_score += filed_cells;
	//up to here


	for (int i = 0; i < 8; ++i)
	{
		if (d_rowR[i] < 0 && d_rowY[i+1] < 0 && d_rowB[i+2] < 0)
		{
			if (i == 0 || i == 7)
				current_score += d_rowB[i+2];
			else if (i == 1 || i == 5)
				current_score += d_rowR[i];
			else
				current_score += d_rowY[i+1];
		}
	}
}
