#include "WhileCommand.h"



WhileCommand::WhileCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r , stack <int> &l,int &curr) : var(in) , Command(r) , loopLocator(l),currentCommand(curr)
{
	line = input;
}


WhileCommand::~WhileCommand()
{

}

void WhileCommand::runCommand()
{
	loopLocator.push(currentCommand);
	if (!runStatus.empty())
	{
		if (runStatus.top().first && runStatus.top().second)
		{
			runStatus.push(make_pair(true, true));
			return;
		}
	}
	runStatus.push(make_pair(false, false));
	string buf = line;
	Evaluate ev(buf.erase(0, 6), var);
	bool conditon = ev.PostfixEvaluate();
	if (conditon)
	{
		runStatus.pop();
		runStatus.push(make_pair(true, false));
	}
	else
	{
		runStatus.pop();
		runStatus.push(make_pair(true, true));
	}
}


FinishCommand::FinishCommand(stack <pair<bool, bool>> &r, stack <int> &l, int &curr) : Command(r), currentCommand(curr) ,loopLocator(l)
{
}

FinishCommand::~FinishCommand()
{
}

void FinishCommand::runCommand()
{
	if (runStatus.top().first && !runStatus.top().second)
	{
		currentCommand = loopLocator.top() - 1;
		runStatus.pop();
		loopLocator.pop();
		return;
	}
	runStatus.pop();
	loopLocator.pop();
}
