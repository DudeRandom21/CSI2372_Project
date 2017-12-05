#include "QwixxRow.h"

//defining functions from QwixxRow template


template <>
void QwixxRow<std::vector<int>, Color::RED>::print(std::ostream& _out) const
{
	_out << "Red           ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, (*this)[i]);
	}
	_out << '|' << std::endl;
}


template <>
void QwixxRow<std::vector<int>, Color::YELLOW>::print(std::ostream& _out) const
{
	_out << "Yellow     ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 7) || (i == 8)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, (*this)[i]);
	}
	_out << '|' << std::endl;
}

template <>
void QwixxRow<std::list<int>, Color::GREEN>::print(std::ostream& _out) const
{
	_out << "Green    ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, (*this)[i]);
	}
	_out << '%' << std::endl;
}

template <>
void QwixxRow<std::list<int>, Color::BLUE>::print(std::ostream& _out) const
{
	_out << "Blue    ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, (*this)[i]);
	}
	_out << '%' << std::endl;
}

// Specialized [] operator based on row type (vector or list)


