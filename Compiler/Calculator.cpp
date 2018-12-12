#include "Calculator.h"
constexpr auto PI = 3.141592653589793;
constexpr auto CoDegreeToRadian = PI / 180;
using namespace std;
map <string, double> Calculator::var;
Calculator::~Calculator()
{
}

double Calculator::postfixCalculate(string postfix)
{
	stack <double> st;
	stringstream line;
	line << postfix;
	string word;
	double operand1, operand2;
	while (line >> word)
	{
		if (Calculator::Calculator::var.find(word) == Calculator::var.end())
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
			st.push(Calculator::var[word]);
		}
	}
	return st.top();
	return 0;
}

