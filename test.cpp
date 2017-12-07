#ifdef TESTING

#include <iostream>

#include "Dice.h"
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "QwintoPlayer.h"

#include "QwixxRow.h"
#include "QwixxScoreSheet.h"
#include "Player.h"
#include "QwixxPlayer.h"

RollOfDice rd1; //this roll of dice is used as a RNG in the random tests
Color randomColor();
void testingQwinto();
void testingQwixx();

int main(int argc, char const *argv[])
{
	//filling the RNG with enough dice to have a value of at least 10
	rd1.push_back(Dice(Color::RED));
	rd1.push_back(Dice(Color::YELLOW));

	//the actual tests
	testingQwinto();
	testingQwixx();

	return 0;
}


void testingQwinto()
{

	//Generating RollOfDice
	RollOfDice rd;
	rd.push_back(Dice(Color::RED));
	rd.push_back(Dice(Color::YELLOW));
	rd.push_back(Dice(Color::BLUE));


	//Creating Test Row
	QwintoRow<Color::BLUE> row;

	//Creating Test ScoreSheet
	QwintoScoreSheet ss("Jane Doe");


	//Actual Tests
	std::cout << "\nTesting Qwinto" << std::endl;
	std::cout << "Testing Row\n" << std::endl;

	std::cout << "Testing Print Row\n" << std::endl;
	std::cout << "Expected Output: " << std::endl;
	std::cout << "Red           |  %  %  |XX|  %  %  |  |  |  |" << std::endl;
	std::cout << "Yellow     |  |  |  |  |  |XX|  %  %  |  |" << std::endl;
	std::cout << "Blue    |  |  %  %  |XX|  |  |  |  %  %" << std::endl;

	std::cout << "Actual Output" << std::endl;
	std::cout << QwintoRow<Color::RED>();
	std::cout << QwintoRow<Color::YELLOW>();
	std::cout << QwintoRow<Color::BLUE>();
	std::cin.get();


	std::cout << "Testing operator[]\n" <<std::endl;
	row[0] = 3;
	std::cout << "Expected Output: " << std::endl;
	std::cout << "Blue    | 3|  %  %  |XX|  |  |  |  %  %" << std::endl;
	std::cout << "Actual Output" << std::endl;
	std::cout << row << std::endl;
	std::cin.get();


	std::cout << "Testing validate" <<std::endl;
	row[2] = 4;
	std::cout << row << std::endl;
	std::cout << "Attempting to validate RollOfDice to index 1" << std::endl;
	std::cout << "Expected Output" << std::endl;
	std::cout << "0" << std::endl;
	std::cout << "Actual Output" << std::endl;
	std::cout << row.validate(1, rd) << std::endl;
	std::cin.get();


	std::cout << "\nTesting ScoreSheet\n" << std::endl;
	std::cout << "Attempting to Fill Cells with Random RollOfDice" << std::endl;
	std::cout << "All plays should be legal" << std::endl;
	std::cout << "(but not necessarily smart)\n" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		rd.roll();
		ss.score(rd, randomColor(), rd1.roll()%10);
	}
	std::cout << ss;
}

void testingQwixx()
{
	//Generating RollOfDice
	RollOfDice rd;
	rd.push_back(Dice(Color::RED));
	rd.push_back(Dice(Color::YELLOW));
	rd.push_back(Dice(Color::GREEN));
	rd.push_back(Dice(Color::BLUE));


	//Creating Test Row
	QwixxRow<std::vector<int>, Color::RED> row;

	//Creating Test ScoreSheet
	QwixxScoreSheet ss("Jane Doe");


	//Actual Tests
	std::cout << "\nTesting Qwixx" << std::endl;
	std::cout << "Testing Row\n" << std::endl;

	std::cout << "Testing Print Row\n" << std::endl;
	std::cout << "Expected Output: " << std::endl;
	std::cout << "Red     | 2| 3| 4| 5| 6| 7| 8| 9|10|11|12| U|" << std::endl;
	std::cout << "Yellow  | 2| 3| 4| 5| 6| 7| 8| 9|10|11|12| U|" << std::endl;
	std::cout << "Green   |12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| U|" << std::endl;
	std::cout << "Blue    |12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| U|" << std::endl;

	std::cout << "Actual Output" << std::endl;
	std::cout << QwixxRow<std::vector<int>, Color::RED>();
	std::cout << QwixxRow<std::vector<int>, Color::YELLOW>();
	std::cout << QwixxRow<std::list<int>, Color::GREEN>();
	std::cout << QwixxRow<std::list<int>, Color::BLUE>();
	std::cin.get();


	std::cout << "Testing operator[]\n" <<std::endl;
	row[0] = -1;
	std::cout << "Expected Output: " << std::endl;
	std::cout << "Red     |XX| 3| 4| 5| 6| 7| 8| 9|10|11|12| U|" << std::endl;
	std::cout << "Actual Output" << std::endl;
	std::cout << row << std::endl;
	std::cin.get();


	std::cout << "Testing validate" <<std::endl;
	row[0] = row[1] = row[2] = row[3] = row[8] = row[9] = -1;
	std::cout << row << std::endl;
	std::cout << "Attempting to validate RollOfDice to index 5" << std::endl;
	std::cout << "Expected Output" << std::endl;
	std::cout << "0" << std::endl;
	std::cout << "Actual Output" << std::endl;
	std::cout << row.validate(5, rd) << std::endl;
	std::cin.get();


	std::cout << "\nTesting ScoreSheet\n" << std::endl;
	std::cout << "Attempting to Fill Cells with Random RollOfDice" << std::endl;
	std::cout << "All plays should be legal" << std::endl;
	std::cout << "(but not necessarily smart)\n" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		rd.roll();
		ss.score(rd, randomColor(), rd1.roll()%10);
	}
	std::cout << ss;
}


Color randomColor()
{
	switch (rd1.roll()%4)
	{
		case 0:
			return Color::RED;
		case 1:
			return Color::YELLOW;
		case 2:
			return Color::GREEN;
		case 3:
			return Color::BLUE;
        default:
            return Color::WHITE_1;
	}
}

#endif