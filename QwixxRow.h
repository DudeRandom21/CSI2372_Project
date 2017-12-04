#ifndef QWIXX_ROW
#define QWIXX_ROW

#include <iomanip>

#include "Row.h"
#include "Dice.h"


template <class rowType, const Color d_c>
class QwixxRow : public Row
{
	rowType d_row;
	inline static void printNumber(std::ostream& _out, int _value);

protected:
	virtual void print(std::ostream& _out) const;
	virtual int & operator[](int _index);

public:
	QwixxRow();
	virtual bool validate(int _index, RollOfDice roll);
};



			
#endif