#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <cstring>

#include "merge_sort.hpp"
#include "efficient_merge_sort.hpp"
#include "threaded_merge_sort.hpp"

using namespace std;

int *generateArray(const int size){
	int *ar = new int[size];

	random_device rd;
	mt19937 gen{rd()};

	uniform_int_distribution<int> distribution{1, 10000};

	for(auto i = 0; i < size; i++){
		ar[i] = distribution(gen);
	}

	return ar;
}

int main(int argc, char *argv[]){
	int ar_size = 1000000; //default size

	if(argc == 3 && strcmp(argv[1], "-s") == 0){
		try{
			ar_size = stoi(argv[2]);
		}
		catch(const invalid_argument &e){
			cerr << "Invalid argument exception: " << e.what() << endl;
			return -1;
		}
		catch(const out_of_range &e){
			cerr << "Out of range exception: " << e.what() << endl;
			return -1;
		} 
	}
	else if(argc > 3 || argc == 2){
		cerr << "Invalid number of arguments.\nRun the program with no arguments or if you want to"
			 << " specify the size of the array then do '-s' followed by the size." << endl;
		return -1;
	}


	int *ar1 = generateArray(ar_size);

	int *ar2 = new int[ar_size];

	int *ar3 = new int[ar_size];

	//This is done to ensure that values are the same 
	//and thus so there won't be any discrepancies in data.
	//Like it would be minimal but 1234 is gonna take up more 
	//space than 12, so yknow.
	efficient_merge::copyArray(ar1, ar2, 0, ar_size);
	efficient_merge::copyArray(ar1, ar3, 0, ar_size);

	auto startTime = chrono::high_resolution_clock::now();
	simple_merge::mergeSort(ar1, ar_size);
	auto endTime = chrono::high_resolution_clock::now();
	const auto simpleDuration = chrono::duration_cast<chrono::microseconds>(endTime-startTime);

	startTime = chrono::high_resolution_clock::now();
	efficient_merge::mergeSort(ar2, ar_size);
	endTime = chrono::high_resolution_clock::now();
	const auto efficientDuration = chrono::duration_cast<chrono::microseconds>(endTime-startTime);

	startTime = chrono::high_resolution_clock::now();
	threaded_merge::mergeSort(ar3, ar_size);
	endTime = chrono::high_resolution_clock::now();
	const auto threadedDuration = chrono::duration_cast<chrono::microseconds>(endTime-startTime);

	cout << "The simple sorted array took " << simpleDuration.count() << " microseconds." << endl;
	cout << "The efficiently sorted array took " << efficientDuration.count() << " microseconds." << endl;
	cout << "The threaded sorted array took " << threadedDuration.count() << " microseconds." << endl;

	delete[] ar1;
	delete[] ar2;
	delete[] ar3;

	return 0;
}