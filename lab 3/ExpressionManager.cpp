
/*
 * ExpressionManager.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: alexis
 */

#include "ExpressionManager.h"
#include <stack>
#include <sstream>
#include <stdlib.h>


ExpressionManager::ExpressionManager(void)
{
}


ExpressionManager::~ExpressionManager(void)
{
}

//checks to see if it is balanced
bool ExpressionManager::isBalanced(string expression)
{
    istringstream s;
    s.str(expression);
    stack<string> stack;
    //While string stream is not at the end of expression, checks the other characters in the string
    while (!s.eof())
    {
        string current;
        s >> current;

        //left parenth
        if (current == "(")
        {
            stack.push(current);
        }
        else if (current == "[")
        {
            stack.push(current);
        }
        else if (current == "{")
        {
            stack.push(current);
        }

        //right parenth
        else if (current == ")")
        {
            if (stack.empty()) {return false;}
            if (stack.top() == "(")
            {
                stack.pop();
            }
            else
            {//if it doesn't match
                return false;
            }
        }
        else if (current == "]")
        {
            if (stack.empty()) {return false;}
            if (stack.top() == "[")
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (current == "}")
        {
            if (stack.empty()) {return false;}
            if (stack.top() == "{")
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stack.empty())
    {return true;}
    else
    {return false;}
}

bool ExpressionManager::higherPrecidence(string current, string topOfStack)
{
    //these are the highest precedence
    if (current == "*" || current == "/" || current == "%")
    {
        if (topOfStack == "*" || topOfStack == "/" || topOfStack == "%")
        {return false;}

        else
        {return true;}
    }
    //lower precedence
    else if (current == "+" || current == "-")
    {
        //checks the top of the stack
        if (topOfStack == "+" || topOfStack == "-" || topOfStack == "*" || topOfStack == "/" || topOfStack == "%")
        {return false;}

        else
        {return true;}
    }
    else if (current == "(" || current == "[" || current == "{") //checking to see if balanced
    {return false;}

    else //checks for errors
    {
        cout << "Error";
        system("pause");
    }
}

//checks to see if it is a valid expression
bool ExpressionManager::isValid(string expression)
{
    if (!isBalanced(expression))
    {return false;}
    istringstream s;
    s.str(expression);
    int opcount = 0;
    int intcount = 0;
    while (!s.eof())
    {//checks the entire file until it is empty
        string current = "";
        s >> current;
        if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
        {opcount++;}
        else if (isdigit(current[0]))
        {intcount++;}
    }
    if (intcount == (opcount + 1))
    {return true;}
    else
    {return false;}
}



string ExpressionManager::postfixToInfix(string postfixExpression)
{//checks to make sure it is valid
    if (!isBalanced(postfixExpression)) {return "invalid";}
    istringstream s;
    s.str(postfixExpression);
    stack<string> stack;
    string result = "";
    while (!s.eof())
    { //reads the file until it is the end of the file
        string current;
        s >> current;
        if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
        {
            string space = " ";
            string op = current;
            //size check
            if (stack.empty())
            {return "invalid";}

            string bTop = stack.top(); //top of stack
            stack.pop();
            //checks to make sure the size if correct throughout
            if (stack.empty())
            {return "invalid";}

            string aTop = stack.top();
            stack.pop();
            //math yay
            result = "(" + space + aTop + space + op + space + bTop + space + ")";
            stack.push(result);
        }//makes sure everything is a digit
        else if (isdigit(current[0]))
        {
            for (unsigned int i = 0; i < current.size(); i++)
            {
                if (!isdigit(current[i]))
                {return "invalid";}
            }
            stack.push(current);
        }
        //if invalid
        else
        {return "invalid";}
    }
    //if invalid
    if (stack.size() == 1)
    {return stack.top();}
    else
    {return "invalid";}
    return "NULL";
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
    if (!isValid(infixExpression)) {return "invalid";}
    istringstream s;
    s.str(infixExpression);
    stack<string> stack;
    string sp = " ";
    string result = "";
    while(!s.eof())
    { //reads until the end of the file
        string current;
        s >> current;
//makes sure it is a digit
        if (isdigit(current[0]))
        {
            for (unsigned int i = 0; i < current.size(); i++)
            {
                if (!isdigit(current[i]))
                {return "invalid";}
            }
            result += current + sp;
        }
//checks for opperand
        else if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
        {
            if (stack.empty())
            {
                stack.push(current);
            }
            else if (higherPrecidence(current, stack.top()))
            {
                stack.push(current);
            }
            else if (!higherPrecidence(current, stack.top()))
            {
                result += stack.top() + sp;
                stack.pop();
                stack.push(current);


            }
        }
//left parenth
        else if (current == "(" || current == "[" || current == "{")
        {
            stack.push(current);
        }
        //right parenth
        else if (current == ")" || current == "]" || current == "}")//pop until parend
        {
            while (stack.top() != "(" && stack.top() != "[" && stack.top() != "{")
            {
                result += stack.top() + sp;
                stack.pop();
            }
            if (stack.top() == "(" || stack.top() == "[" || stack.top() == "{")
            {
                stack.pop();
            }
        }
        else
        {return "invalid";}
    }
    //pop off the rest of the stack
    while (stack.size() > 1)
    {
        //pop until lower precidence is detected
        result += stack.top() + sp;
        stack.pop();
    }
    result += stack.top();
    return result;
}


string ExpressionManager::postfixEvaluate(string postfixExpression)
{
    istringstream s;
    s.str(postfixExpression);
    stack<int> stack;
    int result = 0;
    //Balance Check
    if (!isBalanced(postfixExpression)) {return "invalid";}

    while (!s.eof()) //this equation takes off numbers and inserts the operands
    {
        string current;
        s >> current;
        if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
        {
            int firstInt, secondInt = 0;
            if (!stack.empty())//size check
            {secondInt = stack.top();
            stack.pop();}

            else
            {return "invalid";}

            if (!stack.empty())//makes sure stack is the right size
            {firstInt = stack.top();
            stack.pop();}

            else
            {return "invalid";}

            //calculated sign
            if (current == "+")
            {result = firstInt + secondInt;}

            else if (current == "-")
            {result = firstInt - secondInt;}

            else if (current == "/")
            {
                if (secondInt == 0)
                {//divide by 0 case
                    cout << "Divide by zero\n";
                    return "invalid";
                }
                else
                {
                    result = firstInt / secondInt;
                }
            }

            else if (current == "*")
            {result = firstInt * secondInt;}

            else if (current == "%")
            {
                if (secondInt == 0)
                {
                    cout << "Mod by zero\n";
                    return "invalid";
                }
                else
                {
                    result = firstInt % secondInt;
                }
            }

            stack.push(result);
        }
        else if (isdigit(current[0]))
        {
            istringstream stringToInt;
            stringToInt.str(current);
            int currentAsInt;
            stringToInt >> currentAsInt;
            stack.push(currentAsInt);
            result = currentAsInt;
        }
        else
        {return "invalid\n";}
    }

    if (stack.size() != 1)
    {
        return "invalid";
    }
    stringstream intToString;
    intToString << result;

    return intToString.str();
}
