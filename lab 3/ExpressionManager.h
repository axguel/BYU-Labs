/*
 * ExpressionManager.h
 *
 *  Created on: Feb 7, 2016
 *      Author: alexis
 */

#ifndef EXPRESSIONMANAGER_H_
#define EXPRESSIONMANAGER_H_
#include "ExpressionManagerInterface.h"
class ExpressionManager :
	public ExpressionManagerInterface
{
public:
	ExpressionManager(void);
	~ExpressionManager(void);
	//checks to see if equation is balanced
	bool isBalanced(string expression);
	//postfix to infix
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);
	//checks the precendence of the different opperands
	bool higherPrecidence(string current, string topOfStack);
	//makes sure the string is valid before starting opperation
	bool isValid(string expression);
};

#endif /* EXPRESSIONMANAGER_H_ */
