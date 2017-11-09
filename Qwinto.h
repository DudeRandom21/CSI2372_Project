#ifndef QWINTO
#define QWINTO

#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"
#include "Common.h"

struct QwintoRow<Color>
{
	int d_row[10];
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);
};


class QwintoScoreSheet : public ScoreSheet
{
	QwintoRow<Color::RED> d_red;
	QwintoRow<Color::YELLOW> d_yellow;
	QwintoRow<Color::BLUE> d_blue;

public:
	QwintoScoreSheet();
	~QwintoScoreSheet();
	friend std::ostream& operator<<(std::ostream& _out, QwintoScoreSheet _sS);
}


class QwintoPlayer : public Player
{
	QwintoScoreSheet d_sS;
public:
	QwintoPlayer();
	~QwintoPlayer();	
};

#endif