#include "IfCommand.h"

stack <pair<bool,bool>> Evaluate::ifStack;

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
	if (!Evaluate::ifStack.empty())
	{
		if (Evaluate::ifStack.top().first && Evaluate::ifStack.top().second)
		{
			Evaluate::ifStack.push(make_pair(true, true));
			return;
		}
	}
	Evaluate::ifStack.push(make_pair(false, false));
	stringstream ob, expression;
	string word;
	ob << line;
	ob >> word;
	while (ob >> word && word != "then")
	{
		expression << word + " ";
	}
	bool conditon = Evaluate::logicPostfixEvaluate(st.infixToPostfix(expression.str()));
//	cout << "con : " << conditon << endl;
	if (conditon)
	{
		Evaluate::ifStack.pop();
		Evaluate::ifStack.push(make_pair(true, false));
	}
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
	if (Evaluate::ifStack.top().first && Evaluate::ifStack.top().second)
	{
		return;
	}
	if (Evaluate::ifStack.top().first && !Evaluate::ifStack.top().second)
	{
		Evaluate::ifStack.pop();
		Evaluate::ifStack.push(make_pair(true, true));
		return;
	}
	stringstream ob, expression;
	string word;
	ob << line;
	ob >> word;
	while (ob >> word && word != "then")
	{
		expression << word + " ";
	}
	bool conditon = Evaluate::logicPostfixEvaluate(st.infixToPostfix(expression.str()));
	if (conditon)
	{
		Evaluate::ifStack.pop();
		Evaluate::ifStack.push(make_pair(true, false));
	}
}


ElseCommand::ElseCommand()
{
}

ElseCommand::~ElseCommand()
{
}

void ElseCommand::runCommand()
{
	if (Evaluate::ifStack.top().first && Evaluate::ifStack.top().second)
	{
		return;
	}
	if (Evaluate::ifStack.top().first && !Evaluate::ifStack.top().second)
	{
		Evaluate::ifStack.pop();
		Evaluate::ifStack.push(make_pair(true, true));
		return;
	}
	Evaluate::ifStack.pop();
	Evaluate::ifStack.push(make_pair(true, false));
	return;
}

End::End()
{

}

End::~End()
{

}

void End::runCommand() 
{
	{
		Evaluate::ifStack.pop();
	}
}
