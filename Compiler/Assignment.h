#pragma once
#include "Command.h"
class Assignment :
	public Command
{
public:
	Assignment(string input);
	~Assignment();
};

