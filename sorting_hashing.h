#include "RandolUtilities.h"
#include <list>
#include <iostream>
#include <vector>
#include <stdlib.h>
#pragma once
#include <string>

using namespace std;

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

//Quick Sort Function

void qsort(vector<double>& v) {
	if (v.size() > 1) {
		int pivot = floor(v.size() / 2);
		vector<double> left;
		vector<double> right;
		right.push_back(v[pivot]);
		for (int i = 0; i<v.size(); i++) {
			if (i != pivot) {
				if (v[i]<v[pivot]) {
					left.push_back(v[i]);
				}
				else {
					right.push_back(v[i]);
				}
			}
		}
		qsort(left);
		qsort(right);
		//merge left and right into a single vector
		
		vector<double> sorted;
		sorted.reserve(left.size() + right.size());
		sorted.insert(sorted.end(), left.begin(), left.end());
		sorted.insert(sorted.end(), right.begin(), right.end());
		//
		v.swap(sorted);
	}
}



//used by qsort Function
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}



//MERGE SORT IMPLEMENTATION
// merge function
vector<double> merge(vector<double> left, vector<double> right) {
	int leftCount = 0;
	int rightCount = 0;

	vector<double> results;

	bool useLeft;
	for (int i = 0; i<left.size() + right.size(); i++) {
		if (leftCount<left.size()) {
			if (rightCount<right.size()) {
				useLeft = (left[leftCount] < right[rightCount]);
			}
			else {
				useLeft = true;
			}
		}
		else {
			useLeft = false;
		}

		if (useLeft) {
			results.push_back(left[leftCount]);
			if (leftCount < left.size()) {
				leftCount++;
			}
		}
		else {
			results.push_back(right[rightCount]);
			if (rightCount<right.size()) {
				rightCount++;
			}
		}
	}
	return results;
}

// merge sort function
vector<double> mergeSort(vector<double> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int len = floor(arr.size() / 2);
	vector<double> left(arr.begin(), arr.begin() + len);
	vector<double> right(arr.begin() + len, arr.end());

	return merge(mergeSort(left), mergeSort(right));
}


//binary search
	int BinSearch(vector<double>& vec, double numElements, double searchKey)
{
    bool found = false;
    int index;
    int searchStart = 0;
    int searchEnd = numElements - 1;

    while (!found)
    {
        index = (searchEnd + searchStart) / 2;
        if ((searchEnd - 1) == searchStart)
        {
            found = true;
            if (searchKey == vec[searchStart]) {
                index = searchStart;
            }
            else if (searchKey == vec[searchEnd]) {
                index = searchEnd;
            }
            else {
                index = -1;
            }
        }

        else if (index <= searchStart || index >= searchEnd) {
            found = true;
            index = -1;
        }
        else if (searchKey > vec[index]) {
            searchStart = index + 1;
        }
        else if (searchKey < vec[index]) {
            searchEnd = index - 1;
        }
        else if (searchKey == vec[index]) {
            found = true;
        }
    }
    return index;
}

void printVec(vector<double>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

//hashinh strings to int


unsigned int Hash_str_int(const std::string& str)
{

	unsigned int hash = 5381;
	int c;
	for(auto c : str)
	{
		hash = ((hash << 5) + hash) + c;
	}
	cout << hash << endl;
	return hash;
}
unsigned int IntToString(int num)
{
	string strg = std::to_string(num);
	unsigned int hashed = Hash_str_int(strg);
	return hashed;
}
