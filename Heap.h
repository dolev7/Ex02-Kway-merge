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

		//find related notes
		const int Parent(int node)const;
		const int Left(int node)const;
		const int Right(int node)const;

		void floydBuild();

	public:
		// ctors/dtors
		Heap(Node* unsortedArray, int size) ;
		~Heap();

		//getters
		Node min()const { return nodes[0]; }
		const int getsize()const { return size; }

		void MinFixHeap(int i);
		void Insert(Node toinsert); // not in actual use because the only need of the algorithem is always to *replace* the minimum
		bool isEmpty()const;
		void makeEmpty();
		void replaceMin(Node x);
		void Swap(Node& a, Node& b);
	};
}
