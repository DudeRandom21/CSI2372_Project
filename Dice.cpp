#include <ctime>

#include "Dice.h"

std::uniform_int_distribution<int> RandomDice::die{1,6};

std::default_random_engine RandomDice::generator{ static_cast<unsigned int>(time(NULL)) };
//std::default_random_engine RandomDice::generator{static_cast<unsigned long>(time(NULL))};

Dice::Dice(Color _color) : d_color(_color)
{
	roll();
}

int Dice::roll()
{
	return d_face = RandomDice::die(RandomDice::generator);
}

std::ostream& operator<<(std::ostream& _out, const Dice& _dice)
{
    _out << '\t' << '\t' << '\t' << '\t';
    
	switch(_dice.d_color)
	{
		case Color::RED:
            _out << "Red ";
            break;
            
		case Color::YELLOW:
            _out << "Yellow";
            break;
            
		case Color::BLUE:
            _out << "Blue";
            break;
            
        case Color::GREEN:
            _out << "Green";
            break;
        
        case Color::WHITE_1:
            _out << "White-1";
            break;
            
        case Color::WHITE_2:
            _out << "White-2";
            break;
            
        case Color::INVALID:
            break;
            
            
	}

    _out << '\t' << "|" << _dice.d_face << "|" << std::endl;
    _out << '\t' << '\t' << '\t' << '\t';
    _out << "------------";
	return _out;
}

RollOfDice RollOfDice::roll()
{
	for(auto &die : *this)
	{
		die.roll();
	}
	return *this;
}

//revise if inheritance is not permited
RollOfDice RollOfDice::pair(const int _index1, const int _index2) const
{
	RollOfDice pairedRoll;
	pairedRoll.push_back((*this)[_index1]);
	pairedRoll.push_back((*this)[_index2]);

	return pairedRoll;
}

RollOfDice::operator int() const
{
	int total = 0;
	for(auto die : *this)
		total += die.d_face;
	return total;
}

std::ostream& operator<<(std::ostream& _out, const RollOfDice& _roll)
{
    _out << "Roll: " << std::endl;
    _out << '\t' << '\t' << '\t' << '\t';
    _out << "------------" << std::endl;
	for(auto die : _roll)
        _out << die << std::endl;
	
	_out << '\t' << '\t' << '\t' << '\t' << "Total: " << static_cast<int>(_roll) << std::endl;
    _out << std::endl;

	return _out;
}
