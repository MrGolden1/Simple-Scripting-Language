#pragma once
#include <string>
#include "Statement.h"
using namespace std;
class Compiler
{
public:
	Compiler();
	~Compiler();
	string makeStringStandard(string line);
private:
	map <string, double> var;
};

