#ifndef DICE
#define DICE

#include <iostream>
#include <vector>
#include <random>

enum Color {RED, YELLOW, GREEN, BLUE, WHITE};

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
	friend std::ostream& operator<<(std::ostream& _out, const Dice _dice);
};

// should still check with prof if we are allowed to inherit here but in the meantime it's will behave as needed
struct RollOfDice : public std::vector<Dice>
{
	// std::vector<Dice> d_v;
	void roll();
	RollOfDice pair(int _index1, int _index2);
	operator int();
	friend std::ostream& operator<<(std::ostream& _out, const RollOfDice _roll);
};

#endif