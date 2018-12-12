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
	Statement();
	~Statement();
	string infixToPostfix(string infix);
private:
	map <string, int> prec;
};

