#include<iostream>
#include <math.h>
#include <string>
#include <sstream>
#include "Statement.h"
#include "Calculator.h"
#include <conio.h>
using namespace std;

int main()
{
	/*union MyUnion
	{
		long long x;
		double y;
	};
	MyUnion t;
	long long m = 9223372036854775807;
	//cout << m;
	for (long long i = 9223372036854775808 ; i < m; i++)
	{
		t.x = i;
		if (t.x == t.y)
			cout << i << endl;
	}
	cout << ":)";*/
	stringstream code;
	string line;
	getline(cin, line);
	Statement st(line);
	st.infixToPostfix();
	cout << st.getPostfixString() << endl;
	map<string, double>buf;
	Calculator cal(buf, st.getPostfixString());
	cout << cal.postfixCalculate();
	_getch();
	return 0;
}