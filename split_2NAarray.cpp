/*
 * =====================================================================================
 *
 *       Filename:  split_2NAarray.cpp
 *
 *    Description:  To split a 2N array into two N array which the sum of each array is 
 *    the most closely to SUM/2
 *
 *        Version:  1.0
 *        Created:  08/14/2013 02:17:18 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory.h>
using namespace std;

int calculate_sum(int * array, int length)
{
	if (array == NULL || length <= 0)
		return 0;
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}

int min(int x, int y)
{
	return x > y ? y : x;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

void print_array(int * array, int length)
{
	if (array == NULL || length <= 0)
		return;
	for (int i = 0; i < length; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

/* *
 * Description:
 * 		Simulate dynamic programming to resolve this problem.
 * Time complexity:O(2^N); Spcae complexity:O(N^2 * SUM)
 * Three-dimensional defnition:
 * 		F[i][j][k]: Pick j elements from [0,i], and the sum of j 
 * 	elements is less than k and the most closely to k.
 * 	F[i][j][k] = max{F[i-1][j-1][k-a[i]], F[i-1][j][k]}
 * 	F[2N][N][SUM/2] is what we need
 * */
int solution_1(int *array, int length, int half_sum)
{
	if (array == NULL || length <= 0 || (length & 0x01))
		return 0;

	int N = length >> 1;
	int i, j , k;
	int F[length + 1][N + 1][half_sum + 2];
	
	memset(F, 0, sizeof(F));

	for (i = 1; i <= length; i++) {
		for (j = 1; j <= min(i, N); j++) {
			for (k = half_sum + 1; k >= array[i]; k--) {
				F[i][j][k] = max(F[i-1][j-1][k - array[i]] + array[i],
					F[i-1][j][k]);	
			}
		}
	}

	i = length, j = N, k = half_sum + 1;
	while (i > 0) {
		if (F[i][j][k] == F[i-1][j-1][k-array[i]] + array[i]){
			cout << array[i] << " "; //pick array[i]
			j--;
			k -= array[i];
		}
		i--;
	}
	cout << endl;

	return F[length][N][half_sum+1];
}


/* *
 * Description:
 * 	To pick N+1 elements which total sum is less than SUM/2+2
 * Drawback:
 * 	This solution can't store states
 * Advantage:
 * 	This solution save lots of space
 * */
int solution_2(int *array, int length, int half_sum)
{
	int i, j , k;
	int N = length >> 1;
	int F[N+1][half_sum+2];
	
	memset(F, 0, sizeof(F));

	for (i = 1; i <= length; i++) {
		for (j = 1; j <= min(i,N); j++) {
			for (k = half_sum+1; k >= array[i]; k--) {
				F[j][k] = max(F[j - 1][k - array[i]] + array[i],
					F[j][k]);
			}
		}
	}

	return F[N][half_sum+1];
}

/* *
 * Description:
 * 	isOK[i][j] means if we can find i elements and this elements sum is equal to j		
 * */
int solution_3(int *array, int length, int half_sum)
{
	int i, j, k;
	int N = length >> 1;
	int isOK[N + 1][half_sum + 2];

	memset(isOK, 0, sizeof(isOK));
	isOK[0][0] = 1; //0 elements's sum is 0

	for (i = 1; i <= length; i++) {
		for (j = 1; j <= min(i,N); j++) {
			for (k = half_sum + 1; k >= array[i]; k--) {
				//From big to small
				if (isOK[j-1][k - array[i]])
					isOK[j][k] = 1;
			}
		}
	}

	for (k = half_sum + 1; k >= 0; k--) {
		if(isOK[N][k])
			return k;
	}

	return 0;

}

int main(){
	cout << "Start algorithm" << endl;
	int array[] = {0,1,5,7,8,9,6,3,11,20,17}; //0 is a supplement number
	const int length = 10;
	const int sum = calculate_sum(array, length); 

	cout << "Array:> ";
	print_array(array, length);

	cout << "Sum:>" << sum << endl;

	cout << "solution_1" << endl;
	cout << solution_1(array, length, sum/2) << endl;

	cout << "solution_2" << endl;
	cout << solution_2(array, length, sum/2) << endl;

	cout << "solution_3" << endl;
	cout << solution_3(array, length, sum/2) << endl;
	return 0;
}




