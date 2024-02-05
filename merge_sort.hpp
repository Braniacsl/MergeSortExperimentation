#ifndef simple_merge_sort_H
#define simple_merge_sort_h

namespace simple_merge {
	void mergeSort(int A[], int const length);

	void split(int A[], int const start, int const end);

	void copyArray(int A[], int B[], int const start, int const end);

	void merge(int A[], int const start, int const middle, int const end);

	void printArray(int A[], int const length);
}
#endif