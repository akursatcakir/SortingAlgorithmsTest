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
			if (i <= j) {
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

	int heapLeft(int i) {
		return 2 * (i + 1) - 1;
	}

	int heapRight(int i) {
		return 2 * (i + 1);
	}

	void heapify(int *Vector, unsigned int size, unsigned int index) {
		int max;
		int left = heapLeft(index);
		int right = heapRight(index);
		if (left < size && Vector[left] > Vector[index])
			max = left;
		else max = index;
		if (right < size && Vector[right] > Vector[max])
			max = right;
		if (max != index) {
			int temp = Vector[max];
			Vector[max] = Vector[index];
			Vector[index] = temp;
			heapify(Vector, size, max);
		}
	}

	void heap(int *Vector, unsigned int size) {
		for (int i = floor(size / 2); i >= 0; i--)
			heapify(Vector, size, i);
		for (int i = size - 1; i >= 0; i--)
		{
			int temp = Vector[0];
			Vector[0] = Vector[i];
			Vector[i] = temp;
			heapify(Vector, --size, 0);
		}
	}
}