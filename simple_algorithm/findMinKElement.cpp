/*
 * =====================================================================================
 *
 *       Filename:  findMinKElement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 11:11:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef multiset<int, greater<int> > MaxIntHeap;

void findMinKElement(vector<int> &data, MaxIntHeap& leastNumbers, 
	unsigned int k)
{
	if (data.size() <= 0 || k <= 0) {
		cout << "Error input" << endl;
		return;
	}
	leastNumbers.clear();

	for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++) {
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*iter);
		} else {
			MaxIntHeap::iterator iterFirst = leastNumbers.begin();

			if (*iter < *iterFirst) {
				leastNumbers.erase(iterFirst);
				leastNumbers.insert(*iter);
			}
		}
	}
}


int main(int argc, char *argv[])
{
	vector<int> data;
	MaxIntHeap leastNumbers;

	data.push_back(100);
	data.push_back(12);
	data.push_back(42);
	data.push_back(13);
	data.push_back(25);
	data.push_back(62);
	data.push_back(18);
	data.push_back(31);
	data.push_back(27);
	data.push_back(2);

	cout << "Numbers:";
	for (vector<int>::iterator iter = data.begin();
		iter != data.end(); iter++) {
		cout << *iter << " ";	
	}
	cout << endl;

	findMinKElement(data, leastNumbers, 5);

	cout << "Least Numbers:";
	for (MaxIntHeap::iterator iter = leastNumbers.begin();
		iter != leastNumbers.end(); iter++) {
		cout << *iter << " ";	
	}
	cout << endl;

	return 0;
}
