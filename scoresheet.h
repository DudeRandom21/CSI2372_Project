#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <string>
#include <vector>

struct Dice
{
	
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
	enum Color {RED, YELLOW, BLUE};

	ScoreSheet(std::string _name);
	~ScoreSheet();
	
	void print(std::ostream out);
	void score(std::vector<Dice> _dice, Color _color, int _pos);

};



#endif