#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <fstream>
#include <math.h>
using namespace std;
class Evaluate
{
public:
	Evaluate(string str, map<string, double> &in);
	~Evaluate();
	double PostfixEvaluate();
private:
	void infixToPostfix();
	string statement;
	string postfix;
	static map<string,int> prec;
	map<string, double> &var;
	bool isNumber(string s);
};

