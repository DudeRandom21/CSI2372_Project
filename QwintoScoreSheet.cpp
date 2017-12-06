#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string _name) : ScoreSheet(_name)
{
	d_scoreSheetRows.reserve(3);

	d_scoreSheetRows.push_back( new QwintoRow<Color::RED>() );
	d_scoreSheetRows.push_back( new QwintoRow<Color::YELLOW>() );
	d_scoreSheetRows.push_back( new QwintoRow<Color::BLUE>() );
}

QwintoScoreSheet::~QwintoScoreSheet()
{
	for(auto& row : d_scoreSheetRows)
	{
		delete row;
	}
}

bool QwintoScoreSheet::validate(RollOfDice _dice, Color _color, int _pos)
{
	bool rowValidate = false;
	int red, yellow, blue;
	switch (_color)
	{
		case Color::RED:
		//validate function from row
		rowValidate = d_scoreSheetRows[0]->validate(_pos, _dice);
		//check for stacked same values
		if(_pos < 9)
		{
			rowValidate = rowValidate && (*d_scoreSheetRows[1])[_pos+1] != _dice;
			if (_pos < 8)
				rowValidate = rowValidate && (*d_scoreSheetRows[2])[_pos+2] != _dice;
		}
		break;

		case Color::YELLOW:
		rowValidate = d_scoreSheetRows[1]->validate(_pos, _dice);
		if(_pos < 9)
			rowValidate = rowValidate && (*d_scoreSheetRows[2])[_pos-1] != _dice;
		if (_pos > 0)
			rowValidate = rowValidate && (*d_scoreSheetRows[0])[_pos-1] != _dice;
		break;

		case Color::BLUE:
		rowValidate = d_scoreSheetRows[2]->validate(_pos, _dice);
		if(_pos > 0)
		{
			rowValidate = rowValidate && (*d_scoreSheetRows[1])[_pos-1] != _dice;
			if (_pos > 1)
				rowValidate = rowValidate && (*d_scoreSheetRows[2])[_pos-2] != _dice;
		}
		break;
	}
	return rowValidate;
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
			if ((*d_scoreSheetRows[i])[j] > 0)
				++filled_cells;
		}
		if (filled_cells == 9)
			current_score += (*d_scoreSheetRows[i])[9];
		else
			current_score += filled_cells;
	}

	for (int i = 0; i < 8; ++i)
	{
		if ((*d_scoreSheetRows[0])[i] < 0 && (*d_scoreSheetRows[1])[i+1] < 0 && (*d_scoreSheetRows[2])[i+2] < 0)
		{
			if (i == 0 || i == 7)
				current_score += (*d_scoreSheetRows[2])[i+2];
			else if (i == 1 || i == 5)
				current_score += (*d_scoreSheetRows[0])[i];
			else
				current_score += (*d_scoreSheetRows[1])[i+1];
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
			if ((*d_scoreSheetRows[i])[j] > 0)
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
			return *d_scoreSheetRows[0];

		case Color::YELLOW :
			return *d_scoreSheetRows[1];

		case Color::BLUE :
			return *d_scoreSheetRows[2];
            
        case Color::GREEN :
            return *d_scoreSheetRows[0];
            
        case Color::WHITE :
            return *d_scoreSheetRows[0];
            
	}
}
