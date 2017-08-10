/*
 * Tree.h
 *
 *  Created on: Apr 6, 2016
 *      Author: aguel
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <string>

#include "Node.h"
#include "AVLInterface.h"


class Tree : public AVLInterface {
private:
	Node* root;

	//adds a node given the node pointer and the data to be inserted
	bool add(Node*& n, int data);

	//removes the node and checks if the tree is balanced
	bool removeNode(Node*& n, int data, bool balanceTree = true);

	//replaces a node given a pointer
	bool replace(Node*& n, int prevValue, int newValue);

	//replaces a node given just the values
	bool replace(int prevValue, int newValue);
public:
	Tree() : root(NULL) {};
	~Tree(){ clear(); }

//gets the rootnode
	Node* getRootNode();

	//clears
	void clear();
	//actually adds to the tree given the data that they want to add into the AVL
	bool add(int data);
	//removes given the data
	bool remove(int data);


//balances the entire tree by calling the other balancing functions
	void balance(Node*& n);
	//rotates right
	void rotateRight(Node*& n);
	//rotates left
	void rotateLeft(Node*& n);
	//balances the right side
	void balanceRight(Node*& n);
	//you get the deal
	void balanceLeft(Node*& n);


//receives the max
	int getMax(Node* n);
	int getNodeHeight(Node* n);
	int updateHeight(Node* n);
};

#endif /* TREE_H_ */
