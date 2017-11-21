#include "Common.h"

// Class Scoresheet
ScoreSheet::ScoreSheet(std::string _name) : d_name(_name), d_failedThrows(0), d_points(0) {}

ScoreSheet::~ScoreSheet() {}

bool ScoreSheet::score(RollOfDice _dice, Color _color, int _pos){
    return validate( _dice, _color, _pos ); // assume structure of validate for now
}

int ScoreSheet::setTotal(){
    d_points = calcTotal();
    return d_points;
}

// Class Player
Player::Player() : d_active(true) {}
Player::~Player() {}


