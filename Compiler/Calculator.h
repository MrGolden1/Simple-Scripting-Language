#pragma once
#include "Statement.h"
using namespace std;
class Calculator
{
public:
	Calculator(const map <string, double> & input, string strInput) : var(input), postfix(strInput) {};
	~Calculator();
	double postfixCalculate();
private:
	string postfix;
	map <string, double> var;
};

