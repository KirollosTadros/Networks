#include <iostream>
#include <string>
#include "common.h"
using namespace std;

int main(int argc, char **argv)
{
	int alter;
	if(argc>1)
	{
	alter = stoi(argv[1]);
	}
	string generatorOutput;
	string polynomial;
	getline(cin,generatorOutput);
	getline(cin,polynomial);
	if(alter<=generatorOutput.length()&&alter>0)
	{
	if(generatorOutput[alter-1]=='1')
		generatorOutput[alter-1]='0';
	else
		generatorOutput[alter-1]='1';
	}
	cout<<generatorOutput<<endl;
	cout<<polynomial<<endl;


}
