#include "Assignment.h"
Statement Command::st;
using namespace std;
Assignment::Assignment(string input)
{
	line = input;
}


Assignment::~Assignment()
{
}

void Assignment::runCommand()
{
	if (!Evaluate::ifStack.empty())
	{
		if (Evaluate::ifStack.top().first && Evaluate::ifStack.top().second)
		{
			return;
		}
	}
	parsingExpression();
	Evaluate::var[left] = Evaluate::mathPostfixEvaluate(st.infixToPostfix(right));
}

void Assignment::parsingExpression() 
{
	stringstream ob;
	string word;
	ob << line;
	ob >> word;
	left = word;
	ob >> word; // get = and take it away
	getline(ob, right);
}