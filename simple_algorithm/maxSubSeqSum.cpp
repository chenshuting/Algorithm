/*
 * =====================================================================================
 *
 *       Filename:  maxSubSeqSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2013 03:26:02 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool findMaxSum(int *array, int length, int &maxSum) 
{
	int maxNegtive = 0;
	int negtiveCnt = 0;
	int currentSum = 0;
	int i = 0;

	if (array == NULL || length <= 0) {
		return false;
	}
	
	for (i = 0; i < length; i++) {
		if (array[i] < 0) {
			negtiveCnt++;
			if (maxNegtive == 0) {
				maxNegtive = array[i];
			} else if (maxNegtive < array[i]) {
				maxNegtive = array[i];
			}
		}

		currentSum += array[i];
		if (currentSum < 0) {
			currentSum = 0;
		}
		if (currentSum > maxSum) {
			maxSum = currentSum;
		}
	}

	if (negtiveCnt == length) {
		maxSum = maxNegtive;
	}
	return true;
}

int main() {
	int maxSum = 0;
	int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = 8;

	findMaxSum(array, length, maxSum);

	cout << "MaxSum:> " << maxSum << endl;

	return 0;
}
