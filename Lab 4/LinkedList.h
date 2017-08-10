/*
 * LinkedList.h
 *
 *  Created on: Oct 20, 2015
 *      Author: aguel
 */

using namespace std;
#include <cstdlib>
#pragma once

const int notFound = -1;

class Node{
private:
	Node* nextNode;
	Node* prevNode;
	int data;

public:
	Node();
	Node(int data);
	Node* getNext() const{
		return this->nextNode;
	}

	Node* getPrev() const{
		return this->prevNode;
	}

	int getNum() const{
		return this->data;
	}

	void setNum(int newNum){
		this->data = newNum;
	}

	void setNext(Node *n){
		this->nextNode = n;
	}

	void setPrev(Node* n){
		this->prevNode = n;
	}

};

class LList{
private:
	Node* first;
	Node* last;
	int size; 
	int count;

public:
	LList();
	LList(const Node&, int);

	void push_back(Node*);
	
	void traverse();
	
	Node* getFirst()const{
		return first;
	}
	Node* getLast() const{
		return last;
	}
	int size() const{
		return count;
	}

	int search(int data);
};
//
//class LinkedList{
//private:
//	struct Node{
//		int data;
//		Node* next;
//		Node(int data, Node* next){
//			this->data;
//			this->next;
//		}
//		Node(const int& data_item, Node* next_ptr = NULL) :data(data_item), next(next_ptr){};
//	};
//	int count;
//	Node* head;
//	Node* tail;
//	int max;
//
//public:
//	LinkedList(int){
//	head = NULL;
//	tail = NULL;
//	max = 5;
//	count = 0;
//	};
//
//	~LinkedList(){
//		clear();
//	};
//
//	int search(int value){
//		Node* temp = head;
//		for(int i = 0; i <= count; i ++){
//			if(temp->data==value){
//				return i;
//			}
//		temp= temp->next;
//		}
//	return notFound;
//	};
//
//	bool push(int car){
//		if(count == max){
//			return false;
//		} else{
//			Node *temp = new Node;
//			if(head == NULL){
//				temp->data = car;
//				temp->next = NULL;
//				head=temp;
//				count++;
//				return true;
//			}else{
//				temp->data = car;
//				temp->next = NULL;
//				head = temp;
//				count++;
//				return true;
//			}
//		}
//	};
//
//	bool pop(){
//		if (head == NULL){
//			return false;
//		}
//		else {
//			Node * old = head;
//
//			head = head->next;
//			count--;
//			delete(old);
//			return true;
//		}
//		return false;
//	};
//	/*
//		insertHead
//
//		A node with the given value should be inserted at the beginning of the list.
//
//		Do not allow duplicate values in the list.
//	 */
//	virtual void insertHead(int value){
//		int check = search(value);
//		if(check == -1){
//		if(head == NULL){
//			head = new Node(value, NULL);
//			tail = head;
//		}else {
//
//			Node* temp = new Node(value, head);
//			head = temp;
//		}
//		count++;
//		}
//	};
//
//	/*
//		insertTail
//
//		A node with the given value should be inserted at the end of the list.
//
//		Do not allow duplicate values in the list.
//	 */
//	virtual void insertTail(int value){
//		int check = search(value);
//		if(check == notFound){
//		if(head == NULL){
//			tail = new Node(value, NULL);
//			head = tail;
//		}else{
//			Node* temp = new Node(value, NULL);
//			tail->next = temp;
//			tail = temp;
//		}
//		count++;
//		}
//	};
//
//	/*
//		clear
//
//		Remove all nodes from the list.
//	 */
//	virtual void clear(){
//		while (count > 0){
//		Node* ptr = head->next;
//		head->next = head->next->next;
//		delete ptr;
//		count--;
//		}
//	};
//
//	/*
//		size
//
//		Returns the number of nodes in the list.
//	 */
//	virtual int size(){
//	return count;
//	};
//
//
//};
//


