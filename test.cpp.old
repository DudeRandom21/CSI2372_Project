#include <iostream>

#include "Dice.h"
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "QwintoPlayer.h"

// #include "QwixxRow.h"
// #include "QwixxScoreSheet.h"
// #include "Player.h"
// #include "QwixxPlayer.h"

	RollOfDice rd1;

	RollOfDice rd2;

Color randomColor();

int main(int argc, char const *argv[])
{
	rd1.push_back(Dice(Color::RED));
	rd1.push_back(Dice(Color::YELLOW));

	rd2.push_back(Dice(Color::RED));
	rd2.push_back(Dice(Color::YELLOW));

	// QwintoRow<Color::RED> rowR;
	// QwintoRow<Color::YELLOW> rowY;
	// QwintoRow<Color::BLUE> rowB;

	// rowR[0] = 5;
	// rowY[8] = 12;
	// rowB[6] = 8;


	// if(rowR.validate(5, rd))
	// 	rowR[5] = rd;

	// if(rowY.validate(2, rd))
	// 	rowY[2] = rd;

	// std::cout << rowR << std::endl;
	// std::cout << rowY << std::endl;
	// std::cout << rowB << std::endl;


	RollOfDice rd;
	rd.push_back(Dice(Color::RED));
	rd.push_back(Dice(Color::YELLOW));
	rd.push_back(Dice(Color::BLUE));


	Player *p1 = new QwintoPlayer("Jane Doe");

	RollOfDice active = p1->inputBeforeRoll(rd);

	active.roll();

	p1->inputAfterRoll(active);

	delete p1;



	// QwintoScoreSheet ss1{"Jane Doe"};

	//QwixxScoreSheet ss1{"Jane Doe"};


	// for (int i = 0; i < 100; ++i)
	// {
	// 	rd.roll();
	// 	ss1.score(rd, randomColor(), rd1.roll()%10);
	// }

	// std::cout << ss1;

	// std::cout << !ss1 <<std::endl;






	return 0;
}

Color randomColor()
{
	switch (rd1.roll()%3)
	{
		case 0:
		return Color::RED;
		case 1:
		return Color::YELLOW;
		case 2:
		return Color::BLUE;
        default:
            return Color::WHITE;
	}
}
