#ifndef QWINTO
#define QWINTO

#include <iostream>
#include <string>
#include <vector>

#include "QwintoScoreSheet.h"
#include "Common.h"



class QwintoPlayer : public Player
{
	QwintoScoreSheet d_sS;
public:
	QwintoPlayer();
	~QwintoPlayer();	
};

#endif