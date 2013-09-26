/*
 * =====================================================================================
 *
 *       Filename:  findUniqueThree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2013 11:18:22 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int lastBitOf1(int num)
{
	//return num & ~(num - 1);
	return num ^ (num & (num-1));	
}

void getTwoUnique(vector<int>::iterator begin, 
	vector<int>::iterator end, vector<int>& unique)
{
	int xorResult = 0;

	for (vector<int>::iterator iter = begin; iter != end; iter++) {
		xorResult ^= *iter;
	}
	int diff = lastBitOf1(xorResult);
	int first = 0;
	int second = 0;

	for (vector<int>::iterator iter = begin; iter != end; iter++) {
		if (diff & *iter) {
			first ^= *iter;
		} else {
			second ^= *iter;
		}
	}

	unique.push_back(first);
	unique.push_back(second);
}

void findUniqueThree(vector<int>& numbers, vector<int>& unique)
{
	if(numbers.size() < 3)
		return;
	
	//get XOR result
	int xorResult = 0;
	vector<int>::iterator iter = numbers.begin();
	for (; iter != numbers.end(); iter++) {
		xorResult ^= *iter;
	}

	//get last bif of 1 from three unique numbers
	int flags = 0;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		flags ^= lastBitOf1(xorResult ^ *iter);
	}
	flags = lastBitOf1(flags);

	//get first unique number
	int first = 0;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		if (lastBitOf1(flags ^ *iter) == flags) {
			first ^= *iter;
		}
	}
	unique.push_back(first);

	//move the first number to the last position of vector
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		if (*iter == first ) {
			swap(*iter, *(numbers.end() - 1));
			break;
		}
	}

	//get last two unique numbers
	getTwoUnique(numbers.begin(), numbers.end()-1, unique);
}

int main() 
{
	vector<int> numbers;
	vector<int> unique;

//	numbers.push_back(1);
//	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	cout << "vector number:>";
	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << *iter << " " ;	
	}
	cout << endl;

	findUniqueThree(numbers, unique);

	cout << "unique numbers:>";
	for (vector<int>::iterator iter = unique.begin(); iter != unique.end(); iter++) {
		cout << *iter << " " ;	
	}
	cout << endl;

	return 0;
}
