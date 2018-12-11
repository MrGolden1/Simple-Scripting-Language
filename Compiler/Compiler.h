#pragma once
#include <string>
#include <vector>
#include "Statement.h"
using namespace std;
class Compiler
{
public:
	Compiler();
	~Compiler();
	void readCode(); // read codes from cmd while eof
	void StringsToStandard();
	void printCode();
	void findCommands();
	string makeStringStandard(string line);
private:
	vector <string> lines;
	map <string, double> var;
};

