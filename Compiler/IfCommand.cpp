#include "IfCommand.h"
using namespace std;


IfCommand::IfCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r) : var(in) , Command(r)
{
	line = input;
}

IfCommand::~IfCommand()
{
}

void IfCommand::runCommand() 
{
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
	Evaluate ev(buf.erase(0,3),var);
	bool conditon =ev.PostfixEvaluate();
	if (conditon)
	{
		runStatus.pop();
		runStatus.push(make_pair(true, false));
	}
}



ElseIfCommand::ElseIfCommand(string input, map<string, double> &in, stack <pair<bool, bool>> &r) : IfCommand(input,in,r)
{
}

ElseIfCommand ::~ElseIfCommand()
{
}

void ElseIfCommand::runCommand()
{
	if (runStatus.top().first && runStatus.top().second)
	{
		return;
	}
	if (runStatus.top().first && !runStatus.top().second)
	{
		runStatus.pop();
		runStatus.push(make_pair(true, true));
		return;
	}
	string buf = line;
	Evaluate ev(buf.erase(0,3),var);
	bool conditon = ev.PostfixEvaluate();
	if (conditon)
	{
		runStatus.pop();
		runStatus.push(make_pair(true, false));
	}
}


ElseCommand::ElseCommand(stack <pair<bool, bool>> &r) : Command(r)
{
}

ElseCommand::~ElseCommand()
{
}

void ElseCommand::runCommand()
{
	if (runStatus.top().first && runStatus.top().second)
	{
		return;
	}
	if (runStatus.top().first && !runStatus.top().second)
	{
		runStatus.pop();
		runStatus.push(make_pair(true, true));
		return;
	}
	runStatus.pop();
	runStatus.push(make_pair(true, false));
	return;
}

End::End(stack <pair<bool, bool>> &r) : Command(r)
{

}

End::~End()
{

}

void End::runCommand() 
{
	{
		runStatus.pop();
	}
}
