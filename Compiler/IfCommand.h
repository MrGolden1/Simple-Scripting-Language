#pragma once
#include "Command.h"
class IfCommand :
	public Command
{
public:
	IfCommand();
	IfCommand(string input);
	~IfCommand();
};

class ElseIfCommand :
	public IfCommand
{
public:
	ElseIfCommand();
	ElseIfCommand(string input);
	~ElseIfCommand();
private:
};

class ElseCommand
	: public Command
{
public:
	ElseCommand();
	~ElseCommand();

private:

};


class End
	: public Command
{
public:
	End();
	~End();

private:

};

