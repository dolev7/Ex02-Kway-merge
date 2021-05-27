#include "Heap.h"
using namespace std;

namespace KWaySort
{
	Heap::Heap(Node* unsortedArray, int size)
	{
		allocated = false;
		maxSize = this->size = size;
		nodes = unsortedArray;
		this->size = size;
		floydBuild();
	}

	Heap::~Heap()
	{
		makeEmpty();
	}
	void Heap::makeEmpty()
	{
		if (allocated)
		{
			delete[] nodes;
		}
		nodes = nullptr;
		size = 0;
	}
	bool Heap::isEmpty()const
	{
		if (size == 0)
			return true;
		else return false;
	}
	void  Heap::floydBuild()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			MinFixHeap(i);
	}

	void Heap::Insert(Node toinsert)
	{
		string errorName;
		if (size == maxSize)
		{
			throw (errorName = "size==maxSize");
		}
		int i = size;
		size++;
		while (i > 0 && nodes[Parent(i)].data > toinsert.data)
		{
			nodes[i] = nodes[Parent(i)];
			i = Parent(i);
		}
		nodes[i] = toinsert;
	}
	
	void Heap::replaceMin(Node x)
	{
		nodes[0] = x;  MinFixHeap(0); 
	}

	const int Heap::Parent(int node)const
	{
		return (node - 1) / 2;
	}

	const int Heap::Left(int node)const
	{
		return (2 * node) + 1;
	}

	const int Heap::Right(int node)const
	{
		return (2 * node) + 2;
	}

	void Heap::MinFixHeap(int i)
	{
		int left = Left(i);
		int right = Right(i);
		int smallest = i;
		if (left < size && nodes[left].data < nodes[i].data)
			smallest = left;
		if (right < size && nodes[right].data < nodes[smallest].data)
			smallest = right;
		if (smallest != i)
		{
			Swap(nodes[i], nodes[smallest]);
			MinFixHeap(smallest);
		}
	}

	void Heap::Swap(Node& a, Node& b)
	{
		Node temp = a;
		a = b;
		b = temp;
	}
}