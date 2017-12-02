#ifndef QWIXX
#define QWIXX

#include <iostream>
#include <string>

#include "QwixxScoreSheet.h"
#include "Common.h"


class QwixxPlayer : public Player
{
	// denotes the stage of play, 0 for white, 1 for color
	bool stage;
	
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer() : stage(0) {}
	~QwixxPlayer();	
};

#endif