#include "efficient_merge_sort.hpp"
using namespace efficient_merge;

void efficient_merge::mergeSort(int A[], int const length){
	int *B = new int[length];
	copyArray(A, B, 0, length);

	split(A, B, 0, length);

	delete[] B;
}

void efficient_merge::split(int B[], int A[], int const start, int const end){
	if(end - start <= 1)
		return;

	int middle = (end + start) / 2;
	split(A, B, start, middle);
	split(A, B, middle, end);

	merge(B, A, start, middle, end);
}

void efficient_merge::merge(int B[], int A[], int start, int middle, int end){
	int leftArIndex = start, rightArIndex = middle;

	for(auto i = start; i < end; i++){
		if(leftArIndex < middle && (rightArIndex >= end || A[leftArIndex] <= A[rightArIndex]))
			B[i] = A[leftArIndex++];
		else
			B[i] = A[rightArIndex++];
	}
}

void efficient_merge::copyArray(int A[], int B[], int const start, int const end){
	for(auto i = start; i < end; i++){
		B[i] = A[i];
	}
}