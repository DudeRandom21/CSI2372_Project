#ifndef QWINTO_ROW
#define QWINTO_ROW

#include <iomanip>

#include "Row.h"
#include "Dice.h"


template <const Color d_c>
class QwintoRow : public Row
{
	int d_row[10] = {0};

protected:
	virtual void print(std::ostream& _out) const;

public:
	QwintoRow();
	virtual int &operator[](int _index);
	virtual bool validate(int _index, RollOfDice roll);
};


//defining functions from QwintoRow template

template<const Color d_c>
QwintoRow<d_c>::QwintoRow()
{
	if(d_c == Color::RED)
		d_row[3] = -1;

	else if(d_c == Color::YELLOW)
		d_row[5] = -1;

	else if(d_c == Color::BLUE)
		d_row[4] = -1;
}

template <const Color d_c>
bool QwintoRow<d_c>::validate(int _index, RollOfDice _roll)
{

	if (_index < 0 || _index > 9)
		return false;

	if(d_row[_index] != 0)
		return false;

	//checking if _roll has a dice of the selected color
	bool found = false;
	for(auto die : _roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;

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

template <const Color d_c>
int& QwintoRow<d_c>::operator[](int _index)
{
	return d_row[_index];
}


#endif