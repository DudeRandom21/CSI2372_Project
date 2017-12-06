#include "QwintoPlayer.h"

QwintoPlayer::QwintoPlayer(std::string _name) : Player(new QwintoScoreSheet(_name)) {}

QwintoPlayer::~QwintoPlayer() {delete d_ScoreSheet;}

RollOfDice QwintoPlayer::inputBeforeRoll(RollOfDice& _roll)
{
	d_active = true;

	std::cout << "Which dice would you like to roll?" << std::endl;
	std::cout << "(Seperate each dice by a space ex: red blue): " <<std::endl;

	std::string str;
	std::cin.ignore();
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


void QwintoPlayer::inputAfterRoll(RollOfDice& _roll)
{
	std::cout << _roll;
	std::cout << *d_ScoreSheet;
	
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

		std::cout << "What row would you like to score the roll in? (enter color) ";
		std::cin.ignore();
		std::getline(std::cin, color);

//TODO: implement loop here instead of clean function
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

//TODO: Delete this
void QwintoPlayer::printSS()
{
	std::cout << *d_ScoreSheet;
}

void QwintoPlayer::clean(std::string _str)
{
//TODO: clean the string before processing, right now it juse crashes on bad input.
	// str.erase(std::remove_if(str.begin(), str.end(), std::isalpha));

//ALSO: make sure there are no duplicates (red, red)
}


//TODO: rework the RollOfDice to get by color instead of index
int QwintoPlayer::convert_to_index(std::string _str)
{
		if(_str == "red")
			return 0;

		else if(_str == "yellow")
			return 1;

		else if(_str == "blue")
			return 2;
    
        else
            return 0;
        
}

Color QwintoPlayer::convert_to_color(std::string _str)
{
		if(_str == "red")
			return Color::RED;

		else if(_str == "yellow")
			return Color::YELLOW;

		else if(_str == "blue")
			return Color::BLUE;
    
        else
            return Color::WHITE;
}
