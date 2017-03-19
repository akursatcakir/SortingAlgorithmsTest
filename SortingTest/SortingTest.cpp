// SortingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sorting.h"
#include "create.h"
#include "tester.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

vector<vector<vector<string>>> test() {
	srand(time(0));

	tester test;
	test.creators.insert(tester::creator("Rastgele", &create::random));
	test.creators.insert(tester::creator("Dogru", &create::sorted));
	test.creators.insert(tester::creator("Ters", &create::reversesorted));

	test.algorithms.insert(tester::algorithm("Selection", &sorting::selection));
	test.algorithms.insert(tester::algorithm("Insertion", &sorting::insertion));
	test.algorithms.insert(tester::algorithm("Bubble", &sorting::bubble));
	test.algorithms.insert(tester::algorithm("Quick", &sorting::quick));
	test.algorithms.insert(tester::algorithm("Merge", &sorting::merge));

	test.counts.push_back(10000);
	test.counts.push_back(20000);
	test.counts.push_back(30000);

	return test.test();
}

void line(unsigned char len) {
	cout << " ";
	for (int i = 0; i < len; i++)
		cout << "-";
	cout << "-\n";
}

int main()
{
	vector<vector<vector<string>>> result = test();
	for each (vector<vector<string>> table in result)
	{
		line(table.at(0).size() * 12);
		bool first = true;
		for each (vector<string> row in table)
		{
			cout << " |";
			for each (string cell in row)
				cout << setw(11) << (!first&&row.at(0) != cell ? right : left) << cell << "|";
			cout << "\n";
			if (first) {
				line(table.at(0).size() * 12);
				first = false;
			}
		}
		line(table.at(0).size() * 12);
		cout << "\n\n\n";
	}

	system("PAUSE");
    return 0;
}

