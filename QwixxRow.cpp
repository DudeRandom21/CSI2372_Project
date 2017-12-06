#include "QwixxRow.h"

//defining functions from QwixxRow template

template <>
void QwixxRow<std::vector<int>, Color::RED>::print(std::ostream& _out) const
{
	_out << "Red     ";
	for (int i = 0; i < 11; ++i)
	{
		_out << '|';
		printNumber(_out, (*this)[i]);
	}
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << std::endl;
}


template <>
void QwixxRow<std::vector<int>, Color::YELLOW>::print(std::ostream& _out) const
{
	_out << "Yellow  ";
    for (int i = 0; i < 11; ++i)
    {
        _out << '|';
        printNumber(_out, (*this)[i]);
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << std::endl;
}

template <>
void QwixxRow<std::list<int>, Color::GREEN>::print(std::ostream& _out) const
{
	_out << "Green   ";
    for (int i = 0; i < 11; ++i)
    {
        _out << '|';
        printNumber(_out, (*this)[i]);
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << std::endl;
}

template <>
void QwixxRow<std::list<int>, Color::BLUE>::print(std::ostream& _out) const
{
	_out << "Blue    ";
    for (int i = 0; i < 11; ++i)
    {
        _out << '|';
        printNumber(_out, (*this)[i]);
    }
    _out << '|' << ' ' << ((this->_locked) ? "L" : "U") << '|' << std::endl;
}


