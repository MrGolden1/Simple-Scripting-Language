#pragma once
#include <string>
#include <vector>
#include "Statement.h"
#include "Command.h"
#include "IfCommand.h"
#include "Assignment.h"
#include "CoutCommand.h"
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
	vector <Command *> MC;
	map <string, double> var;
};

