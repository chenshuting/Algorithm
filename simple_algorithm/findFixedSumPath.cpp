/*
 * =====================================================================================
 *
 *       Filename:  findFixedSumPath.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2013 04:11:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#include "BinaryTree.h"

void printPath(vector<int> path)
{
	cout << "Path:>";
	for (vector<int>::iterator iter = path.begin(); iter != path.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void findFixedSumPath(BTreeNode<int> *root, int currentSum, int sum, vector<int>& path) {
	if (root == NULL) {
		return;
	} 
	currentSum += root->value;
	if (currentSum <= sum) {
		path.push_back(root->value);
	}
	
	if (root->isLeaf() && currentSum == sum) {
		printPath(path);	
	}

	findFixedSumPath(root->left, currentSum, sum, path);
	findFixedSumPath(root->right, currentSum, sum, path);

	path.pop_back();
}

int main() {
	BTree<int> *tree = new BTree<int>();
	vector<int> path;
	int array[] = {10,12,7,5};

	tree->makeTree(array, 4);
	tree->print();
	
	findFixedSumPath(tree->getRoot(), 0, 22, path);

	return 0;
}
