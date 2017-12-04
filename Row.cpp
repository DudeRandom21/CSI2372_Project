#include "Row.h"

std::ostream& operator<<(std::ostream& _out, const Row& _row)
{
	_row.print(_out);
	return _out;
}

inline void printNumber(std::ostream& _out, int _value)
{
	if (_value == 0)
		_out << "  ";
	else if (_value == -1)
		_out << "XX";
	else
		_out << std::setw(2) << _value;	
}

