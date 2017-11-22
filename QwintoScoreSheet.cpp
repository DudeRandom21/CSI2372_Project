#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string _name) : ScoreSheet(_name) {}


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
	int filled_cells = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (d_rowR[i] > 0)
			++filled_cells;
	}
	if (filled_cells == 9)
		current_score += d_rowR[9];
	else
		current_score += filled_cells;
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

bool QwintoScoreSheet::operator!()
{
	//checking for failed throws
	if (ScoreSheet::operator!())
		return true;

	int filled_rows = 0;

	//same as above this should loop over all the rows
	int filled_cells = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (d_rowR[i] > 0)
			++filled_cells;
	}
	if (filled_cells == 9)
		++filled_rows;
	//up to here

	if (filled_rows >= 2)
		return true;

	//if nothing no condition is met the game is not over
	return false;
}

std::ostream& operator<<(std::ostream& _out, QwintoScoreSheet _sS)
{
	_out << "Player name: " << _sS.d_name << "\t\t   Points: " << _sS.d_points << std::endl;
	_out << "              -------------------------------" << std::endl;
	_out << _sS.d_rowR;
	_out << "           ----------------------------------" << std::endl;
	_out << _sS.d_rowY;
	_out << "        ----------------------------------" << std::endl;
	_out << _sS.d_rowB;
	_out << "        -------------------------------" << std::endl;
	_out << "Failed throws: ";
	for (int i = 1; i <= _sS.d_failedThrows; ++i)
	{
		_out << i << ' ';
	}
	_out << std::endl;
}
