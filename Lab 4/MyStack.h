/*
 * MyStack.h
 *
 *  Created on: Oct 22, 2015
 *      Author: aguel
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_
#include <stack>
#include <cstdlib>
using namespace std;
#include "LinkedList.h"


class Stack{
public:
	Stack(){};
~Stack(){
	//LL.clear();
};

void pop();

bool push();
int size();

private:
LList LL;

};



#endif /* MYSTACK_H_ */
