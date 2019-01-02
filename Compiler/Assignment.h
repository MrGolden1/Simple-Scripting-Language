#pragma once
#include "Command.h"
class Assignment :
	public Command
{
public:
	Assignment(string input, map<string, double> &in, stack <pair<bool, bool>> &r);
	~Assignment();
	virtual void runCommand();
	void parsingExpression() ; // left = right
private:
	string left;
	string right;
	map<string, double> & var;
};