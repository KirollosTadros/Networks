#include <iostream>
#include <string>
#include "common.h"
using namespace std;

int main()
{
	int alter;
	string generatorOutput;
	string inverted;
	getline(cin,generatorOutput);
	cin>>alter;
	if(generatorOutput[alter-1]=='1')
		inverted="0";
	else
		inverted="1";
	cout<<generatorOutput.substr(0,alter-1)+inverted+generatorOutput.substr(alter,generatorOutput.length()-alter+1)<<endl;

}
