#include "Compiler.h"



Compiler::Compiler()
{
}


Compiler::~Compiler()
{
}

void Compiler::readCode()
{
	string buf;
	while (!cin.eof())
	{
		getline(cin, buf);
		lines.push_back(buf);
	}
	lines.pop_back();
}

void Compiler::StringsToStandard()
{
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i] = makeStringStandard(lines[i]);
	}
}

void Compiler::printCode()
{
	for (int i = 0; i < lines.size(); i++)
	{
		cout << lines[i] << endl;
	}
}

void Compiler::findCommands()
{
	Command *a;
	string word;
	for (int i = 0; i < lines.size(); i++)
	{
		stringstream ob;
		ob << lines[i];
		ob >> word;
		if (word == "cout")
		{
			a = new CoutCommand(lines[i]);
			MC.push_back(a);
			continue;
		}
		if (word == "if")
		{
			a = new IfCommand(lines[i]);
			MC.push_back(a);
			continue;
		}
		if (word == "elseif")
		{
			a = new ElseIfCommand(lines[i]);
			MC.push_back(a);
			continue;
		}
		if (word == "else")
		{
			a = new ElseCommand;
			MC.push_back(a);
			continue;
		}
		if (word == "end")
		{
			a = new End;
			MC.push_back(a);
			continue;
		}
		ob >> word;
		if (word == "=")
		{
			a = new Assignment(lines[i]);
			MC.push_back(a);
			continue;
		}
	}
}

void Compiler::Execute()
{
	for (int i = 0; i < MC.size(); i++)
	{
		MC[i]->runCommand();
	}
}

string Compiler::makeStringStandard(string line)
{
	string standard;
	bool preIsOperator = false;
	int i = 0;
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
			preIsOperator = false;
			continue;
		}
		if (!preIsOperator && (line[i] == '*' || line[i] == '/' || line[i] == '+' || line[i] == '-' || line[i] == '=' || line[i] == '^' || line[i] == '&' || line[i] == '~' || line[i] == '|' || line[i] == '>' || line[i] == '<' || line[i] == ';' ) )
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = true;
			continue;
		}
		if (line[i] == ')')
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		if (line[i] == '(')
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = true;
			continue;
		}
		if (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')))
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
			preIsOperator = false;
			continue;
		}
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (standard.size() < 2 || standard[standard.size() - 2] == '(' || (standard[standard.size() - 1] != 'g' && standard[standard.size() - 2] != 'o' && standard[standard.size() - 3] != 'l'))
			{
				standard += "# "; // #sharp show the next element is number
			}
			if (line[i] == '-')
			{
				standard += line[i++];
			}
			while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
			{
				standard += line[i++];
			}
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		i++;
		standard += "? ";
	}
	return standard;
}
