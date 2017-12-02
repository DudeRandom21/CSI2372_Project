#include "QwixxRow.h"

template<class rowType, const Color d_c>
inline void QwixxRow<rowType, d_c>::printNumber(std::ostream& _out, int _value)
{
	if (_value == 0)
		out << "  ";
	else if (_value == 1)
		_out << "XX";
	else
		_out << std::setw(2) << _value;
}


template <>
void QwixxRow<std::vector<int>, Color::RED>::print(std::ostream& _out) const
{
	_out << "Red           ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		QwixxRow<std::vector<int>, Color::RED>::printNumber(_out, d_row[i]);
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
		QwixxRow < std::vector<int>, Color::YELLOW > ::printNumber(_out, d_row[i]);
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
		QwixxRow<std::list<int>, Color::GREEN>::printNumber(_out, d_row[i]);
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
		QwixxRow<std::list<int>, Color::BLUE>::printNumber(_out, d_row[i]);
	}
	_out << '%' << std::endl;
}