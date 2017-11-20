#ifndef QWINTO_ROW
#define QWINTO_ROW

#include <iostream>

#include "Dice.h"

template <const Color d_c>
class QwintoRow;

template <const Color d_c>
std::ostream& operator<<(std::ostream& _out, QwintoRow<d_c> _row);

template <const Color d_c>
class QwintoRow
{
	int d_row[10] = {0};

public:
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);

	friend std::ostream& operator<<<d_c>(std::ostream& _out, QwintoRow<d_c> _row);
};


template <>
std::ostream& operator<<<Color::BLUE>(std::ostream& _out, QwintoRow<Color::BLUE> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 2) || (i == 3) || (i == 9)) ? '%' : '|');
		if (i == 4)
			_out << "XX";
		else if (_row[i] == 0)
			_out << "  ";
		else if (_row[i] < 10)
			_out << ' ' << _row[i];
		else
			_out << _row[i];
	}
	_out << '%' << std::endl;
	return _out;
}


template <>
std::ostream& operator<<<Color::YELLOW>(std::ostream& _out, QwintoRow<Color::YELLOW> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 7) || (i == 8)) ? '%' : '|');
		if (i == 5)
			_out << "XX";
		else if (_row[i] == 0)
			_out << "  ";
		else if (_row[i] < 10)
			_out << ' ' << _row[i];
		else
			_out << _row[i];
	}
	_out << '|' << std::endl;
	return _out;
}


template <>
std::ostream& operator<<<Color::RED>(std::ostream& _out, QwintoRow<Color::RED> _row)
{
	for (int i = 0; i < 10; ++i)
	{
		_out << (((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|');
		if (i == 3)
			_out << "XX";
		else if (_row[i] == 0)
			_out << "  ";
		else if (_row[i] < 10)
			_out << ' ' << _row[i];
		else
			_out << _row[i];
	}
	_out << '|' << std::endl;
	return _out;
}






template <const Color d_c>
int& QwintoRow<d_c>::operator[](int index)
{
	return d_row[index];
}

template <const Color d_c>
bool QwintoRow<d_c>::validate(int index, RollOfDice roll)
{
	if(d_row[index] != 0)
		return false;

	//checking if the roll has a dice of the selected color
	bool found = false;
	for(auto die : roll)
	{
		if (die.d_color == d_c)
			found = true;
	}
	if (!found)
		return false;

	//checking if a lower index has a higer value
	int i = index;
	for(; d_row[i] == 0; --i);

	if (d_row[i] >= roll)
		return false;

	//checking if a higer index has a lower value
	i = index;
	for(; d_row[i] == 0; ++i);

	if (d_row[i] <= roll)
		return false;

	return true;
}

#endif