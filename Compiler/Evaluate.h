#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;
class Evaluate
{
public:
	Evaluate();
	~Evaluate();
	static double mathPostfixEvaluate(string postfix);
	static bool logicPostfixEvaluate(string postfix);
	static map<string, double> var;
	static stack <pair<bool,bool>> ifStack;
};

