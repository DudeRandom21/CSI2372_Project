#ifndef QWIXX
#define QWIXX

#include <iostream>
#include <string>

#include "Player.h"
#include "QwixxScoreSheet.h"


class QwixxPlayer : public Player
{
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer() : stage(0) {}
	~QwixxPlayer();	
};

#endif
