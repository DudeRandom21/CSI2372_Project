#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <string>
#include <vector>

struct Dice
{
	ScoreSheet::Color color;
	int face;
	int roll();
	ostream &operator<<(ostream &out, const Dice);
};

struct RandomDice
{
	std::uniform_int_distribution die(1, 6);
	//** I have no idea what goes in here.
};

struct RollOfDice
{
	std::vector<Dice> v; // Instead of storing the Vector internally this should probably inherit form vector - check with prof
	int roll();
	RollOfDice pair();
	operator int();
	ostream &operator<<(ostream &out, const Dice);
};

struct QwintoRow<Color>
{
	std::array<int, 10> row; // again I this should probably be inherited
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);
};

class ScoreSheet
{

	std::string d_name;
	int d_failedThrows;
	int d_points;

	int d_red[10];
	int d_yellow[10];
	int d_blue[10];

public:
	enum Color {RED, YELLOW, GREEN, BLUE, WHITE};

	ScoreSheet(std::string _name);
	~ScoreSheet();
	
	void print(std::ostream out);
	void score(std::vector<Dice> _dice, Color _color, int _pos);

};



#endif