/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-23 09:39:53
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-23 10:21:15
 */
// mycmd.cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[], char **env)
{
	cout << argv[0] << " begin running " << endl;
	cout << "这是命令行参数：" << endl;
	for (int i = 0; argv[i]; i++)
	{
		cout << i << ":" << argv[i] << endl;
	}
	cout << "这是环境变量信息：" << endl;

	for (int i = 0; env[i]; i++)
	{
		cout << i << ":" << env[i] << endl;
	}

	cout << argv[0] << " stop running " << endl;
	return 0;
}
int main2()
{
	cout << "PATH:" << getenv("PATH") << endl;
	cout << "--------------------------" << endl;
	// cout << "MYPATH:" << getenv("MYPATH") << endl;
	cout << "--------------------------" << endl;
	cout << "hello C++" << endl;
	cout << "hello C++" << endl;
	cout << "hello C++" << endl;
	cout << "hello C++" << endl;
	return 0;
}
