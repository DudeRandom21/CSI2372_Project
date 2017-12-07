#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(const std::string _name) : ScoreSheet(_name)
{
	d_scoreSheetRows.reserve(4);

	d_scoreSheetRows.push_back( new QwixxRow<std::vector<int>, Color::RED>() );
	d_scoreSheetRows.push_back( new QwixxRow<std::vector<int>, Color::YELLOW>() );
	d_scoreSheetRows.push_back( new QwixxRow<std::list<int>, Color::GREEN>() );
	d_scoreSheetRows.push_back( new QwixxRow<std::list<int>, Color::BLUE>() );
}

QwixxScoreSheet::~QwixxScoreSheet()
{
	for(auto& row : d_scoreSheetRows)
	{
		delete row;
	}
}

bool QwixxScoreSheet::validate(const RollOfDice _dice, const Color _color, const int _pos) const
{
	if (_color != Color::RED && _color != Color::YELLOW && _color != Color::GREEN && _color != Color::BLUE) {
		return false;
	}
	else {
		switch (_color)
		{
		case Color::RED:
			return d_scoreSheetRows[0]->validate(_pos, _dice);

		case Color::YELLOW:
			return d_scoreSheetRows[1]->validate(_pos, _dice);

		case Color::GREEN:
			return d_scoreSheetRows[2]->validate(_pos, _dice);

		case Color::BLUE:
			return d_scoreSheetRows[3]->validate(_pos, _dice);
		default:
			return false;
		}
	}
}

int QwixxScoreSheet::calcTotal() const
{
	int current_score = 0;
	current_score -= d_failedThrows * 5;

	for (int i = 0; i < 4; ++i)
	{
		int filled_cells = 0;
		for (int j = 0; j < 11; ++j)
		{
			if((*d_scoreSheetRows[i])[j] == -1)
			{
				++filled_cells;
			}
		}

		//sum of filled cells count
		for (int j = 0; j < filled_cells; ++j)
		{
			current_score += j;
		}
	}
	return current_score;
}

bool QwixxScoreSheet::operator!() const
{
	//checking for common fail conditions (failed throws)
	if (ScoreSheet::operator!())
		return true;

	//checking for locked Rows
    return (d_lockedRows >= 2);
}

Row& QwixxScoreSheet::operator[](const Color _color)
{
	switch(_color)
	{
		case Color::RED :
			return *d_scoreSheetRows[0];

		case Color::YELLOW :
			return *d_scoreSheetRows[1];

		case Color::GREEN :
			return *d_scoreSheetRows[2];

		case Color::BLUE :
			return *d_scoreSheetRows[3];
		default:
			return *d_scoreSheetRows[0];
	}
}


bool QwixxScoreSheet::score(RollOfDice _playDice, Color _rowColor, int _val){
    int _pos = -1;
    for (int i = 0; i < 10 ; i++){
        if ((*this)[_rowColor][i] == _val){
            _pos = i;
        }
    }
    
    if(validate( _playDice, _rowColor, _pos ))
    {
        Row& row = (*this)[_rowColor];
        row[_pos] = -1;
        setTotal();
        return true;
    }
    
    return false;
}

std::vector<Color> QwixxScoreSheet::getUnlockedColorsVector() const {
    std::vector<Color> lr;
    for (auto row : d_scoreSheetRows){
        if (!row->getLockedStatus()){
            lr.push_back(row->getColor());
        }
    }
    return lr;
}
