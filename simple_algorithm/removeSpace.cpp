/*
 * =====================================================================================
 *
 *       Filename:  removeSpace.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2013 01:28:02 AM
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
enum stringState{startStr, endStr, changeLineStart, changeLineEnd, normalChar};

void removeSpace(char *str)
{
	if (str == NULL || *str == '\0') {
		return;
	}

	int state = startStr; 
	int index = -1;
	bool hasSpace = false;
	char *pos = str;

	while (*pos != '\0') {
		hasSpace = false;
		while (*pos == ' ') {
			pos++;
			hasSpace = true;
		}

		if (*pos == '\n') {
			state = changeLineStart;
		} else if (pos == '\0') {
			state = endStr;
		} else {
			if (state != startStr && state != changeLineEnd) {
				state = normalChar;
			}
		}

		switch(state) {
		case startStr:
			state = normalChar;
			break;
		case endStr:
		case changeLineEnd:
			state = normalChar;
			break;
		case normalChar:
			if (hasSpace)
				str[++index] = ' ';
			break;
		case changeLineStart:
			state = changeLineEnd;
			break;
		default:
			break;
		}
		str[++index] = *pos;
		pos++;
	}
	str[++index] = '\0';
}

int main() {
	char test[] = "   abc  \n  haha";
	cout << "Before remove:" << test << endl;

	removeSpace(test);

	cout << "After remove:" << test << endl;

	return 0;
}
