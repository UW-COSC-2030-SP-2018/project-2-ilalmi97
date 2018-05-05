#include "sorting_hashing.h"
#include "RandolUtilities.h"
#include <iostream>
#include <vector>
#include<algorithm> //  to use for testing
using std::sort;
using namespace::std;
using std::vector;


int main()
{
	//quick sort funtion test
	vector<double> vec =  getNums(80, 1, 500);
		vector<double> testing_vec = vec;
		qsort(vec);
		sort(testing_vec.begin(), testing_vec.end());

		if (vec == testing_vec)
		{
			cout << "the quick Sort function is successful " << endl;

		}
		else
		{
			cout << "quick Sort function  did not match test vector" << endl;

		}

		// BINARY SEARCH TEST


		vec = getNums(80, 1, 500);
		qsort(vec);
		double right = vec.size();
		cout << "Before the binary search: " << endl;
		printVec(vec);
		cout << endl;
		double search;
		cout << "Enter the value you want to search: ";
		cin >> search;
		BinSearch(vec,right,search);
		cout << endl;

		// MERGE SORT TEST

		vec = getNums(80, 1, 500);
		vector<double>testVector = vec;
		vec = mergeSort(vec);
		sort(testVector.begin(), testVector.end());
		if (vec == testVector)
		{
			cout << "the mergesort function was successful" << endl;
			printVec(vec);
		}
		else
		{
			cout << "Mergesort did not match test vector... Fail!" << endl;
			printVec(vec);
		}
		cout << endl;

	// HASHING TESTS
	cout << "Hash a String to Int"<<endl;
	cout<<"Hello World this is JUST random talk to test for  of the string hashing funtion and this is over eighty characters for the test and it actually working youpiii" << endl;
	string str = " this is a test of the string hashing function and it is over eighty characters for the test and it actually working ";
	cout << endl;
	cout << "After the Hash: " << endl;
	Hash_str_int(str);
	cout << endl;
	unsigned int num = 800;
	cout << "Hash an Int to Int" << endl;
	cout<<"800"<<endl;
	cout << "After the Hash: " << endl;
   IntToString(num);
	cout << endl;
}
