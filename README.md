Algorithm
======

Practice algorithm for jobs

[heap_sort.c]
Description:
	Implement heap sort alogrithm.
Function list:
void HeapSort(int num[],int size);
void BuildHeap(int num[] ,int size);
void PercolateDown(int num[] , int index,int size);
void PrintHeap(const char* strMsg,int array[],int nLength);
void Swap(int num[] , int v, int u);

[split_2NArray.cpp]
Description:
	Implement alogrithm for split 2N-array into two N-array. And each sum of N-array is the most closely to the half sum of 2N-array
Function list:
int calculate_sum(int * array, int length);
int min(int x, int y);
int max(int x, int y);
void print_array(int * array, int length);
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
int solution_1(int *array, int length, int half_sum);
/* *
 * Description:
 * 	To pick N+1 elements which total sum is less than SUM/2+2
 * Drawback:
 * 	This solution can't store states
 * Advantage:
 * 	This solution save lots of space
 * */
int solution_2(int *array, int length, int half_sum);
/* *
 * Description:
 * 	isOK[i][j] means if we can find i elements and this elements sum is equal to j		
 * */
int solution_3(int *array, int length, int half_sum);
