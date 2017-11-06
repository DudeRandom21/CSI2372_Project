#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <string>
#include <vector>
#include <random>

enum Color {RED, YELLOW, GREEN, BLUE, WHITE};

struct Dice
{
	Color d_color;
	int d_face;
	int roll();
	friend std::ostream& operator<<(std::ostream& _out, const Dice _dice);
};

struct RandomDice
{
	std::uniform_int_distribution<> d_die;
	//** I have no idea what goes in here.
};

struct RollOfDice
{
	std::vector<Dice> d_v; // Instead of storing the Vector internally this should probably inherit form vector - check with prof
	int roll();
	RollOfDice pair();
	operator int();
	friend std::ostream& operator<<(std::ostream& _out, const RollOfDice _roll);
};

struct QwintoRow<Color>
{
	std::array<int, 10> d_row; // again I this should probably be inherited
	int &operator[](int index);
	bool validate(int index, RollOfDice roll);
};

struct QwixxRow<class ,Color>
{
	//add prototypes
};



class ScoreSheet
{
	std::string d_name;
	int d_failedThrows;
	int d_points;
protected:
	virtual bool validate() = 0;
	virtual int calcTotal() = 0;

public:

	ScoreSheet(std::string _name);
	~ScoreSheet();
	bool score(RollOfDice _dice, Color _color, int _pos = -1);
	int setTotal();
	virtual bool operator!();
	friend std::ostream& operator<<(std::ostream& _out, ScoreSheet* _sS);
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

class QwixxScoreSheet : public ScoreSheet
{
	QwixxRow<std::vector, Color> d_color1;	//identifiers should be changed to the color names instead of "colorX"
	QwixxRow<std::vector, Color> d_color2;
	QwixxRow<std::list, Color> d_color3;
	QwixxRow<std::list, Color> d_color4;

public:
	QwixxScoreSheet();
	~QwixxScoreSheet();
	friend std::ostream& operator<<(std::ostream& _out, QwintoScoreSheet _sS);
};

class Player
{
protected:
	bool d_active;

public:
	Player();
	~Player();
	virtual inputBeforeRoll(RollOfDice& _roll) = 0;
	virtual inputAfterRoll(RollOfDice& _roll) = 0;	
};

class QwintoPlayer : public Player
{
	QwintoScoreSheet d_sS;
public:
	QwintoPlayer();
	~QwintoPlayer();	
};

class QwixxPlayer : public Player
{
	QwixxScoreSheet d_sS;
public:
	QwixxPlayer();
	~QwixxPlayer();	
};

#endif