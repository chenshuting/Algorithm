/*
 * =====================================================================================
 *
 *       Filename:  BinaryTree.cpp
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

template <typename T> class BTreeNode{
public:
	BTreeNode(int new_value) {
		value = new_value;
		left = NULL;
		right = NULL;
	}

	BTreeNode(void) {
		value = 0;
		left = NULL;
		right = NULL;
	}
	~BTreeNode(void) {
	
	}

	bool isLeaf(void) {
		if (left == NULL && right == NULL) {
			return true;
		} else {
			return false;
		}
	}

	T value;
	BTreeNode<T> *left;
	BTreeNode<T> *right;
};

template <typename T> class BTree{
public:
	BTree(void) {
		root = NULL;
		nodeCnt = 0;
		
	}

	virtual ~BTree(void){
	
	}
	
	void insert(BTreeNode<T> *newNode) {
		if (root == NULL) {
			root = newNode;
			return;
		}
		BTreeNode<T> *pos = root;
		int level = 0;
		while(pos != NULL) {
			level++;
			if (pos->value < newNode->value) {
				if (pos->right == NULL) {
					pos->right = newNode;
					break;
				}
				pos = pos->right;
			} else {
				if (pos->left == NULL) {
					pos->left = newNode;
					break;
				}
				pos = pos->left;
			}
		}
	}

	void makeTree(int numberOfNodes) {
		if (numberOfNodes <= 0) {
			return;
		}

		srand((unsigned)time(NULL));
		while (numberOfNodes-- > 0) {
			int value = random()%100;
			BTreeNode<int> *node = new BTreeNode<int>(value);
			insert(node);
		}
	}

	void makeTree(T array[], int length) {
		if (array == NULL || length <= 0) {
			return;
		}

		for (int i = 0; i < length; i++) {
			BTreeNode<T> *node = new BTreeNode<T>(array[i]);
			insert(node);
		}
	
	}

	void _printInorder(BTreeNode<int> *node) {
		if (node == NULL)
			return;

		_printInorder(node->left);
		cout << " " << node->value;
		_printInorder(node->right);
	}
	void print() {
		cout << "Print tree:";
		_printInorder(root);	
		cout << endl;
	}

	BTreeNode<T> *getRoot(){
		return root;
	}

private:
	BTreeNode<T> *root;
	int nodeCnt;
};
