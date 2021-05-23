#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

static const int  PIVOT = 0;

namespace KWaySort
{
	class ArrayToSort
	{
	private:
		int _size;
		int _k;
		int* _arrayToSort;
		int** _heapPointers;
	public:
		//ctors and dtors
		ArrayToSort(int n, int k, int* array);
		~ArrayToSort() { delete[]_arrayToSort;}

		//getters
		int getSize() const { return _size; }
		int* getArray() const { return _arrayToSort; }

		void KWaySort();
		void KWaySortRec(int* _arrayToSort, int  n, int k);
		void HeapKWaySort();

		void QuickSort(int* _arrayToSort, int left, int right);
		int Partition(int* array, int left, int right);
	};
}