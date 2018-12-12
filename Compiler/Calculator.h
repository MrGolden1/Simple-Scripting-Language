#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;
class Calculator
{
public:
	Calculator() {};
	~Calculator();
	static double postfixCalculate(string postfix);
	static map<string, double> var;
private:
};