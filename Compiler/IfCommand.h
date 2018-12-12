#pragma once
#include "Command.h"
class IfCommand :
	public Command
{
public:
	IfCommand();
	IfCommand(string input);
	~IfCommand();
	virtual void runCommand() ;
};

class ElseIfCommand :
	public IfCommand
{
public:
	ElseIfCommand();
	ElseIfCommand(string input);
	~ElseIfCommand();
	virtual void runCommand() ;
private:
};

class ElseCommand
	: public Command
{
public:
	ElseCommand();
	~ElseCommand();
	virtual void runCommand() ;
private:

};


class End
	: public Command
{
public:
	End();
	~End();
	virtual void runCommand();
private:

};
