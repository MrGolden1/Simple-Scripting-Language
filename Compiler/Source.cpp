#include<iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "Compiler.h"
#include <conio.h>
using namespace std;
int main()
{
	Compiler myCompiler;
	myCompiler.readCode();
	//myCompiler.readFromfile("test.txt");
	myCompiler.findCommands();
	system("cls");
	myCompiler.printCode();
	cout << endl << endl << "output    -----------------------------------" << endl << endl;
	myCompiler.Execute();
	_getch();
	return 0;
}