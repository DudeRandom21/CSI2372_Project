#ifndef DICE
#define DICE

#include <iostream>
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

#endif