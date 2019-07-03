#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"
#include "BinaryTreeNode.h"
using namespace std;

int main() {
	MinHeap h;
	MaxHeap m;

	h.insert(10);
	h.insert(20);
	h.insert(30);
	h.insert(40);
	h.insert(50);
	h.insert(60);

	m.insert(100);
	m.insert(90);
	m.insert(80);
	m.insert(70);
	m.insert(60);

	cout << m.getMax() << endl;
	cout << "Descending using max heaps" << endl;
	while (m.getSize() != 0) {
		cout << m.removeMax() << " ";
	}
	cout << endl;

	cout << h.getSize() << endl;
	cout << h.getMin() << endl;

	cout << "Ascending using min heaps" << endl;
	while (h.getSize() != 0) {
		cout << h.removeMin() << " ";
	}

	BinaryTreeNode bTree;
	cout << endl;
	cout << "Press -1 where you dont want empty node" << endl;
	bTree.insert();
	
	bTree.isHeap();
}