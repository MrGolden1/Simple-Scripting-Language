#pragma once
#include <string>
#include <iostream>
#include <map>
using namespace std;
class Command
{
public:
	Command();
	~Command();
	static void setVariables(map <string, double> & in);
protected:
	string line;
	static map <string, double> & var;
};
