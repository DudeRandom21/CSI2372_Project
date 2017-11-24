#include "Row.h"

int& Row::operator[](int _index)
{
	return d_row[_index];
}

std::ostream& operator<<(std::ostream& _out, const Row& _row)
{
	_row.print(_out);
	return _out;
}
