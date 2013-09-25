/*
 * =====================================================================================
 *
 *       Filename:  printTreeByLevel.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 07:27:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <deque>
#include "BinaryTree.h"
using namespace std;

void printTreeByLevel(BTreeNode<int> *root)
{
	if (root == NULL) {
		return;
	}

	deque<BTreeNode<int> *> dequeTreeNode;

	dequeTreeNode.push_back(root);

	while (dequeTreeNode.size()) {
		BTreeNode<int> *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		cout << pNode->value << " ";

		if (pNode->left)
			dequeTreeNode.push_back(pNode->left);

		if (pNode->right)
			dequeTreeNode.push_back(pNode->right);
	
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	BTree<int> *tree = new BTree<int>();	
	tree->makeTree(10);
	tree->print();
	
	printTreeByLevel(tree->getRoot());

	return 0;
}

