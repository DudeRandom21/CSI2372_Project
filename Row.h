#ifndef ROW
#define ROW

#include <iostream>
#include <iomanip>


#include "Dice.h"


class Row
{

protected:
    virtual void print(std::ostream& _out) const = 0;
    bool _locked;
    void printNumber(std::ostream& _out, int _value) const;

public:
    virtual ~Row() = default;
    virtual int &operator[](int _index) = 0;
    virtual bool validate(int _index, RollOfDice roll) = 0;


    friend std::ostream& operator<<(std::ostream& _out, const Row& _row);
};


#endif
