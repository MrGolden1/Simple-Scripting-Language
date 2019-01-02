#include "CoutCommand.h"


CoutCommand::CoutCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r) : var(in) ,Command(r)
{
	line = input;
}

CoutCommand::~CoutCommand()
{
}

void CoutCommand::runCommand()
{
	if (!runStatus.empty())
	{
		if (!(runStatus.top().first ^ runStatus.top().second))
		{
			return;
		}
	}
	int printLocation = line.find("<<");
	Evaluate ev(line.substr(printLocation + 2),var);
	cout << ev.PostfixEvaluate() << endl;
}