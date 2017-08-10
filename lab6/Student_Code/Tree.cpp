/*
 * Tree.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: aguel
 */


#include <iostream>
#include <string>

#include "Tree.h"

using namespace std;

//returns the root of the tree
Node* Tree::getRootNode() {
	return root;
}
//adds into the tree when tree is finished
bool Tree::add(int data) {
	add(root, data);
	return true;
}
//adds a node into the tree in a certain position
bool Tree::add(Node*& n, int data) {
	//checks for validity
	if (n == NULL) {
		n = new Node(data);
		return true;
	}
	else if (n->data == data) {
		return false;
	}//correctly places it with the data
	else if (data < n->data) {
		return add(n->left, data);
	}
	else if (data > n->data) {
		return add(n->right, data);
	}
	return false;
}
//removes data from tree
bool Tree::remove(int data) {
	return remove(root,data);
}

//removes node
bool Tree::remove(Node*& n, int data) {
	//makes sure it is a valid node
	if (n == NULL) {
		return false;
	}//varifies that the data matches as well
	else if (data < n->data) {
		return remove(n->left, data);
	}
	else if (data > n->data) {
		return remove(n->right, data);
	}
	//if everything checks out it moves onto this step
	else {
		Node* toRemove = n;
		//if it has a left node
		if ((n->left == NULL) && (n->right == NULL)) {
			n = NULL;
			delete toRemove;
		}
		//if it has a single child
		else if (n->left == NULL) {
			n = n->right;
			delete toRemove;
		}
		else if (n->right == NULL) {
			n = n->left;
			delete toRemove;
		}
		//checks both children
		else {
			int replacement = getMax(n->left);
			remove(replacement);
			n->data = replacement;
		}
		return true;
	}
}
//clears out the entire tree
void Tree::clear() {
	while (root != NULL) {
		remove(root->data);
	}
}

//recursively calls the function in order to return the max value at the bottom of the tree
int Tree::getMax(Node* n) {
	if (n->right == NULL)
		return n->data;
	else
		return getMax(n->right);

}
