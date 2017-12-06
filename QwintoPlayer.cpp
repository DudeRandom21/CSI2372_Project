#include "QwintoPlayer.h"

QwintoPlayer::QwintoPlayer(std::string _name) : Player(new QwintoScoreSheet(_name)) {}

QwintoPlayer::~QwintoPlayer() {delete d_ScoreSheet;}

RollOfDice QwintoPlayer::inputBeforeRoll(RollOfDice& _roll)
{
	d_active = true;

	std::cout << "Which dice would you like to roll?" << std::endl;
	std::cout << "(Seperate each dice by a space ex: red blue): " <<std::endl;

	std::vector<Color> dice_colors = get_color_index_vect(std::cin);

	RollOfDice rd;
	for(auto color : dice_colors)
		rd.push_back(_roll[convert_to_index(color)]);

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
		std::cin.ignore(256, '\n');
		if(answer == 'n')
			return;
	}

	for (int i = 0; i < 2; ++i)
	{
		Color color;
		int index;

		std::cout << "What row would you like to score the roll in? (enter color) ";

		color = get_color_index_vect(std::cin)[0];

		std::cout << "What column (index) do you want to score in?" << std::endl;
		std::cout << "(count from beginning of the chosen row) ";
		std::cin >> index;
		std::cin.ignore(256, '\n');

		if(d_ScoreSheet->score(_roll, color, index-1))
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

//TODO: rework the RollOfDice to get by color instead of index
int QwintoPlayer::convert_to_index(Color _color)
{
	if(_color == Color::RED)
		return 0;

	else if(_color == Color::YELLOW)
		return 1;

	else if(_color == Color::BLUE)
		return 2;

    else
        return 0;
    
}
