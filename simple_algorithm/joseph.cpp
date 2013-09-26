/*
 * =====================================================================================
 *
 *       Filename:  joseph.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 09:58:39 AM
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

int main(int argc, char *argv[])
{
	int winner = 0;
	int n = 0, m = 0;
	
	do{
		cout << "Input n and m:>";
		cin >> n >> m;
		cout << endl;
	}while (n <= 0 || m <= 0);

	for (int i = 2; i <= n; i++) {
		winner = (winner+m) % n;
	}
	
	cout << "Winner" << winner << endl;

	return 0;
}
