#include "Statement.h"
#include <stack>
using namespace std;

Statement::Statement()
{
	// initiate the precede of the operators
	prec = { {"(" , 1}  ,{"+" , 7} ,{"-" , 7} ,{"*" , 8},{"/" , 8} ,{"^" , 9} , {"sin" , 10} , {"cos" , 10}, {"tan" , 10}, {"log2" , 10}, {"log10" , 10} , {"&" , 2}  , {"|" , 2}  , {"==" , 3}  , {">" , 3}  , {"<" , 3}  , {"<=" , 3}  ,{">=" , 3}  , {"~" , 4} };
};
Statement::~Statement()
{
}

string Statement::infixToPostfix(string infix)
{
	string postfix;
	stack <string> st;
	stringstream line;
	string word;
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
			while (!st.empty() && prec[word] <= prec[st.top()] && (word != "^" && st.top() != "^"))
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
