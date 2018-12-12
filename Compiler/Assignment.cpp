#include "Assignment.h"

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
	parsingExpression();
	Statement st(right);
	Calculator::var[left] = Calculator::postfixCalculate(st.infixToPostfix());
	cout << Calculator::var[left] << endl;
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