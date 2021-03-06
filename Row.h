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
    void printNumber(std::ostream& _out, const int _value) const;    

public:
    virtual ~Row() = default;
    virtual int &operator[](const int _index) = 0;
    virtual bool validate(const int _index, const RollOfDice roll) = 0;
    bool getLockedStatus() { return _locked; }
    virtual Color getColor() = 0;
    
    friend std::ostream& operator<<(std::ostream& _out, const Row& _row);
};


#endif
