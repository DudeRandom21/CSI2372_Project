#include "Player.h"

Player::Player(ScoreSheet *_ss) : d_ScoreSheet(_ss) {}

bool Player::operator!()
{
	return !*d_ScoreSheet;
}

std::vector<Color> Player::get_color_index_vect(std::istream& _in)
{
	std::vector<Color> dice_colors;
	while(dice_colors.size() < 1)
	{
		//getting input line
		std::string raw;
		std::getline(_in, raw);

		//converting input line into vector of dice colors
		std::istringstream ss(raw);
		std::string tmp;
		while(ss >> tmp)
		{
			Color c = convert_to_color(tmp);
			if(c != Color::INVALID)
				dice_colors.push_back(c);
		}

		if(dice_colors.size() < 1)
			std::cout << "invalid input please try again: ";
	}
	return dice_colors;
}

Color Player::convert_to_color(std::string _str)
{
		if(_str == "red")
			return Color::RED;

		else if(_str == "yellow")
			return Color::YELLOW;

		else if(_str == "green")
			return Color::GREEN;

		else if(_str == "blue")
			return Color::BLUE;
		
		else if(_str == "white")
			return Color::WHITE;
		else
			return Color::INVALID;
}
