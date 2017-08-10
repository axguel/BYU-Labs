/*
 * Tree.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: aguel
 */
#include <algorithm>
#include <iostream>
#include <string>


#include "Tree.h"

using namespace std;
//returns node
Node* Tree::getRootNode() {
	return root;
}

//removes the data from the node
bool Tree::remove(int data) {
	bool check = removeNode(root,data);
	return check;
}

//clears the tree!
void Tree::clear() {
	while (root != NULL) {
		remove(root->data);
	}
}

//returns the max amount of the tree
int Tree::getMax(Node* n) {
	if (n->right == NULL)
		return n->data;
	else
		return getMax(n->right);
}

//calls add
bool Tree::add(int data) {
	bool check = add(root, data);
	return check;
}

//adds item into the tree given the node pointer and the data
bool Tree::add(Node*& n, int data) {
	if (n == NULL) { //if it is null where they want to insert it
		n = new Node(data);
		updateHeight(root);
		balance(n);
		return true;
	}//if equal
	else if (n->data == data) {
		return false;
	} //if less than
	else if (data < n->data) {
		bool check = add(n->left, data);
		updateHeight(root);
		balance(n);
		return check;
	}//if greater than
	else if (data > n->data) {
		bool check = add(n->right, data);
		updateHeight(n);
		balance(n);
		return check;
	}
	return false;
}


//removes a node from the tree while checking different things along the way
bool Tree::removeNode(Node*& n, int data, bool balanceTree) {
	if (n == NULL) {
		return false;
	} //if it is an invalid node pointer
	else if (data < n->data) {
		bool status = removeNode(n->left, data);
		if (balanceTree) { //checks to make sure the tree is balanced
			updateHeight(root); //updates the height
			balance(n);
		}
		return status;
	}
	else if (data > n->data) {//does the check for the data if it is less than the data for the n pointer
		bool status = removeNode(n->right, data);
		if (balanceTree) { //checks to see if it is balanced
			updateHeight(root);
			balance(n);
		}
		return status;
	}
	//after those two checks, all that is left is that the two nodes are equal
	else {
		Node* nremove = n;
		//checks the children nodes
		if ((n->left == NULL) && (n->right == NULL)) {
			n = NULL;
			delete nremove;
		}
		//for one child
		else if (n->left == NULL) {
			n = n->right;
			delete nremove;
		}
		else if (n->right == NULL) {
			n = n->left;
			delete nremove;
		}
		//CTL
		else {
			int replacement = getMax(n->left);
			remove(replacement);
			replace(data,replacement);
			updateHeight(root);
			balance(n);
		}
		return true;
	}
}

//balances the right side of the tree
void Tree::balanceRight(Node*& n) {
	Node* leftNChild = n->getLeftChild()->getLeftChild();
	Node* rightNChild = n->getLeftChild()->getRightChild();
	//calls another function if it is out of balance
	if (getNodeHeight(leftNChild) < getNodeHeight(rightNChild)) {
		rotateLeft(n->left);
	}
	rotateRight(n);
}
//balances the left side of the tree
void Tree::balanceLeft(Node*& n) {
	//gets a node peinter and points it to the n's right's left child
	Node* leftNChild = n->getRightChild()->getLeftChild();
	//the inverse for the right child is here
	Node* rightNChild = n->getRightChild()->getRightChild();
	if (getNodeHeight(leftNChild) > getNodeHeight(rightNChild)) {
		rotateRight(n->right); //rotates if needed to rotate
	}
	rotateLeft(n);
}

//balances the tree as a whole
void Tree::balance(Node*& n) {
	//calls the balance right if the statement is tree
	if ((getNodeHeight(n->getLeftChild()) - getNodeHeight(n->getRightChild())) > 1) {
		balanceRight(n);
	}//calls balance left if statement is true
	else if ((getNodeHeight(n->getRightChild()) - getNodeHeight(n->getLeftChild())) > 1) {
		balanceLeft(n);
	}
}

//rotates the tree to the right given the child
void Tree::rotateRight(Node*& n) {
	Node* x = n->getLeftChild();
	n->left = x->right;
	x->right = n;
	n = x;
}
//rotates the node left with the child
void Tree::rotateLeft(Node*& n) {
	//creates a node pointer and equals it to the child
	Node* x = n->getRightChild();
	//switcharoo
	n->right = x->left;
	x->left = n;
	n = x;
}


//returns the height of the tree
int Tree::getNodeHeight(Node* n) {
	if (n == NULL)
		return -1;
	return n->getHeight();
}
//updates a height when a node is inserted
int Tree::updateHeight(Node* n) {
	if (n->getLeftChild() != NULL)
		updateHeight(n->getLeftChild());
	if (n->getRightChild() != NULL)
		updateHeight(n->getRightChild());
	n->height = max(getNodeHeight(n->getLeftChild()),getNodeHeight(n->getRightChild())) + 1;
	return n->getHeight();
}
//replaces node with one value to another
bool Tree::replace(Node*& n, int prevValue, int newValue) {
	if (n != NULL) {
		if (n->getData() < prevValue) //measures the data from the new to the old
			return replace(n->right, prevValue, newValue); //replaces the data
		else if (n->getData() > prevValue)
			return replace(n->left, prevValue, newValue);
		else {
			n->data = newValue;
			return true;
		}
	}
	return false; //if unsuccessful
}

//replaces the value
bool Tree::replace(int prevValue, int newValue) {
	bool check = false;
	check = replace(root, prevValue, newValue); //calls replace to see if it was successful or not with the values given
	return check;
}


