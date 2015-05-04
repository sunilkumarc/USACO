/*
ID: sunilku1
LANG: C++
PROG: friday
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>

using namespace std;

int isLeap(int year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year %4 == 0));
}

int find_day(int month, int isleap, int previous_month_13_day)
{
	map<int, int> month_offset;
	month_offset[0] = 31;
	month_offset[2] = 31;
	month_offset[3] = 30;
	month_offset[4] = 31;
	month_offset[5] = 30;
	month_offset[6] = 31;
	month_offset[7] = 31;
	month_offset[8] = 30;
	month_offset[9] = 31;
	month_offset[10] = 30;
	month_offset[11] = 31;
	if(isleap)
		month_offset[1] = 29;
	else
		month_offset[1] = 28;

	map<int, int> day_offset;
	day_offset[28] = 0;
	day_offset[29] = 1;
	day_offset[30] = 2;
	day_offset[31] = 3;

	return (previous_month_13_day + day_offset[month_offset[month-1]]) % 7;
}

void calculate(int year, int isleap, int day, int * final_values)
{
	int month;

	int previous_month_13_day = ((day + 5) % 7);
	++(final_values[previous_month_13_day]);

	// For each month from feb - dec
	for(month = 1; month < 12; ++month) {
		previous_month_13_day = find_day(month, isleap, previous_month_13_day);
		++(final_values[previous_month_13_day]);
	} 
}

int main(void)
{
	ifstream fin ("friday.in");
	ofstream fout ("friday.out");
	int N;
	fin >> N;
	int i;
	int years = 1900 + N;

	int final_values[7] = {0};

	int day = 2;
	for(i = 1900; i < years; ++i) {
		int isleap = isLeap(i);
		calculate(i, isleap, day % 7, final_values);

		if(isleap)
			day += 2;
		else
			day += 1;
	}

	for(i = 0; i < 6; ++i) {
		fout << final_values[i] << " ";
	}
	fout << final_values[6] << endl;

	return 0;
}