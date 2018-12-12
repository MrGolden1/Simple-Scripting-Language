#pragma once
#include "Calculator.h"
#include "Statement.h"
using namespace std;
class Command
{
public:
	Command();
	virtual ~Command() {};
	virtual void runCommand() = 0;
protected:
	string line;
};
