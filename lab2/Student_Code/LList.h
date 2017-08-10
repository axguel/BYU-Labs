/*
 * LList.h
 *
 *  Created on: Mar 29, 2016
 *      Author: aguel
 */

#pragma once
#include <iostream>
#include <stdexcept>
#include "LinkedListInterface.h"

using namespace std;

template<typename ItemType>
class LList: public LinkedListInterface<ItemType> {
private:
	struct Node {
		ItemType item;
		Node* next;
	};
	int items;
	Node* head;
	Node* tail;
public:
	LList() : items(0), head(NULL), tail(NULL){};
	~LList() {
		this->clear();
	}

	/*
		insertHead

		A node with the given value should be inserted at the beginning of the list.

		Do not allow duplicate values in the list.
	 */
	void insertHead(ItemType value) {
		if (!InList(value)) {
			Node* n = new Node();
			n->item = value;
			if (items == 0)
				tail = n;
			else
				n->next = head;
			head = n;
			items++;
		}
	}
	/*
		insertTail

		A node with the given value should be inserted at the end of the list.

		Do not allow duplicate values in the list.
	 */
	void insertTail(ItemType value) {
		if (!InList(value)) {
			if (items == 0)
				insertHead(value);
			else {
				Node* n = new Node();
				n->item = value;
				tail->next = n;
				tail = n;
				items++;
			}
		}
	}
	/*
		insertAfter

		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.

		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list.
	 */

	void insertAfter(ItemType value, ItemType insertionNode) {
		if (!InList(value)) {
			Node* node = head;
			while (node != NULL) {
				if (node->item == insertionNode) {
					Node* n = new Node();
					n->item = value;
					n->next = node->next;
					node->next = n;
					if (n->next == NULL)
						tail = n;
					items++;
				}
				node = node->next;
			}
		}
	}
	/*
		remove

		The node with the given value should be removed from the list.

		The list may or may not include a node with the given value.
	 */
	void remove(ItemType value) {
		//node pointers to different nodes
		Node* node = head;
		Node* toRemove;
		Node* prevNode;
		//checks to see if the value is the head or the tail of the list
		if (head->item == value) {
			toRemove = head;
			head = head->next;
			items--;
			if (toRemove == tail)
				tail = NULL;
			delete toRemove;
		}
		else {//goes through the entire list to find the value
			node = node->next;
			prevNode = head;
			while (node != NULL) {
				if (node->item == value) {
					toRemove = node;
					prevNode->next = toRemove->next;
					if (toRemove == tail)
						tail = prevNode;
					delete toRemove;
					items--;
					break;
				}
				node = node->next;
				prevNode = prevNode->next;
			}
		}
	}

	int size() {
		return items;
	}
	/*
		clear

		Remove all nodes from the list.
	 */
	void clear() {
		Node* n;
		while (this->size() > 0) {
			n = head;
			head = head->next;
			delete n;
			items--;
		}


	}
	/*
		at

		Returns the value of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, throw an out of range exception.
	 */
	ItemType at(int index) {
		if (index >= items || index < 0) {
			//throws out of range if given invalid index
			throw out_of_range("out of range");
		}
		else {
			Node* n = head;
			//goes through the entire list
			for (int i = 0; i <= index; i++) {
				if (i == index)
					return n->item;
				n = n->next;
			}
		}
	}

	//checks to see if a value is in the list or not
	bool InList(ItemType value) {
		Node* n = head;
		while (n != NULL) {
			if (n->item == value) return true;
			n = n->next;
		}
		return false;
	}
	//prints the list with the size
	void PrintList() {
		//points to the head node
		Node* n = head;
		//prints out the size
		cout << "Size: " << this->size() << " {";
		//loops through until the list is empty
		while (n != NULL) {
			cout << n->item << " ";
			n = n->next;
		}
		cout << "}" << endl;
	}
};


