#include "QwintoRow.h"


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