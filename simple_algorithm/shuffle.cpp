/*
 * =====================================================================================
 *
 *       Filename:  shuffle.cpp
 *
 *    Description:  shuffle
 *
 *        Version:  1.0
 *        Created:  2013/09/26 09时54分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int plate_num = 54;
enum king{small=53, big};
enum special{J,Q,K};
string special_values[] = {"J", "Q", "K"};
string shapes[] = {"heart", "diamond", "wintersweet", "spade"};
string king_values[] = {"[small king]", "[big king]"};

void print_plates(int plates[])
{
	cout << "Print plates:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	for (int i = 0; i < plate_num; i++) {
		int shape_value = plates[i] / 14;
		int pos = plates[i] % 13;

		if (plates[i] == small) {
			cout << king_values[0] << " ";
		} else if (plates[i] == big) {
			cout << king_values[1] << " ";
		} else if (pos == 1) {
			cout << shapes[shape_value] << "[A] ";  
		} else if (pos == 0){
			cout << shapes[shape_value] << "[K] ";  
		} else if (pos == 11) {
			cout << shapes[shape_value] << "[J] ";  
		} else if (pos == 12) { 
			cout << shapes[shape_value] << "[Q] ";  
		} else {
			cout << shapes[shape_value] << "[" << pos  << "] ";
		}
	}
	cout << endl;
}

int main()
{
	int plates[plate_num] = {0};

	/* initialization  */
	for (int i = 1; i <= plate_num; i++) {
		plates[i - 1] = i;
	}
	print_plates(plates);

	/* shuffle procedure  */
	srand((unsigned) time(0));
	for (int i = 0; i < plate_num; i++) {
		int pos = rand()%plate_num;
		int tmp = plates[i];
		plates[i] = plates[pos];
		plates[pos] = tmp;
	}

	print_plates(plates);
}
