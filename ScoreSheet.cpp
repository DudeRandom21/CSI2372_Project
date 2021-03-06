#include "ScoreSheet.h"


// Class Scoresheet
ScoreSheet::ScoreSheet(std::string _name) : d_name(_name), d_failedThrows(0), d_lockedRows(0), d_points(0) {}

std::vector<Color> ScoreSheet::getUnlockedColorsVector() const {
    std::vector<Color> lr;
    for (auto row : d_scoreSheetRows){
        if (!row->getLockedStatus()){
            lr.push_back(row->getColor());
        }
    }
    return lr;
}


int ScoreSheet::setTotal(){
    d_points = calcTotal();
    return d_points;
}

bool ScoreSheet::operator!() const
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
