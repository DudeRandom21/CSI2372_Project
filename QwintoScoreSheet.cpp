#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string _name) : ScoreSheet(_name)
{
	d_row.reserve(3);

	d_row.push_back( new QwintoRow<Color::RED>() );
	d_row.push_back( new QwintoRow<Color::YELLOW>() );
	d_row.push_back( new QwintoRow<Color::BLUE>() );
}

QwintoScoreSheet::~QwintoScoreSheet()
{
	for(auto& row : d_row)
	{
		delete row;
	}
}

bool QwintoScoreSheet::validate(RollOfDice _dice, Color _color, int _pos)
{
	switch (_color)
	{
		case Color::RED:
		return d_row[0]->validate(_pos, _dice);

		case Color::YELLOW:
		return d_row[1]->validate(_pos, _dice);

		case Color::BLUE:
		return d_row[2]->validate(_pos, _dice);
	}
}


int QwintoScoreSheet::calcTotal()
{
	int current_score = 0;
	current_score -= d_failedThrows * 5;


	for (int i = 0; i < 3; ++i)
	{
		int filled_cells = 0;
		for (int j = 0; j < 10; ++j)
		{
			if ((*d_row[i])[j] > 0)
				++filled_cells;
		}
		if (filled_cells == 9)
			current_score += (*d_row[i])[9];
		else
			current_score += filled_cells;
	}

	for (int i = 0; i < 8; ++i)
	{
		if ((*d_row[0])[i] < 0 && (*d_row[1])[i+1] < 0 && (*d_row[2])[i+2] < 0)
		{
			if (i == 0 || i == 7)
				current_score += (*d_row[2])[i+2];
			else if (i == 1 || i == 5)
				current_score += (*d_row[0])[i];
			else
				current_score += (*d_row[1])[i+1];
		}
	}
	return current_score;
}

bool QwintoScoreSheet::operator!()
{
	//checking for common fail conditions (failed throws)
	if (ScoreSheet::operator!())
		return true;

	int filled_rows = 0;

	for (int i = 0; i < 3; ++i)
	{
		int filled_cells = 0;
		for (int j = 0; j < 10; ++j)
		{
			if ((*d_row[i])[j] > 0)
				++filled_cells;
		}
		if (filled_cells == 9)
			++filled_rows;
	}

	if (filled_rows >= 2)
		return true;

	//if no condition is met the game is not over
	return false;
}

Row& QwintoScoreSheet::operator[](Color _color)
{
	switch(_color)
	{
		case Color::RED :
			return *d_row[0];

		case Color::YELLOW :
			return *d_row[1];

		case Color::BLUE :
			return *d_row[2];
	}
}