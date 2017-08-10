/*
 * Tree.h
 *
 *  Created on: Mar 29, 2016
 *      Author: aguel
 */

#ifndef TREE_H_
#define TREE_H_



#include <iostream>
#include <string>

#include "Node.h"
#include "BSTInterface.h"

using std::string;

class Tree : public BSTInterface {
private:
	Node* root;


	//Recursive Functions
	bool add(Node*& n, int data);
	bool remove(Node*& n, int data);

public:
	Tree() : root(NULL) {};
	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node* getRootNode();
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

	//gives out the max value position in the tree
	int getMax(Node* n);

};


#endif /* TREE_H_ */
