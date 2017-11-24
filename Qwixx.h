#ifndef QWIXX
#define QWIXX

#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"
#include "Common.h"

struct QwixxRow<class ,Color>
{
	//add prototypes
};

class QwixxScoreSheet : public ScoreSheet
{

public:
	QwixxScoreSheet();
	~QwixxScoreSheet();
};


class QwixxPlayer : public Player
{
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer();
	~QwixxPlayer();	
};


#endif