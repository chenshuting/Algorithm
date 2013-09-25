/*
 * =====================================================================================
 *
 *       Filename:  findTwoMissingNums.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2013 03:35:23 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <math.h>
using namespace std;
#define ARRAY_LEN 10000

bool findTwoMissingNums(int *array, int length, int& missX, int& missY)
{
	int sumTotal = 0, sum = 0;
	long long squareSumTotal = 0, squareSum = 0;
	int current = 0;
	int currentValue = length;
	int squareX = 0, squareY = 0;
	
	if (array == NULL || length <=0) {
		return false;
	}

	for (int i = 0; i < length-2; i++, currentValue--) {
		sumTotal += currentValue;
		squareSumTotal += pow(currentValue,2);
		sum += array[i];
		squareSum += pow(array[i], 2);
	}
	while (currentValue != 0) {
		sumTotal += currentValue;
		squareSumTotal += pow(currentValue,2);
		currentValue--;
	}

	int diffSum = sumTotal - sum;
	int diffSqureSum = squareSumTotal - squareSum;
	int a = 2, b = -2 * diffSum, c = pow(diffSum,2) - diffSqureSum;

	return true;
}

int main()
{
	int x = 3, y = 4;
	int array[ARRAY_LEN] = {0};
	int i = 0, pos = 0;
	int missX = 0, missY = 0;
	for (i = 1; i <= ARRAY_LEN; i++) {
		if (i == x || i == y ) {
			continue;
		}
		array[pos++] = i;
	}

	findTwoMissingNums(array, ARRAY_LEN, missX, missY);

	return 0;
}
