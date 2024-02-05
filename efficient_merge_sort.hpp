#ifndef efficient_merge_sort_H
#define efficient_merge_sort_H

namespace efficient_merge{
	void mergeSort(int A[], int const length);
	void split(int A[], int B[], int const start, int const end);
	void merge(int A[], int B[], int start, int middle, int end);
	void copyArray(int A[], int B[], int const start, int const end);
}

#endif