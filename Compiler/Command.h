#pragma once
#include "Evaluate.h"
using namespace std;
class Command
{
public:
	Command(stack <pair<bool, bool>> &r) : runStatus(r) {};
	virtual ~Command() {};
	virtual void runCommand() = 0;
protected:
	string line;
	stack <pair<bool, bool>> &runStatus;
};
