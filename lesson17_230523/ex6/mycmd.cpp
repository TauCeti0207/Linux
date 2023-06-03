//mycmd.cpp
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	cout << "PATH:" << getenv("PATH") << endl;                                 
	cout << "--------------------------" << endl;
	cout << "MYPATH:" << getenv("MYPATH") << endl;
	cout << "--------------------------" << endl;
	cout <<"hello C++"<<endl;
  	return 0;
}
