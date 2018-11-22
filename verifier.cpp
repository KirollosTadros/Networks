#include <iostream>
#include <string>
#include "common.h"
using namespace std;

int main()
{
	string generatorOutput;
	string generator;
	getline(cin,generatorOutput);
	getline(cin,generator);
	string remainder = get_remainder(generatorOutput, generator);
	if (remainder=="")
		cout<<"Message is correct"<<endl;
	else
		cout<<"An error has occured"<<endl;

}