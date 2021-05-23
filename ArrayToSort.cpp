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
    
    void ArrayToSort::KWaySort()
    {
        KWaySortRec(_arrayToSort, _size, _k);
    }

    void ArrayToSort::KWaySortRec(int* _arrayToSort, int  n, int k)
    {
        if (n < k)
        {
            QuickSort(_arrayToSort, 0, n);
        }
    }

    void ArrayToSort::QuickSort(int* _arrayToSort, int left, int right)
    {
        if (left < right)
        {
            int pivot = Partition(_arrayToSort, left, right);
            QuickSort(_arrayToSort, left, pivot - 1);
            QuickSort(_arrayToSort, pivot + 1, right);
        }
    }

    int ArrayToSort::Partition(int* array, int left, int right)
    {
        int pivot = array[right];
        int i = (left - 1);
        for (int j = left; j < right; j++)
        {
            if (array[j] <= pivot)
            {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[right]);
        return i + 1;
    }

    void swap(int& num1, int& num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

}