#pragma once
#include <string>
#include <vector>
#include <map>


using namespace std;

class tester {

private:
	unsigned long long _get_tick();
	string _format_time(unsigned long long time);
public:
	typedef int*(*PCreate)(unsigned int);
	typedef void(*PAlgorithm)(int*, unsigned int);
	typedef pair<string, PCreate> creator;
	typedef pair<string, PAlgorithm> algorithm;

	map<string, PCreate> creators;
	map<string, PAlgorithm> algorithms;
	vector<unsigned int> counts;

	vector<vector<vector<string>>> test();
};