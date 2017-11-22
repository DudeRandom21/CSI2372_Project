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
std::ostream& operator<<<Color::RED>(std::ostream& _out, QwintoRow<Color::RED> _row)
{
	_out << "Red           ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::RED>::printNumber(_out, _row[i]);
	}
	_out << '|' << std::endl;
	return _out;
}



template <>
std::ostream& operator<<<Color::YELLOW>(std::ostream& _out, QwintoRow<Color::YELLOW> _row)
{
	_out << "Yellow     ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 7) || (i == 8)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::YELLOW>::printNumber(_out, _row[i]);
	}
	_out << '|' << std::endl;
	return _out;
}


template <>
std::ostream& operator<<<Color::BLUE>(std::ostream& _out, QwintoRow<Color::BLUE> _row)
{
	_out << "Blue    ";
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|'); //this line decides which seperator to place
		QwintoRow<Color::BLUE>::printNumber(_out, _row[i]);
	}
	_out << '%' << std::endl;
	return _out;
}


