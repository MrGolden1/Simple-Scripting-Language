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
		if (!(Evaluate::ifStack.top().first ^ Evaluate::ifStack.top().second))
		{
			return;
		}
	}
	//cout << Evaluate::ifStack.top().first << "     " << Evaluate::ifStack.top().second << endl;
	stringstream ob;
	string word;
	ob << line;
	ob >> word >> word;
	getline(ob, word);
	cout << Evaluate::PostfixEvaluate(st.infixToPostfix( word)) << endl;
}