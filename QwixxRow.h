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
	

template<class rowType, const Color d_c>
QwixxRow<rowType, d_c>::QwixxRow()
{
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

template <typename rowType, const Color d_c>
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
				return false;
		}
	}

	if (playedBoxCount > 5)
		return false;

	return true;
}

template<typename rowType, Color d_c>
const int& QwixxRow<rowType, d_c>::operator[](const int _index) const
{
	auto iter = d_row.begin();
	std::advance(iter, _index);
	auto x = *iter;
}

template<typename rowType, Color d_c>
int& QwixxRow<rowType, d_c>::operator[](const int _index)
{
	auto iter = d_row.begin();
	std::advance(iter, _index);
	auto x = *iter;
}













#endif