#ifndef QWIXX_ROW
#define QWIXX_ROW

#include "Row.h"
#include "Dice.h"


template <class rowType, const Color d_c>
class QwixxRow : public Row
{
	rowType d_row = {0};

	inline static void printNumber(std::ostream& _out, int _value);

protected:
	virtual void print(std::ostream& _out) const;

public:
	QwixxRow();
	virtual int &operator[](int _index);
	virtual bool validate(int _index, RollOfDice roll);
};


//defining functions from QwixxRow template



template <class rowType, const Color d_c>
bool QwixxRow<rowType, d_c>::validate(int _index, RollOfDice _roll)
{
	if ( _index < 2 || _index > 12 ){
		return false;
	}

	if ( d_row[_index] == 1 ){
		return false;
	}

	bool found = false;
	for(auto die : _roll){
		if (die.d_color == d_c){
			found = true;
		}
	}
	if (!found){
		return false;
	}







	//checking if a lower index has a higer value
	int i;
	for(i = _index; i>-1 && d_row[i] <= 0; --i);

	if (i>-1 && d_row[i] >= _roll)
		return false;

	//checking if a higer index has a lower value
	for(i = _index; i<10 && d_row[i] <= 0; ++i);

	if (i<10 && d_row[i] <= _roll)
		return false;

	return true;

}

template <class rowType, const Color d_c>
int& QwixxRow<rowType, d_c>::operator[](int _index)
{	
	return d_row[_index];
}



#endif