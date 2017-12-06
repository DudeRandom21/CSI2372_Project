#ifndef DICE
#define DICE

#include <iostream>
#include <vector>
#include <random>
#include <list>


enum Color {INVALID, RED, YELLOW, GREEN, BLUE, WHITE};

struct RandomDice
{
	static std::uniform_int_distribution<int> die;
	static std::default_random_engine generator;
};

struct Dice
{
	Dice(Color _color);
	const Color d_color;
	int d_face;
	int roll();
	friend std::ostream& operator<<(std::ostream& _out, const Dice& _dice);
};

struct RollOfDice : public std::vector<Dice>
{
	RollOfDice roll();
	RollOfDice pair(const int _index1, const int _index2) const;
	operator int() const;
	friend std::ostream& operator<<(std::ostream& _out, const RollOfDice& _roll);
};

#endif