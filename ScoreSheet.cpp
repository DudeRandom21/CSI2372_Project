#include "ScoreSheet.h"


// Class Scoresheet
ScoreSheet::ScoreSheet(std::string _name) : d_name(_name), d_failedThrows(0), d_lockedRows(0), d_points(0) {}

bool ScoreSheet::score(RollOfDice _dice, Color _color, int _pos)
{
    if(validate( _dice, _color, _pos ))
    {
    	Row& row = (*this)[_color];
    	row[_pos] = _dice;  // this is probably going to have to be changed when we implement Qwixx because _pos = -1
    	setTotal();
    	return true;
    }

    return false;
}

int ScoreSheet::setTotal(){
    d_points = calcTotal();
    return d_points;
}

bool ScoreSheet::operator!()
{
	if(d_failedThrows >= 4)
		return true;
	return false;
}

void ScoreSheet::addFailedThrow() {++d_failedThrows;}

void ScoreSheet::addLockedRow() { ++d_lockedRows; }

std::ostream& operator<<(std::ostream& _out, const ScoreSheet& _sS)
{
	_out << "Player name: " << _sS.d_name << "\t\t   Points: " << _sS.d_points << std::endl;

	for(const auto& row : _sS.d_scoreSheetRows)
	{
		_out << "---------------------------------------------" << std::endl;
		_out << *row;
	}

	_out << "---------------------------------------------" << std::endl;
	_out << "Failed throws: ";
	for (int i = 1; i <= _sS.d_failedThrows; ++i)
	{
		_out << i << ' ';
	}
	_out << std::endl;

	return _out;
}
