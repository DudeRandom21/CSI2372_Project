#include "QwixxRow.h"

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

template <>
void QwixxRow<std::vector<int>, Color::RED>::print(std::ostream& _out) const
{
	_out << "Red           ";
	for (int i = 0; i < 11; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|'); //this line decides which seperator to place
		printNumber(_out, (*this)[i]);
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
		printNumber(_out, (*this)[i]);
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
		printNumber(_out, (*this)[i]);
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
		printNumber(_out, (*this)[i]);
	}
	_out << '%' << std::endl;
}

// Specialized [] operator based on row type (vector or list)

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