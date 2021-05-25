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
			fixHeap(i);
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
		while (i > 0 && nodes[Parent(i)].priority > toinsert.priority)
		{
			nodes[i] = nodes[Parent(i)];
			i = Parent(i);
		}
		nodes[i] = toinsert;
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
	void Heap::fixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		if (left < size && (nodes[left].priority < nodes[node].priority))
		{
			min = left;
		}
		else
		{
			min = node;
		}

		if (right < size)
		{
			if (nodes[right].priority < nodes[min].priority)
				min = right;
		}
		if (min != node)
		{
			Swap(nodes[node], nodes[min]);
			fixHeap(min);
		}
	}



	void Heap::Swap(Node& a, Node& b)
	{
		Node temp = a;
		a = b;
		b = temp;
	}

}