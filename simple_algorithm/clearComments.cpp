/*
 * =====================================================================================
 *
 *       Filename:  clearComments.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 08:45:34 PM
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
#include <fstream>
using namespace std;

#define PATH_LENGTH 100
#define BUFFER_LENGTH 512 
#define LINE_LENGTH 128

int _clearComments(char *buffer, int size, bool& singleFlag, bool& multiFlag)
{
	int current = 0, start = 0, length = 0;
	int ret = size;

	while (current < size) {
		switch(buffer[current]) {
		case '/':
			if (!multiFlag && !singleFlag) {
				//not set any flags
				current++;
				if (current >= size) {
					break;
				}
				length++;
				if (buffer[current] == '*') {
					multiFlag = true;
					start = current - 1;
					length = 2;
				} else if (buffer[current] == '/') {
					singleFlag = true;
					start = current - 1;
					length = 2;
				}
			}
			break;
		case '*':
			if (multiFlag) {
				current++;
				if (current >= size) {
					break;
				}
				length++;

				if (buffer[current] == '/') {
					memset(buffer+start, ' ', length);
					length = 0;
					multiFlag = false;
				}
			}
			break;
		case '\n':
			if (singleFlag) {
				memset(buffer+start, ' ', length);
				length = 0;
				singleFlag = false;
			}
			break;
		default:
			break;
		}
		current++;
		length++;
	}

	if (singleFlag || multiFlag) {
		singleFlag = false;
		multiFlag = false;
		memset(buffer+start, ' ', length);
		ret = size - length;
	}

	return ret;
}

void clearComments(ifstream& fileIn, ofstream& fileOut)
{
	char buffer[BUFFER_LENGTH];
	bool singleFlag = false, multiFlag = false;
	int buf_size = 0, writeChars = 0;
	int file_length = 0;
	int count = 0;

	//get length of the file 
	fileIn.seekg(0, ios::end);	
	file_length = fileIn.tellg();
	fileIn.seekg(0, ios::beg);	

	while (file_length > 0) {
		fileIn.read(buffer, BUFFER_LENGTH);	
		buf_size = strlen(buffer);
		writeChars = _clearComments(buffer, buf_size, singleFlag, multiFlag);	
		fileOut.write(buffer, writeChars);
		memset(buffer, '\0', BUFFER_LENGTH);
		file_length -= buf_size;
	}
}


int main (int argc, char *argv[]) {

	int ret = 0;
	char fileInPath[PATH_LENGTH], fileOutPath[PATH_LENGTH];
	int path_len = 0;

	cout << "File path:>";
	cin >> fileInPath;

	ifstream fileIn(fileInPath);
	if (!fileIn) {
		cout << "Open file to read failed!" << endl;
		return 0;
	}
	
	snprintf(fileOutPath, PATH_LENGTH,"%s_%s", fileInPath, "bkp");
	ofstream fileOut(fileOutPath);
	if (!fileOut) {
		cout << "Open file to write failed!" << endl;
		fileIn.close();
		return 0;
	}

	clearComments(fileIn, fileOut);	
	fileOut << flush;
	fileOut.close();

	ret = rename(fileOutPath,fileInPath);

	return 0;
}
