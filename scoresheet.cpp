#include "scoresheet.h"


void ScoreSheet::print(std::ostream out)
{
	out << "Player name: " << d_name << "\t" << Points << d_points << std::endl;
	out << "-------------------------------" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		out << ((i == 1) || (i == 2) || (i == 5) || (i == 6)) ? '%' : '|';
		if (i == 3)
			out << "XX";
		else if (red[i] == 0)
			out << "  ";
		else if (red[i] < 10)
			out << ' ' << red[i];
		else
			out << red[i];
	}
	out << '|' << std::endl;

	out << "-------------------------------" << std::endl;	
	
	for (int i = 0; i < 10; ++i)
	{
		out << ((i == 7) || (i == 8)) ? '%' : '|';
		if (i == 5)
			out << "XX";
		else if (red[i] == 0)
			out << "  ";
		else if (red[i] < 10)
			out << ' ' << red[i];
		else
			out << red[i];
	}
	out << '|' << std::endl;

	out << "-------------------------------" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		out << ((i == 2) || (i == 3) || (i == 9)) ? '%' : '|';
		if (i == 4)
			out << "XX";
		else if (red[i] == 0)
			out << "  ";
		else if (red[i] < 10)
			out << ' ' << red[i];
		else
			out << red[i];
	}
	out << '%' << std::endl;

	out << "-------------------------------" << std::endl;

	out << "Failed throws: ";
	for (int i = 1; i <= d_failedThrows; ++i)
	{
		out << i << ' ';
	}

	out << std::endl;
}










void ScoreSheet::score(std::vector<Dice> _dice, Color _color, int _pos)
{

}
