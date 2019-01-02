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
		lines.push_back(makeStringStandard(buf));
	}
	lines.pop_back();
}

void Compiler::readFromfile(string FileName)
{
	ifstream iMyFile;
	string buf;
	iMyFile.open(FileName, ios::app);
	while (!iMyFile.eof())
	{
		getline(iMyFile, buf);
		lines.push_back(makeStringStandard(buf));
	}
	iMyFile.close();
}



void Compiler::printCode()
{
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; lines[i][j] ; j++)
		{
			if (lines[i][j] != '#')
			{
				cout << lines[i][j];
			}
		}
		cout << endl;
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
			a = new CoutCommand(lines[i], var,runStatus);
			MC.push_back(a);
			continue;
		}
		if (word == "if")
		{
			a = new IfCommand(lines[i],var,runStatus);
			MC.push_back(a);
			continue;
		}
		if (word == "elseif")
		{
			a = new ElseIfCommand(lines[i],var,runStatus);
			MC.push_back(a);
			continue;
		}
		if (word == "else")
		{
			a = new ElseCommand(runStatus);
			MC.push_back(a);
			continue;
		}
		if (word == "end")
		{
			a = new End(runStatus);
			MC.push_back(a);
			continue;
		}
		if (word == "while")
		{
			a = new WhileCommand(lines[i], var, runStatus,loopLocator,runningLine);
			MC.push_back(a);
			continue;
		}
		if (word == "finish")
		{
			a = new FinishCommand(runStatus, loopLocator, runningLine);
			MC.push_back(a);
			continue;
		}
		ob >> word;
		if (word == "=")
		{
			a = new Assignment(lines[i],var,runStatus);
			MC.push_back(a);
			continue;
		}
	}
}

void Compiler::Execute()
{
	runningLine = 0;
	for (; runningLine < MC.size(); runningLine++)
	{
		MC[runningLine]->runCommand();
	}
}

string Compiler::makeStringStandard(string line)
{
	string standard;
	bool preIsOperator = false;
	int i = 0;
	while (i < line.size())
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
			preIsOperator = true;
			continue;
		}
		if ( !preIsOperator && (line[i] == '*' || line[i] == '/' || line[i] == '+' || line[i] == '-' || line[i] == '=' || line[i] == '^' ) )
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = true;
			continue;
		}
		if (line[i] == ';')
		{
			i++;
			continue;
		}
		if (line[i] == ')' )
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = false;
			continue;
		}
		if ( line[i] == '&' || line[i] == '~' || line[i] == '|' || line[i] == '>' || line[i] == '<')
		{
			standard += line[i++];
			standard += ' ';
			preIsOperator = true;
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
			if (buf == "if" || buf == "elseif" || buf == "else" || buf == "while")
			{
				preIsOperator = true;
			}
			else preIsOperator = false;
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


