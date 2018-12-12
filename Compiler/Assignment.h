#pragma once
#include "Command.h"
class Assignment :
	public Command
{
public:
	Assignment(string input);
	~Assignment();
	virtual void runCommand();
	void parsingExpression() ; // left = right
private:
	string left;
	string right;
};

