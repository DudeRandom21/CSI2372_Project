#ifndef QWINTO_ROW
#define QWINTO_ROW

#include <iostream>

#include "Dice.h"


template <const Color d_c>
class QwintoRow
{
	int d_row[10] = {0};

public:
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);
};








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