/*
ID: sunilku1
LANG: C++
TASK: test
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ofstream fout ("test.out");
	ifstream fin ("test.in");
	int a, b;
	fin >> a >> b;
	fout << a + b << endl;

	return 0;	
}