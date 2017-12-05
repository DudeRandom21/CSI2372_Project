#include "QwixxPlayer.h"

void clean(std::string _str);
int convert_to_index(std::string _str);
Color convert_to_color(std::string _str);

QwixxPlayer::QwixxPlayer(std::string _name) : Player( new QwixxScoreSheet(_name) ) {}

QwixxPlayer::~QwixxPlayer() { delete d_ScoreSheet; }

RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice& _roll)
{
	d_active = true;

	std::cout << "Which dice would you like to roll?" << std::endl;
	std::cout << "(Seperate each dice by a space ex: red blue): ";

	std::string str;
	std::getline(std::cin, str);
	clean(str);

	//converting input line into vector of dice colors
	std::istringstream ss(str);
	std::vector<int> dice_colors;

	std::string tmp;
	while(ss >> tmp)
		dice_colors.push_back(convert_to_index(tmp));

	RollOfDice rd;
	for(auto color : dice_colors)
		rd.push_back(_roll[color]);

	return rd;
}


void QwixxPlayer::inputAfterRoll(RollOfDice& _roll)
{
	std::cout << _roll;
	
	if(!d_active)
	{
		char answer;
		std::cout << "Would you like to score this roll? [y/n] ";
		std::cin >> answer;
		if(answer == 'n')
			return;
	}

	for (int i = 0; i < 2; ++i)
	{
		std::string color;
		int index;

		std::cout << "What row would you like to score the dice in? (enter color) ";
		std::getline(std::cin, color);

		clean(color);

		std::cout << "What column (index) do you want to score in?" << std::endl;
		std::cout << "(count from beginning of the chosen row) ";
		std::cin >> index;

		if(d_ScoreSheet->score(_roll, convert_to_color(color), index-1))
			return;

		else
		{
			std::cout << "That is not a valid location please try another" << std::endl;
			if(d_active)
				std::cout << "(last try before being marked as failed throw)" << std::endl;
		}
	}
	
	if(d_active)
		d_ScoreSheet->addFailedThrow();
	d_active = false;

}

void QwixxPlayer::clean(std::string _str)
{
	std::cout << "Cleaning and Stuff" << std::endl;
}


//TODO: rework the RollOfDice to get by color instead of index
int QwixxPlayer::convert_to_index(std::string _str)
{
	if (_str == "red")
		return 0;

	else if (_str == "yellow")
		return 1;

	else if (_str == "blue")
		return 2;
	else
		return 0;
}

Color QwixxPlayer::convert_to_color(std::string _str)
{
	if (_str == "red")
		return Color::RED;

	else if (_str == "yellow")
		return Color::YELLOW;

	else if (_str == "blue")
		return Color::BLUE;
	else
		return Color::WHITE;
}