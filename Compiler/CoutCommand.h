#pragma once
#include "Command.h"
class CoutCommand :
	public Command
{
public:
	CoutCommand(string input , map<string, double> &in, stack <pair<bool, bool>> &r);
	~CoutCommand();
	virtual void runCommand();
private:
	map<string, double> &var;
};

