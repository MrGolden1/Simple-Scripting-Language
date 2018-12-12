#include<iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "Statement.h"
#include "Calculator.h"
#include "Compiler.h"
#include <conio.h>
using namespace std;
int main()
{
	Compiler myCompiler;
	myCompiler.readCode();
	myCompiler.StringsToStandard();
	myCompiler.printCode();
	myCompiler.findCommands();
	myCompiler.Execute();
	_getch();
	return 0;
}