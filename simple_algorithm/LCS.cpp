/*
 * =====================================================================================
 *
 *       Filename:  LCS.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 10:47:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_LENGTH 10

void LCSLength(char *seq1, char *seq2, int m, int n,
	int c[][MAX_LENGTH], int b[][MAX_LENGTH])
{
	if (seq1 == NULL || seq2 == NULL || m <= 0 || n <= 0) {
		cout << "Error input!" << endl;
		return;
	}
	//Initialize arrays
	for (int i = 0; i <= m; i++) {
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		c[0][j] = 0;
	}
	
	for (int i = 1; i <=m; ++i ) {
		for (int j = 1; j <=n; ++j) {
			if (seq1[i-1] == seq2[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 0;
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 1;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
}

void printLCS(int b[][MAX_LENGTH], char *seq, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	
	if (b[i][j] == 0) {
		printLCS(b, seq, i-1, j-1);
		cout << seq[i-1];
	} else if (b[i][j] == 1){
		printLCS(b, seq, i-1, j);
	} else {
		printLCS(b, seq, i, j-1);
	}
}

int main() {
	char x[MAX_LENGTH] = {"ABCBDAB"};
	char y[MAX_LENGTH] = {"BDCABA"};
	int b[MAX_LENGTH][MAX_LENGTH];
	int c[MAX_LENGTH][MAX_LENGTH];
	int m,n;
	
	m = strlen(x);
	n = strlen(y);
	cout << "seq1:" << x << endl;
	cout << "seq2:" << y << endl;

	LCSLength(x, y, m, n, c, b);
	cout << "LCS:";
	printLCS(b, x, m, n);
	cout << endl;

	return 0;
}
