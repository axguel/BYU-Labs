/*
 * Node.h
 *
 *  Created on: Mar 29, 2016
 *      Author: aguel
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include "NodeInterface.h"

class Node : public NodeInterface {
public:
	int data;
	//left child
	Node* left;
	//right child
	Node* right;
//constructs a clear node with no children
	Node() : data(0), left(NULL), right(NULL) {};
	Node(int data) : data(data), left(NULL), right(NULL) {};
	//data stored inside of the node
	int getData() {
		return data;
	}
	//the left child of the node
	Node* getLeftChild() {
		return left;
	}
	//the right child of the node
	Node* getRightChild() {
		return right;
	}


};



#endif /* NODE_H_ */
