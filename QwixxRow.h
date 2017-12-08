#ifndef QWIXX_ROW
#define QWIXX_ROW

#include <iomanip>

#include "Row.h"
#include "Dice.h"


template <class rowType, const Color d_c>
class QwixxRow : public Row
{
    rowType d_row;

protected:
	virtual void print(std::ostream& _out) const;

public:
	QwixxRow();
	bool validate(const int _index, const RollOfDice roll);
    virtual Color getColor() { return d_c; }
    virtual int & operator[](const int _index);
	virtual const int & operator[](const int _index) const;
};


template<class rowType, const Color d_c>
QwixxRow<rowType, d_c>::QwixxRow()
{
    _locked = false;
    
	if ((d_c == Color::RED) || (d_c == Color::YELLOW))
        for (int i = 2; i < 13; i++) {
            d_row.push_back(i);
		}
	if ((d_c == Color::GREEN) || (d_c == Color::BLUE))
		for (int i = 12; i > 1; i--) {
            d_row.push_back(i);
		}
}

template <typename rowType, const Color d_c>
bool QwixxRow<rowType, d_c>::validate(const int _index, const RollOfDice _roll)
{
    int val = (*this)[_index];
    int count = 0;
    
    int op1 = 0;
    int op2 = 0;
    
    for (auto d : _roll){
        Color dieColor = d.d_color;
        int d_val = d.d_face;
        
        
        if (dieColor == Color::WHITE_1 || dieColor == WHITE_2){
            count += d_val;
        }
        
        if (dieColor == Color::WHITE_1){
            op1 += d_val;
        }
        if (dieColor == Color::WHITE_2){
            op2 += d_val;
        }
        
        if (dieColor == d_c){
            op1 += d_val;
            op2 += d_val;
        }
        
    }
    
    if(val != count && val != op1 && val != op2){
        return false;
    }
                      

	if (_index < 0 || _index > 10)
		return false;

	if ((*this)[_index] == -1)
		return false;

	//checking if _roll has a dice of the selected color
	bool found = false;
	for (auto die : _roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;
    
    

	//checking if value is open for use
	int playedBoxCount = 0;
	for (int i = 0; i < d_row.size(); i++) {
		if ((*this)[i] == -1) {
			playedBoxCount++;
			if (i > _index)
				return false;
		}
	}

    if (playedBoxCount > 5){
        this->_locked = true;
        return false;
    }

	return true;
}

template<typename rowType, Color d_c>
int & QwixxRow<rowType, d_c>::operator[](int _index)
{
    auto iter = d_row.begin();
    std::advance(iter, _index);
    return *iter;
}

template<typename rowType, Color d_c>
const int & QwixxRow<rowType, d_c>::operator[](int _index) const
{
    auto iter = d_row.begin();
    std::advance(iter, _index);
    return *iter;
}




#endif
