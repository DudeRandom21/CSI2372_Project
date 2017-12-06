#include "QwixxPlayer.h"

QwixxPlayer::QwixxPlayer(std::string _name) : Player( new QwixxScoreSheet(_name) ) {}

QwixxPlayer::~QwixxPlayer() { delete d_ScoreSheet; }

RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice& _roll)
{
    d_active = true;
    
    std::vector<Color> dice_colors = d_ScoreSheet->getUnlockedColorsVector();
    dice_colors.push_back(Color::WHITE_1);
    dice_colors.push_back(Color::WHITE_2);
    
    RollOfDice rd;
    for(auto color : dice_colors)
        rd.push_back(_roll[convert_to_index(color)]);
    return rd;
}


void QwixxPlayer::inputAfterRoll(RollOfDice& _roll)
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
        
        std::cout << std::endl << "Would you like to score the white dice? (y/n) ";
        bool scoreWhite = true;
        std::cin >> scoreWhite;
        std::cin.ignore(256, '\n');
        
        if(scoreWhite){
            
            std::cout << "What row would like to play in?";
            color = get_color_index_vect(std::cin)[0];
            std::cin.ignore(256, '\n');
            
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
        
        std::cout << std::endl << "Would you like to score the colored dice? (y/n) ";
        bool scoreColored = true;
        std::cin >> scoreColored;
        
        if(scoreColored){
            std::cout << "What row would like to play in?";
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
        
        if ( scoreWhite == false && scoreColored == false ){
            d_ScoreSheet->addFailedThrow();
        }
        
            

		
    }
    d_active = false;
}

//TODO: rework the RollOfDice to get by color instead of index
int QwixxPlayer::convert_to_index(Color _color)
{
	if(_color == Color::RED)
		return 0;

	else if(_color == Color::YELLOW)
		return 1;

	else if(_color == Color::GREEN)
		return 2;

	else if(_color == Color::BLUE)
		return 3;

	else if(_color == Color::WHITE_1)
		return 4;

    else if(_color == Color::WHITE_2)
        return 5;
    
    else
        return -1;
}


