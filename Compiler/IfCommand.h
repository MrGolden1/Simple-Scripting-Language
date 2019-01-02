#pragma once
#include "Command.h"
class IfCommand :
	public Command
{
public:
	IfCommand();
	IfCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r);
	~IfCommand();
	virtual void runCommand();
protected:
	map<string, double> &var;
};

class ElseIfCommand :
	public IfCommand
{
public:
	ElseIfCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r);
	~ElseIfCommand();
	virtual void runCommand() ;
};

class ElseCommand
	: public Command
{
public:
	ElseCommand(stack <pair<bool, bool>> &r);
	~ElseCommand();
	virtual void runCommand() ;
};


class End
	: public Command
{
public:
	End(stack <pair<bool, bool>> &r);
	~End();
	virtual void runCommand();
};
