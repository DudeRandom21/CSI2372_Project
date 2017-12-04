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


//defining functions from QwixxRow template
template<class rowType, const Color d_c>
QwixxRow<rowType, d_c>::QwixxRow()
{
	//setting up the reference array for denoting the values in d_row
	int index = 0;
	if ((d_c == Color::RED) || (d_c == Color::YELLOW))
		for (int i = 2; i < 13; i++) {
			d_row[index] = i;
			index++;
		}
	if ((d_c == Color::GREEN) || (d_c == Color::BLUE))
		for (int i = 12; i > 1; i--) {
			d_row[index] = i;
			index++;
		}
}
			
#endif