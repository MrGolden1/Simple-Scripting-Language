#pragma once
#define ll long long // integer number
#define fp double // floating point number
class Var
{
public:
	Var();
	~Var();
private:
	union
	{
		ll x;
		fp y;
	};
	bool type; // flase integer , true float
};

