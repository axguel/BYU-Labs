/*
 * Node.h
 *
 *  Created on: Apr 6, 2016
 *      Author: aguel
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <iostream>
#include "Tree.h"
#include "NodeInterface.h"

class Node : public NodeInterface {
private:
	//the data that the node is actually going to hold
	int data;
	//points to the node to the left
	Node* left;
	//points to the node to the right
	Node* right;
	//contains the actual height of the node
	int height;
	friend class Tree;
public:
	Node() : data(0), left(NULL), right(NULL) {};
	Node(int data) : data(data), left(NULL), right(NULL) {};
	//returns data
	int getData() {
		return data;
	}
	//returns the left child
	Node* getLeftChild() {
		return left;
	}
	//returns the right child
	Node* getRightChild() {
		return right;
	}
	//gets the height of the node
	int getHeight() {
		return height;
	}
};


#endif /* NODE_H_ */
