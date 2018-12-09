#include "Compiler.h"



Compiler::Compiler()
{
}


Compiler::~Compiler()
{
}


string Compiler::makeStringStandard(string line)
{
	string standard;
	int i = 0, j = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
		{
			i++;
		}
		if ((line[i] == '=' && line[i + 1] == '=') || (line[i] == '<' && line[i + 1] == '<') || (line[i] == '<' && line[i + 1] == '=') || (line[i] == '>' && line[i + 1] == '='))
		{
			standard += line[i++];
			standard += line[i++];
			standard += ' ';
			continue;
		}
		if (line[i] == '*' || line[i] == '/' || line[i] == '+' || line[i] == '-' || line[i] == '=' || line[i] == '^' || line[i] == '&' || line[i] == '~' || line[i] == '|' || line[i] == ')' || line[i] == '(' || line[i] == '>' || line[i] == '<' || line[i] == ';')
		{
			standard += line[i++];
			standard += ' ';
			continue;
		}
		else if (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')))
		{
			string buf = "";
			while (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) && line[i])
			{
				buf += line[i];
				standard += line[i++];
			}
			if (buf != "log")
			{
				standard += ' ';
			}
			continue;
		}
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (standard[standard.size() - 1] != 'g' && standard[standard.size() - 2] != 'o' && standard[standard.size() - 3] != 'l')
			{
				standard += "# "; // #sharp show the next element is number
			}
			while (((line[i] >= '0' && line[i] <= '9') || line[i] == '.' || line[i] == '-') && line[i])
			{
				standard += line[i++];
			}
			standard += ' ';
			continue;
		}
		i++;
		standard += "? ";
	}
	return standard;
}