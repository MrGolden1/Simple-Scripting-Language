#include "Evaluate.h"
constexpr auto PI = 3.141592653589793;
constexpr auto CoDegreeToRadian = PI / 180;
using namespace std;
map <string, double> Evaluate::var;
Evaluate::~Evaluate()
{
}

bool Evaluate::logicPostfixEvaluate(string postfix)
{
	stack <double> st;
	stringstream line;
	line << postfix;
	string word;
	double operand1, operand2;
	while (line >> word)
	{
		if (Evaluate::Evaluate::var.find(word) == Evaluate::var.end())
		{
			switch (word[0])
			{
			case '#':
			{
				line >> operand1;
				st.push(operand1);
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
				operand2 = st.top();
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
				if (operand1 -int(operand1) > 0.99999999999999)
				{
					operand1 = int(operand1) + 1;
				}
				if (operand2 - int(operand2) > 0.99999999999999)
				{
					operand2 = int(operand2) + 1;
				}
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
				operand1 = st.top();
				st.pop();
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
		else
		{
			st.push(Evaluate::var[word]);
		}
	}
	return bool(st.top());
}

double Evaluate::mathPostfixEvaluate(string postfix)
{
	stack <double> st;
	stringstream line;
	line << postfix;
	string word;
	double operand1, operand2;
	while (line >> word)
	{
		if (Evaluate::Evaluate::var.find(word) == Evaluate::var.end())
		{
			switch (word[0])
			{
			case '#':
			{
				line >> operand1;
				st.push(operand1);
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
				operand1 = st.top();
				st.pop();
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
		else
		{
			st.push(Evaluate::var[word]);
		}
	}
	return st.top();
}

