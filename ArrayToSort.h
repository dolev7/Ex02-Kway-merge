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
	public:
		//ctors and dtors
		ArrayToSort(int n, int k, int* array);
		~ArrayToSort() { delete[]_arrayToSort;}

		//getters
		int getSize() const { return _size; }
		int* getArray() const { return _arrayToSort; }

		void bubbleSort(double arr[], int n);
	};
}