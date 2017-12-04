#include "Row.h"

std::ostream& operator<<(std::ostream& _out, const Row& _row)
{
	_row.print(_out);
	return _out;
}
