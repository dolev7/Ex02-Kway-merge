#include "ArrayToSort.h"

namespace KWaySort
{
    ArrayToSort::ArrayToSort(int n, int k, int* array)
	{
        this->_arrayToSort = new int[n];
		_size = n; 
        _k = k;

        for (int i = 0; i < _size; i++)
        {
            _arrayToSort[i] = array[i];
        }
	}
    
    void swap(double& num1, double& num2)
    {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }
    void ArrayToSort::bubbleSort(double arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)

            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
}