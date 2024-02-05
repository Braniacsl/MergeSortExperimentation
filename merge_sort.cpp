#include <iostream>
#include "merge_sort.hpp"
using namespace std;
using namespace simple_merge;

void simple_merge::mergeSort(int A[], int const length){
	split(A, 0, length - 1);
}

void simple_merge::split(int A[], int const start, int const end){
	if(start >= end)
		return;

	int middle = (end + start) / 2;

	split(A, start, middle);
	split(A, middle + 1, end);

	merge(A, start, middle, end);
}

void simple_merge::merge(int A[], int const start, int const middle, int const end){
	int const leftArSize = middle - start + 1;
	int const rightArSize = end - middle;

	auto *leftAr = new int[leftArSize], *rightAr = new int[rightArSize];

	copyArray(A, leftAr, start, middle);
	copyArray(A, rightAr, middle + 1, end);

	int leftArIndex = 0, rightArIndex = 0, mergeIndex = start;
	while(leftArIndex < leftArSize && rightArIndex < rightArSize){
		if(leftAr[leftArIndex] <= rightAr[rightArIndex])
			A[mergeIndex++] = leftAr[leftArIndex++];
		else
			A[mergeIndex++] = rightAr[rightArIndex++];
	}

	while(leftArIndex < leftArSize)
		A[mergeIndex++] = leftAr[leftArIndex++];

	while(rightArIndex < rightArSize)
		A[mergeIndex++] = rightAr[rightArIndex++];

	delete[] leftAr;
	delete[] rightAr;
}

void simple_merge::copyArray(int A[], int B[], int const start, int const end){
	for(auto i = 0; i < end - start + 1; i++)
		B[i] = A[start + i];
}

void simple_merge::printArray(int A[], int const length){
	for(auto i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}