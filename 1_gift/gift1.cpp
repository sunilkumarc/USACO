/*
ID: sunilku1
LANG: C++
PROG: gift1
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>


using namespace std;

int main(void)
{
	map<string, int> friends;
	map<int, string> friends_order;
	map<string, int> initial_amount;
	
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	int num = 0;
	fin >> num;
	int i;
	string name;

	for(i = 0; i < num; ++i) {
		fin >> name;
		friends[name] = 0;
		friends_order[i] = name;
	}

	int money, people_count;
	for(i = 0; i < num; ++i) {
		fin >> name;
		fin >> money >> people_count;
		initial_amount[name] = money;
		int balance;

		if (people_count != 0) {
			balance = money % people_count;
			friends[name] += balance;
		}

		int j;
		string person;
		for(j = 0; j < people_count; ++j) {
			fin >> person;
			friends[person] += money / people_count;			
		}

	}

	for(map<int, string>::iterator ii=friends_order.begin(); ii != friends_order.end(); ++ii) {
		name = (*ii).second;
		fout << name << " " << friends[name] - initial_amount[name] << endl;
	}

	return 0;
}