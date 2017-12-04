#ifndef QWIXX_ROW
#define QWIXX_ROW

#include <iomanip>

#include "Row.h"
#include "Dice.h"


template <class rowType, const Color d_c>
class QwixxRow : public Row
{
	rowType d_row;
	int d_ref[11] = { 0 }; //reference array for the numbering order
	inline void printNumber(std::ostream& _out, int _value);

protected:
	virtual void print(std::ostream& _out) const;

public:
	QwixxRow();
	virtual int &operator[](int _index);
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
			d_ref[index] = i;
			index++;
		}
	if ((d_c == Color::GREEN) || (d_c == Color::BLUE))
		for (int i = 12; i > 1; i--) {
			d_ref[index] = i;
			index++;
		}
}


template <class rowType, const Color d_c>
bool QwixxRow<rowType, d_c>::validate(int _index, RollOfDice _roll)
{

	if (_index < 0 || _index > 10)
		return false;

	if (d_row[_index] != 0)
		return false;

	//checking if _roll has a dice of the selected color
	bool found = false;
	for (auto die : _roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;

	//checking if value is open for use
	int playedBoxCount = 0;
	for (int i = 0; i < d_row.size(); i++) {
		if (d_row[i] == 1) {
			playedBoxCount++;
			if (i > _index)
				return false
		}
	}

	if (playedBoxCount > 5)
		return false;

	return true;
}

// Specialized [] operator based on row type (vector or list)
template<>
int& QwixxRow<std::vector<int>, Color::RED>::operator[](int _index) const {
	return d_row.at(_index);
}

template<>
int& QwixxRow<std::vector<int>, Color::YELLOW>::operator[](int _index) const {
	return d_row.at(_index);
}

template <>
int& QwixxRow<std::list<int>, Color::GREEN>::operator[](int _index) const
{
	std::list<int>::iterator it = std::next(d_row.begin(), _index);
	return *it;
}

template <>
int& QwixxRow<std::list<int>, Color::BLUE>::operator[](int _index) const
{
	std::list<int>::iterator it = std::next(d_row.begin(), _index);
	return *it;
}

			
#endif