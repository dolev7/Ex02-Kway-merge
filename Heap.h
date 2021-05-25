#pragma once
#include <iostream>
using namespace std;

namespace KWaySort
{

	struct Node
	{
		int data;
		int array_index;
		int item_index;
	};

	class Heap
	{
		
	private:
		Node* nodes;
		int size;
		int maxSize;
		bool allocated;
		const int Parent(int node)const;
		const int Left(int node)const;
		const int Right(int node)const;
		void floydBuild();

	public:
		void fixHeap(int node);
		void replaceMin(Node x) { nodes[0] = x;  MinHeapify(0); }
		Heap(Node* unsortedArray, int size) ;
		~Heap();
		Node deleteMin() {
			if (size < 1)
			{
				cout << "invalid input";
				exit(1);
			}
		Node min = nodes[0];
			size--;
			nodes[0] = nodes[size];
			fixHeap(0);
			return min;
		};
		void MinHeapify(int i)
		{
			int l = Left(i);
			int r = Right(i);
			int smallest = i;
			if (l < size && nodes[l].data < nodes[i].data)
				smallest = l;
			if (r < size && nodes[r].data < nodes[smallest].data)
				smallest = r;
			if (smallest != i)
			{
				Swap(nodes[i], nodes[smallest]);
				MinHeapify(smallest);
			}
		}
		Node min()const { return nodes[0]; }
		const int getsize()const { return size; }
		void Insert(Node toinsert);
		bool isEmpty()const;
		void makeEmpty();
		void Swap(Node& a, Node& b);
	};
}
