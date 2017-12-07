#include "Player.h"

Player::Player(ScoreSheet *_ss) : d_ScoreSheet(_ss) {}

bool Player::operator!() const
{
	return !*d_ScoreSheet;
}

std::vector<Color> Player::get_color_index_vect(std::istream& _in) const
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


Color Player::convert_to_color(const std::string _str) const
{
		if(_str == "red")
			return Color::RED;

		else if(_str == "yellow")
			return Color::YELLOW;

		else if(_str == "green")
			return Color::GREEN;

		else if(_str == "blue")
			return Color::BLUE;
		
		else if(_str == "white-1")
			return Color::WHITE_1;
    
        else if(_str == "white-2")
            return Color::WHITE_2;
    
		else
			return Color::INVALID;
}

int Player::printScoreSheet() const
{
	std::cout << *d_ScoreSheet;
	return d_ScoreSheet->setTotal();
}

std::string Player::getName() const
{
	return d_ScoreSheet->getName();
}