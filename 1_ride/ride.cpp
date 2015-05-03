/*
ID: sunilku1
LANG: C++
PROG: ride
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(void)
{
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	char comet[8], group[8];
	fin >> comet >> group;
	
	int comet_val = 1, group_val = 1;
	int i;
	int comet_len = strlen(comet);
	int group_len = strlen(group);
	
	for(i = 0; i < comet_len; ++i)
		comet_val *= (comet[i] - 64);
	
	for(i = 0; i < group_len; ++i)
		group_val *= (group[i] - 64);

	comet_val %= 47;
	group_val %= 47;

	if(comet_val == group_val)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;

	return 0;
}