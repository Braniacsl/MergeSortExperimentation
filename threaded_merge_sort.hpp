#ifndef threaded_merge_sort_H
#define threaded_merge_sort_H

namespace threaded_merge{
	void mergeSort(int A[], int length);
	void split(int B[], int A[], int const start, int const end, int const numThreads);
}
#endif