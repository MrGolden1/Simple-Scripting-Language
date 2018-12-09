#include "Statement.h"
#include <stack>
using namespace std;

Statement::Statement(string in) : leftSide(NULL), infix(in) 
{
	// initiate the precede of the operators
	makeStringStandard();
	prec = { {"(" , 1}  ,{"+" , 2} ,{"-" , 2} ,{"*" , 3},{"/" , 3} ,{"^" , 4} , {"sin" , 5} , {"cos" , 5}, {"tan" , 5}, {"log2" , 5}, {"log10" , 5} };
};
Statement::~Statement()
{
}

string Statement::getPostfixString()
{
	return postfix;
}

void Statement::infixToPostfix()
{
	stack <string> st;
	stringstream line;
	string word;
	cout << infix << endl;
	line << infix;
	while (line >> word)
	{
		if (word == "(")
		{
			st.push(word);
			continue;
		}
		if (!(prec.find(word) == prec.end()))
		{
			while (!st.empty() && prec[word] <= prec[st.top()])
			{
				postfix += st.top() + " ";
				st.pop();
			}
			st.push(word);
			continue;
		}
		else
		{
			if (word == ")")
			{
				while (!st.empty() && st.top() != "(")
				{
					postfix += st.top() + " ";
					st.pop();
				}
				if (!st.empty() && st.top() == "(")
				{
					st.pop();
				}
				continue;
			}
			postfix += word + " ";
		}
	}
	while (!st.empty())
	{
		postfix += st.top() + " ";
		st.pop();
	}
}

void Statement::makeStringStandard()
{
	string standard;
	bool preIsOperator = false;
	int i = 0;
	while (infix[i])
	{
		while (infix[i] && infix[i] == ' ')
		{
			i++;
		}
		if ((infix[i] == '=' && infix[i + 1] == '=') || (infix[i] == '<' && infix[i + 1] == '<') || (infix[i] == '<' && infix[i + 1] == '=') || (infix[i] == '>' && infix[i + 1] == '='))
		{
			standard += infix[i++];
			standard += infix[i++];
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		if (!preIsOperator && (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '=' || infix[i] == '^' || infix[i] == '&' || infix[i] == '~' || infix[i] == '|' || infix[i] == '>' || infix[i] == '<' || infix[i] == ';' || infix[i] == '('))
		{
			standard += infix[i++];
			standard += ' ';
			preIsOperator = true;
			continue;
		}
		if (infix[i] == ')')
		{
			standard += infix[i++];
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		if (((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')))
		{
			string buf = "";
			while (((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) && infix[i])
			{
				buf += infix[i];
				standard += infix[i++];
			}
			if (buf != "log")
			{
				standard += ' ';
			}
			preIsOperator = false;
			continue;
		}
		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '-')
		{
			if ( standard.size() < 2 || standard[standard.size() - 2] == '(' || ( standard[standard.size() -1] != 'g' && standard[standard.size() - 2] != 'o' && standard[standard.size() - 3] != 'l'))
			{
				standard += "# "; // #sharp show the next element is number
			}
			if (infix[i] == '-')
			{
				standard += infix[i++];
			}
			while ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.')
			{
				standard += infix[i++];
			}
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		i++;
		standard += "? ";
	}
	infix = standard;
}
