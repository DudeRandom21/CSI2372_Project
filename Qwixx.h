#ifndef QWIXX
#define QWIXX

#include <iostream>
#include <string>

#include "Common.h"

class QwixxPlayer : public Player
{
	// denotes the stage of play, 0 for white, 1 for color
	bool stage;
	
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer() : stage( false );
	~QwixxPlayer();	
};


#endif