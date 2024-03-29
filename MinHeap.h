#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
	vector<int> pq;

public:
	MinHeap() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		if (pq.size() == 0) {
			return 0;
		}
		else {
			return pq[0];
		}
	}

	void insert(int element) {
		pq.push_back(element);
		int childIndex = pq.size() - 1;

		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;
			if (pq[parentIndex] > pq[childIndex]) {
				int temp = pq[parentIndex];
				pq[parentIndex] = pq[childIndex];
				pq[childIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		
		}
	}

	int removeMin() {
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();
		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

		while (leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if (rightChildIndex < pq.size() && (pq[parentIndex] > pq[leftChildIndex] || pq[parentIndex] > pq[rightChildIndex])) {
				if (pq[leftChildIndex] < pq[rightChildIndex]) {
					minIndex = leftChildIndex;
				}
				else {
					minIndex = rightChildIndex;
				}
			}
			
			if (minIndex == parentIndex) {
				break;
			}
			int temp = pq[parentIndex];
			pq[parentIndex] = pq[minIndex];
			pq[minIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}
		return ans;
	}
		
};

