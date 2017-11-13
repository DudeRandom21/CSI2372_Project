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
	QwixxRow<std::vector, Color> d_color1;	//identifiers should be changed to the color names instead of "colorX"
	QwixxRow<std::vector, Color> d_color2;
	QwixxRow<std::list, Color> d_color3;
	QwixxRow<std::list, Color> d_color4;

public:
	QwixxScoreSheet();
	~QwixxScoreSheet();
	friend std::ostream& operator<<(std::ostream& _out, QwixxScoreSheet _sS);
};


class QwixxPlayer : public Player
{
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer();
	~QwixxPlayer();	
};


#endif