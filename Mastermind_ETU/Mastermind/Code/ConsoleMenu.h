#pragma once
#include "Color.h"
#include "Combination.h"

class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void run();
private:
	bool readSequence(Color tabColors[]);
	void displayResult(short nbTries);
	bool isGameOver(short tabVerdicts[]);
	void readVerdicts(Combination* tabReference, short tabVerdicts[]);
};

