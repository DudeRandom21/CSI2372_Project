#ifndef QWINTO_ROW
#define QWINTO_ROW

#include <iomanip>

#include "Dice.h"

template <const Color d_c>
class QwintoRow;

template <const Color d_c>
std::ostream& operator<<(std::ostream& _out, QwintoRow<d_c> _row);

template <const Color d_c>
class QwintoRow
{
	int d_row[10] = {0};

public:
	QwintoRow();
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);

	friend std::ostream& operator<<<d_c>(std::ostream& _out, QwintoRow<d_c> _row);
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
int& QwintoRow<d_c>::operator[](int index)
{
	return d_row[index];
}

template <const Color d_c>
bool QwintoRow<d_c>::validate(int index, RollOfDice roll)
{
	if(d_row[index] != 0)
		return false;

	//checking if the roll has a dice of the selected color
	bool found = false;
	for(auto die : roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;

	//checking if a lower index has a higer value
	int i;
	for(i = index; i>-1 && d_row[i] <= 0; --i);

	if (i>-1 && d_row[i] >= roll){
		std::cerr << "lower" << std::endl;
		return false;
	}

	//checking if a higer index has a lower value
	for(i = index; i<10 && d_row[i] <= 0; ++i);

	if (i<10 && d_row[i] <= roll)
		return false;

	return true;
}


inline void printNumber(std::ostream& _out, int _value); //Not sure if this should be virtutal or not


//specializations of the insertion operator for template QwintoRow

template <>
std::ostream& operator<<<Color::RED>(std::ostream& _out, QwintoRow<Color::RED> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, _row[i]);
	}
	_out << '|' << std::endl;
	return _out;
}



template <>
std::ostream& operator<<<Color::YELLOW>(std::ostream& _out, QwintoRow<Color::YELLOW> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 7) || (i == 8)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, _row[i]);
	}
	_out << '|' << std::endl;
	return _out;
}


template <>
std::ostream& operator<<<Color::BLUE>(std::ostream& _out, QwintoRow<Color::BLUE> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, _row[i]);
	}
	_out << '%' << std::endl;
	return _out;
}


inline void printNumber(std::ostream& _out, int _value) //Not sure if this should be inline or not
{
	if (_value == -1)
		_out << "XX";
	else if (_value == 0)
		_out << "  ";
	else
		_out << std::setw(2) << _value;	
}


#endif