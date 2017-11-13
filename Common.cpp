#include "Common.h"

// Class Scoresheet
ScoreSheet::ScoreSheet(std::string _name){
    this -> d_name = _name;
    this -> d_failedThrows = 0;
    this -> d_points = 0;
}

ScoreSheet::~ScoreSheet(){
    delete d_name;
    delete d_failedThrows;
    delete d_points;
}

bool ScoreSheet::score(RollOfDice _dice, Color _color, int _pos = -1){
    return validate(_dice, _color, _pos); // assume structure of validate for now
}

int ScoreSheet::setTotal(){
    d_points = calcTotal();
    return d_points;
}

friend std::ostream& operator<<(std::ostream& _out, ScoreSheet* _sS){
    _out << "ScoreSheet Name: " << _sS -> d_name << endl;
    _out << "Failed Throws: " << _sS -> d_failedThrows << endl;
    _out << "Points: " << _sS -> d_points << endl;
    _out << endl;
}


// Class Player
Player::Player(){ 
	d_active = true; 
}

~Player(){
    delete d_active;
}


