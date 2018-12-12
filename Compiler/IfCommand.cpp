#include "IfCommand.h"



IfCommand::IfCommand()
{
}


IfCommand::IfCommand(string input)
{
	line = input;
}

IfCommand::~IfCommand()
{
}

void IfCommand::runCommand() 
{
	int buf;
}


ElseIfCommand::ElseIfCommand()
{
}

ElseIfCommand::ElseIfCommand(string input)
{
	line = input;
}

ElseIfCommand ::~ElseIfCommand()
{
}

void ElseIfCommand::runCommand() 
{
	int buf;
}


ElseCommand::ElseCommand()
{
}

ElseCommand::~ElseCommand()
{
}

void ElseCommand::runCommand() 
{
	int buf;
}

End::End()
{
}

End::~End()
{
}

void End::runCommand() 
{
	int buf;
}
