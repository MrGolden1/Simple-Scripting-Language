#include "Assignment.h"
using namespace std;
Assignment::Assignment(string input, map<string, double> &in, stack <pair<bool, bool>> &r) : var(in) ,Command(r)
{
	line = input;
}


Assignment::~Assignment()
{
}

void Assignment::runCommand()
{
	if (!runStatus.empty())
	{
		if (!(runStatus.top().first ^ runStatus.top().second))
		{
			return;
		}
	}
	parsingExpression();
	Evaluate ev(right,var);
	var[left] = ev.PostfixEvaluate();
}

void Assignment::parsingExpression() 
{
	string buf = line;
	int assignLocation = buf.find('=');
	right = buf.substr(assignLocation + 1);
	left = buf.erase(assignLocation - 1);
}