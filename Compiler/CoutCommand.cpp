#include "CoutCommand.h"





CoutCommand::CoutCommand(string input)
{
	line = input;
}

CoutCommand::~CoutCommand()
{
}

void CoutCommand::runCommand()
{
	if (!Evaluate::ifStack.empty())
	{
		if (Evaluate::ifStack.top().first && Evaluate::ifStack.top().second)
		{
			return;
		}
	}
	stringstream ob;
	string word;
	ob << line;
	ob >> word >> word >> word;
	cout << word << " = " << Evaluate::var[word] << endl;
}