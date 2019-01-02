#pragma once
#include <string>
#include <vector>
#include "Command.h"
#include "IfCommand.h"
#include "Assignment.h"
#include "CoutCommand.h"
#include "WhileCommand.h"
using namespace std;
class Compiler
{
public:
	Compiler();
	~Compiler();
	//////////////////////////////// methods

	void readCode(); // read codes from cmd while eof
	void readFromfile(string); // read code from file
	void printCode();
	void findCommands();
	void Execute();

private:

	/////////////////////////////// methods

	string makeStringStandard(string line);

	////////////////////////////// members

	vector <string> lines;
	vector <Command *> MC;
	map<string, double> var;
	stack <pair<bool, bool>> runStatus;
	stack <int> loopLocator;
	int runningLine;
};
