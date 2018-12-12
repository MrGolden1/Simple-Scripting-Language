#include "Command.h"



Command::Command()
{
}


Command::~Command()
{
}

void Command::setVariables(map<string, double> & in)
{
	var = in;
}
