#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <map>
using namespace std;
class Statement
{
public:
	Statement(string in);
	~Statement();
	string getPostfixString();
	void infixToPostfix();
	void makeStringStandard();
private:
	string infix;
	string postfix;
	bool valid;
	map <string, int> prec;
};

