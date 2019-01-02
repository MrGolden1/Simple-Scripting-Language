#include "Evaluate.h"
constexpr auto PI = 3.141592653589793;
using namespace std;
map <string, int> Evaluate::prec = { {"(" , 1}  ,{"+" , 7} ,{"-" , 7} ,{"*" , 8},{"/" , 8} ,{"^" , 9} , {"sin" , 10} , {"cos" , 10}, {"tan" , 10}, {"log2" , 10}, {"log10" , 10} , {"&" , 2}  , {"|" , 2}  , {"==" , 3}  , {">" , 3}  , {"<" , 3}  , {"<=" , 3}  ,{">=" , 3}  , {"~" , 4} };
Evaluate::Evaluate(string str , map<string, double> &in) : var(in), statement(str)
{
	infixToPostfix();
}
Evaluate::~Evaluate()
{
}

void Evaluate::infixToPostfix()
{
	postfix = "";
	stack <string> st;
	stringstream line;
	string word;
	line << statement;
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
}

double Evaluate::PostfixEvaluate()
{
	stack <double> st;
	stringstream line;
	line << postfix;
	string word;
	double operand1, operand2;
	while (line >> word)
	{
		if (var.find(word) == var.end())
		{
			switch (word[0])
			{
			case '#':
			{
				line >> operand1;
				st.push(operand1);
				/*if (word == "#")
				{
					line >> operand1;
					st.push(operand1);
					break;
				}
				if (isNumber(word))
					st.push(stof(word));
				else st.push(var[word]);*/
			}
			break;
			case '|':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(operand1 || operand2);
			}
			break;
			case '&':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(operand1 && operand2);
			}
			break;
			case '~':
			{
				operand1 = st.top();
				st.pop();
				st.push(!(bool)(operand1));
			}
			break;
			case '<':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				if (word == "<=")
				{
					st.push(operand1 <= operand2);
				}
				else
				{
					st.push(operand1 < operand2);
				}
			}
			break;
			case '>':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				if (word == ">=")
				{
					st.push(operand1 >= operand2);
				}
				else
				{
					st.push(operand1 > operand2);
				}
			}
			break;
			case '=':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				/*if (operand1 -int(operand1) > 0.99999999999999)
				{
					operand1 = int(operand1) + 1;
				}
				if (operand2 - int(operand2) > 0.99999999999999)
				{
					operand2 = int(operand2) + 1;
				}*/
				/*operand1 /= 1000;
				operand1 *= 1000;
				operand2 /= 1000;
				operand2 *= 1000;*/
				st.push(operand1 == operand2);
			}
			break;
			case '+':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(operand1 + operand2);
			}
			break;
			case '-':
			{
				operand2 = st.top();
				st.pop();
				if (!st.empty())
				{
					operand1 = st.top();
					st.pop();
				}
				else operand1 = 0;
				st.push(operand1 - operand2);
			}
			break;
			case '*':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(operand1 * operand2);
			}
			break;
			case '/':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(operand1 / operand2);
			}
			break;
			case '^':
			{
				operand2 = st.top();
				st.pop();
				operand1 = st.top();
				st.pop();
				st.push(pow(operand1, operand2));
			}
			break;
			break;
			default:
			{
				if (word == "sin")
				{
					operand1 = st.top();
					st.pop();
					st.push(sin(operand1 * PI / 180));
				}
				else if (word == "cos")
				{
					operand1 = st.top();
					st.pop();
					st.push(cos(operand1 * PI / 180));
				}
				else if (word == "tan")
				{
					operand1 = st.top();
					st.pop();
					st.push(tan(operand1 * PI / 180));
				}
				else if (word == "log2")
				{
					operand1 = st.top();
					st.pop();
					st.push(log2(operand1));
				}
				else if (word == "log10")
				{
					operand1 = st.top();
					st.pop();
					st.push(log10(operand1));
				}
			}
			break;
			}
		}
		else {
			st.push(var[word]);
		}
	}
	return (st.top());
}

bool Evaluate::isNumber(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '.' )
		{
			return false;
		}
	}
	return true;
}
