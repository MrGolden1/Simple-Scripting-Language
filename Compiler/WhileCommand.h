#pragma once
#include "Command.h"
class WhileCommand :
	public Command
{
public:
	WhileCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r, stack <int> &l,int &curr);
	~WhileCommand();
	virtual void runCommand();
private:
	map<string, double> &var;
	stack <int> &loopLocator;
	int &currentCommand;
};
class FinishCommand : 
	public Command
{
public:
	FinishCommand(stack <pair<bool, bool>> &r, stack <int> &l, int &curr);
	~FinishCommand();
	virtual void runCommand();
private:
	int &currentCommand;
	stack <int> &loopLocator;
};

