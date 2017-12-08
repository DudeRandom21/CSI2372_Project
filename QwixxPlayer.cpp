#include "QwixxPlayer.h"

QwixxPlayer::QwixxPlayer(const std::string _name) : Player( new QwixxScoreSheet(_name) ) {}

QwixxPlayer::~QwixxPlayer() { delete d_ScoreSheet; }

RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice& _roll)
{
    d_active = true;
    
    std::vector<Color> dice_colors;
    dice_colors.push_back(Color::WHITE_1);
    dice_colors.push_back(Color::WHITE_2);
    
    // Getting available dice corresponding to unlocked rows
    std::vector<Color> tmp = d_ScoreSheet->getUnlockedColorsVector();
    for (auto c : tmp){
        dice_colors.push_back(c);
    }
    
    RollOfDice rd;
    for(auto color : dice_colors)
        rd.push_back(_roll[convert_to_index(color)]);
    rd.roll();
    
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "           " << "Rolling " << d_ScoreSheet->getName() << "'s Dice" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    
    return rd;
}

void QwixxPlayer::inputAfterRoll(const RollOfDice& _roll)
{
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "                  " << d_ScoreSheet->getName() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << _roll;
    std::cout << *d_ScoreSheet;
    
    if(!d_active)
    {
        char answer;
        
        std::cout << std::endl;
        std::cout << d_ScoreSheet->getName() << ", ";
        std::cout << "Would you like to score the active player's white dice this roll? [y/n] " << std::endl;
        std::cin >> answer;
        std::cin.ignore(256, '\n');
        
        if (answer == 'y'){
            
            bool validMove = true;
            
            do {
                std::cout << std::endl;
                std::cout << "What row would like to play in?";
                Color color = get_color_index_vect(std::cin)[0];
                std::cin.ignore(256, '\n');
                
                RollOfDice whiteDice;
                whiteDice.push_back(_roll[0]);
                whiteDice.push_back(_roll[1]);
                
                int count = 0;
                for (auto d : whiteDice){
                    count += d.d_face;
                }
                
                //trying to score whites only
                if(d_ScoreSheet->score(_roll, color, count)){
                    std::cout << _roll;
                    std::cout << *d_ScoreSheet;
                    return;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "That is not a valid location please try another" << std::endl;
                    validMove = false;
                }
            } while (!validMove);
            
        }
        
    }
    
    else if (d_active)
    {
        
        char answer;
        
        std::cout << std::endl;
        std::cout << d_ScoreSheet->getName() << ", ";
        std::cout << "Would you like to score your white dice this roll? [y/n] " << std::endl;
        std::cin >> answer;
        std::cin.ignore(256, '\n');
        
        bool scoreWhite = true;
        
        if(answer == 'n')
            scoreWhite = false;
        
        if (scoreWhite){
            
            bool validMove = true;
            
            do {
                std::cout << std::endl;
                std::cout << "What row would like to play in?"  << std::endl;
                Color color = get_color_index_vect(std::cin)[0];
                
                RollOfDice whiteDice;
                whiteDice.push_back(_roll[0]);
                whiteDice.push_back(_roll[1]);
                
                int count = 0;
                for (auto d : whiteDice){
                    count += d.d_face;
                }
                
                if(d_ScoreSheet->score(_roll, color, count)){
                    std::cout << _roll;
                    std::cout << *d_ScoreSheet;
                    //return;
                }
                
                else
                {
                    std::cout << std::endl;
                    std::cout << "That is not a valid location please try another" << std::endl;
                    validMove = false;
                }
            } while (!validMove);
            
            
        }
        
        
        std::cout << std::endl;
        std::cout << std::endl << "Would you like to score your colored dice? [y/n]" << std::endl;
        bool scoreColored = true;
        
        std::cin >> answer;
        std::cin.ignore(256, '\n');
        
        if(answer == 'n')
            scoreColored = false;
        
        bool validMove = true;
        
        do {
            
            if(scoreColored){
                Color color;
                std::cout << std::endl;
                std::cout << "What row would like to play in?" << std::endl;
                
                color = get_color_index_vect(std::cin)[0];
                
                int num = -1;
                std::cout << std::endl;
                std::cout << "What number would you like to play?" << std::endl;
                std::cin >> num;
                std::cin.ignore(256, '\n');
                
                
                RollOfDice rd;
                
                bool flag = false;
                int w_d = 0; //getting ready to store what the white dice should be
                
                for (auto d : _roll){
                    if (d.d_color == color){
                        rd.push_back(d);
                        w_d = num - d.d_face; // setting expected white dice value
                    }
                }
                
                for (auto d : _roll){
                    if ((d.d_color == Color::WHITE_1 || d.d_color == Color::WHITE_2) && !flag && d.d_face == w_d){
                        rd.push_back(d);
                        flag = true;
                    }
                }
                
                
                //attempting to score
                if(d_ScoreSheet->score(rd, color, num)){
                    std::cout << std::endl << std::endl << std::endl;
                    std::cout << _roll;
                    std::cout << *d_ScoreSheet;
                    return;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "That is not a valid location please try another" << std::endl;
                    if(d_active)
                        std::cout << std::endl;
                    validMove = false;
                }
            }
        }
        while (!validMove);
        
    
    if ( scoreWhite == false && scoreColored == false ){
        d_ScoreSheet->addFailedThrow();
    }
    
    d_active = false;
}
}

int QwixxPlayer::convert_to_index(const Color _color) const
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


