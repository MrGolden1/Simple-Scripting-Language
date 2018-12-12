#pragma once
#include "Command.h"
class CoutCommand :
	public Command
{
public:
	CoutCommand(string input);
	~CoutCommand();
	virtual void runCommand();
};

