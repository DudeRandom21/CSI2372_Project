#include "QwintoRow.h"

template<const Color d_c>
inline void QwintoRow<d_c>::printNumber(std::ostream& _out, int _value)
{
	if (_value == 0)
		_out << "  ";
	else if (_value == -1)
		_out << "XX";
	else
		_out << std::setw(2) << _value;	
}


//specializations of the insertion operator for template QwintoRow

template <>
void QwintoRow<Color::RED>::print(std::ostream& _out) const
{
	_out << "Red           ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::RED>::printNumber(_out, d_row[i]);
	}
	_out << '|' << std::endl;
}



template <>
void QwintoRow<Color::YELLOW>::print(std::ostream& _out) const
{
	_out << "Yellow     ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 7) || (i == 8)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::YELLOW>::printNumber(_out, d_row[i]);
	}
	_out << '|' << std::endl;
}


template <>
void QwintoRow<Color::BLUE>::print(std::ostream& _out) const
{
	_out << "Blue    ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::BLUE>::printNumber(_out, d_row[i]);
	}
	_out << '%' << std::endl;
}