/*
 * =====================================================================================
 *
 *       Filename:  verifySequeceOfBST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 11:41:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool verifySequeceOfBST(int *sequece, int start, int end)
{
	if (sequece == NULL ||start > end || start < 0 ||end < 0) {
		return false;
	}

	bool left = true, right = true;
	int i = 0, middle = 0;

	while (i < end && sequece[i] <= sequece[end]) {
		i++;
	}
	middle = i - 1;

	while (i < end  && sequece[i] > sequece[end]) {
		i++;
	}

	if (i != end) {
		return false;
	}

	if (middle > start) {
		left = verifySequeceOfBST(sequece, start, middle);
	}

	if (middle < end - 1) {
		right = verifySequeceOfBST(sequece, middle + 1, end - 1);
	}

	return (left && right);
}

int main(int argc, char *argv[])
{
	int array[] = {5,6,6,9,11,10,8};
	bool result = false;

	result = verifySequeceOfBST(array, 0, 6);

	if (result)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}
