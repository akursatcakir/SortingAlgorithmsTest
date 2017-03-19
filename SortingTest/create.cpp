#include "stdafx.h"
#include "create.h"
#include "sorting.h"
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
namespace create {

	typedef pair<unsigned int, int*> Vector;

	map<unsigned int, int*> vectors;

	int _random() {
		int res = (rand() % 3 == 0 ? -1 : +1)*rand();
		for (int i = 0; i < 6; i++)
			if (rand() % 2 == 0)
				res *= (rand() % 9) + 1;
		return res;
	}

	int* random(unsigned int size) {
		int* Result;
		map<unsigned int, int*>::iterator it = vectors.find(size);
		if (it != vectors.end())
			Result = it->second;
		else {
			Result = new int[size];
			for (unsigned int i = 0; i < size; i++)
				Result[i] = _random();
			vectors.insert(Vector(size, Result));
		}
		return Result;
	}

	int* sorted(unsigned int size) {
		int *var = random(size);
		int *Result = new int[size];
		copy(var, var + size, stdext::checked_array_iterator<int*>(Result, size));
		sorting::quick(Result,size);
		return Result;
	}

	int* reversesorted(unsigned int size) {
		int *var = random(size);
		int *Result = new int[size];
		copy(var, var + size, stdext::checked_array_iterator<int*>(Result, size));
		sorting::quick(Result, size);
		reverse(Result, Result + size);
		return Result;
	}
}