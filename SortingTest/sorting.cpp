#include "stdafx.h"
#include "sorting.h"
#include <algorithm>
#include <iterator>

using namespace std;

namespace sorting {

	void bubble(int *Vector, unsigned int size) {
		bool swapped;
		do {
			swapped = false;
			for (unsigned int i = 0; i < size - 1; i++)
				if (Vector[i] > Vector[i + 1]) {
					int tmp = Vector[i];
					Vector[i] = Vector[i + 1];
					Vector[i + 1] = tmp;
					swapped = true;
				}
		} while (swapped);
	}

	void selection(int *Vector, unsigned int size) {
		for (unsigned int i = 0; i < size - 1; i++) {
			unsigned int iMin = i;
			for (unsigned int j = i + 1; j < size; j++)
				if (Vector[iMin] > Vector[j])
					iMin = j;
			int tmp = Vector[i];
			Vector[i] = Vector[iMin];
			Vector[iMin] = tmp;
		}
	}

	void insertion(int *Vector, unsigned int size) {
		for (unsigned int i = 1; i < size; i++) {
			unsigned int j = i;
			while (j > 0 && Vector[j - 1] > Vector[j]) {
				int tmp = Vector[j];
				Vector[j] = Vector[j - 1];
				Vector[j - 1] = tmp;
				j--;
			}
		}
	}

	void _quick(int *Vector, int low, int high) {
		int i = low, j = high;
		int x = Vector[(low + high) / 2];
		do {
			while (Vector[i] < x)
				i++;
			while (Vector[j] > x)
				j--;
			if (i <= j){
				int tmp = Vector[i];
				Vector[i] = Vector[j];
				Vector[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);
		if (low < j)
			_quick(Vector, low, j);
		if (i < high)
			_quick(Vector, i, high);
	}

	void quick(int* Vector, unsigned int size) {
		_quick(Vector, 0, size - 1);
	}
	
	void _merge(int* Vector, int* Result, unsigned int iLeft, unsigned int iRight, unsigned int iEnd) {
		unsigned int i = iLeft, j = iRight;
		for (unsigned int k = iLeft; k < iEnd; k++)
			if (i < iRight && (j >= iEnd || Vector[i] <= Vector[j]))
				Result[k] = Vector[i++];
			else
				Result[k] = Vector[j++];
	}
	
	void merge(int *Vector, unsigned int size) {
		int* Result = new int[size];
		for (unsigned int width = 1; width < size; width *= 2) {
			for (unsigned int i = 0; i < size; i = i + 2 * width)
				_merge(Vector, Result, i, min(i + width, size), min(i + 2 * width, size));
			copy(Result, Result + size, stdext::checked_array_iterator<int*>(Vector, size));
		}
	}
}