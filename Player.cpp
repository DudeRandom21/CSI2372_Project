#include "Player.h"

Player::Player(ScoreSheet *_ss) : d_ScoreSheet(_ss) {}

bool Player::getEndCond(){
    return d_ScoreSheet->getEndGameCond();
}
