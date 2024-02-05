#include <thread>
#include <mutex>

#include "threaded_merge_sort.hpp"
#include "efficient_merge_sort.hpp"

using namespace std;
using namespace threaded_merge;

mutex mergeMutex;

void threaded_merge::mergeSort(int A[], int length){
	int *B = new int[length];
	efficient_merge::copyArray(A, B, 0, length);

	split(A, B, 0, length, thread::hardware_concurrency());

	delete[] B;
}

void threaded_merge::split(int B[], int A[], int const start, int const end, int const numThreads){
	if(end - start <= 1)
		return;

	if(numThreads == 1 || end - start <= 1000){
		efficient_merge::mergeSort(B, end - start);
		return;
	}

	int middle = (end + start) / 2;

	thread leftThread{split, A, B, start, middle, numThreads / 2};

	split(A, B, middle, end, numThreads - numThreads / 2);

	leftThread.join();

	lock_guard<mutex> lock{mergeMutex};

	efficient_merge::merge(A, B, start, middle, end);
}