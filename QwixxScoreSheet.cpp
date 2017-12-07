#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(std::string _name) : ScoreSheet(_name)
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

bool QwixxScoreSheet::validate(RollOfDice _dice, Color _color, int _pos)
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

int QwixxScoreSheet::calcTotal()
{
	int current_score = 0;
	current_score -= d_failedThrows * 5;

	for (int i = 0; i < 4; ++i){
		int filled_cells = 0;
		for (int j = 0; j < 11; ++j){
			if((*d_scoreSheetRows[i])[j] == -1){
				++filled_cells;
			}
		}

		switch(filled_cells){
            case(0):
                break;
                
			case (1):
                current_score += 1;
                break;
                
			case (2):
                current_score += 3;
                break;
                
			case (3):
                current_score += 6;
                break;
                
			case (4):
                current_score += 10;
                break;
                
			case (5):
                current_score += 15;
                break;
                
			case (6):
                current_score += 21;
                break;
                
			case (7):
                current_score += 28;
                break;
                
			case (8):
                current_score += 36;
                break;
                
			case (9):
                current_score += 45;
                break;
                
			case (10):
                current_score += 55;
                break;
                
			case (11):
                current_score += 66;
                break;
                
			case (12):
                current_score += 78;
                break;
		}
	}
	return current_score;
}

bool QwixxScoreSheet::operator!()
{
	//checking for common fail conditions (failed throws)
	if (ScoreSheet::operator!())
		return true;

	//checking for locked Rows
    return (d_lockedRows >= 2);
}

Row& QwixxScoreSheet::operator[](Color _color)
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



















