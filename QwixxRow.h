#ifndef QWIXX_ROW
#define QWIXX_ROW

#include <iomanip>

#include "Row.h"
#include "Dice.h"


template <class rowType, const Color d_c>
class QwixxRow : public Row
{
	rowType d_row;

protected:
	virtual void print(std::ostream& _out) const;
	virtual int & operator[](const int _index);
	virtual const int & operator[](const int _index) const;

public:
	QwixxRow();
	virtual bool validate(int _index, RollOfDice roll);
};
			
#endif