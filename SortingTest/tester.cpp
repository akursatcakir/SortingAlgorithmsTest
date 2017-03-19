#include "stdafx.h"
#include "tester.h"
#include <vector>
#include <map>
#include <iterator>
#include <Windows.h>

#include <string>
#include <sstream>
#include <iomanip>

#include <iostream>

using namespace std;

//100 nanosecond accuracy
unsigned long long tester::_get_tick() {
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	unsigned long long tt = ft.dwHighDateTime;
	tt <<= 32;
	tt |= ft.dwLowDateTime;
	tt -= 11644473600000000ULL;
	return tt;
}

string tester::_format_time(unsigned long long time) {
	stringstream ss;
	unsigned int decimal = time % 10000000;
	ss << (time-decimal)/10000000 << "." << setw(7) << setfill('0') << left << decimal;
	
	return ss.str();
}

vector<vector<vector<string>>> tester::test() {
	vector<vector<vector<string>>> tables;
	for each (unsigned int count in counts)
	{
		vector<vector<string>> table;
		vector<string > titlerow;
		titlerow.push_back(to_string(count));
		for each (tester::algorithm algorithm in algorithms)
			titlerow.push_back(algorithm.first);
		table.push_back(titlerow);
		for each (tester::creator creator in creators)
		{
			vector<string> row;
			row.push_back(creator.first);
			int* var = creator.second(count);
			for each (tester::algorithm algorithm in algorithms)
			{
				int* vec = new int[count];
				copy(var, var + count, stdext::checked_array_iterator<int*>(vec, count));
				unsigned long long before = _get_tick();
				algorithm.second(vec,count);
				unsigned long long after = _get_tick();
				row.push_back(_format_time(after - before));
				delete vec;
			}
			table.push_back(row);
		}
		tables.push_back(table);
	}
	return tables;
}