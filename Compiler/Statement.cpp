#include "Statement.h"
#include <stack>
using namespace std;

Statement::Statement(string in) : infix(in) 
{
	// initiate the precede of the operators
	prec = { {"(" , 1}  ,{"+" , 2} ,{"-" , 2} ,{"*" , 3},{"/" , 3} ,{"^" , 4} , {"sin" , 5} , {"cos" , 5}, {"tan" , 5}, {"log2" , 5}, {"log10" , 5} };
};
Statement::~Statement()
{
}

string Statement::getPostfixString()
{
	return postfix;
}

string Statement::infixToPostfix()
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
	return postfix;
}
