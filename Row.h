#ifndef ROW
#define ROW

#include <iostream>

#include "Dice.h"

class Row
{

protected:
	virtual void print(std::ostream& _out) const = 0;
	int d_row[10] = {0};

public:
	// Row();
	virtual ~Row() = default;
	int &operator[](int _index);
	virtual bool validate(int _index, RollOfDice roll) = 0;

	friend std::ostream& operator<<(std::ostream& _out, const Row& _row);
};


#endif