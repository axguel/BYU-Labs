/*
 * Factory.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: aguel
 */

#include "Factory.h"
#include <string>
#include "LList.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getLinkedListInt() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<int>();".
*/
LinkedListInterface<int> * Factory::getLinkedListInt()
{
	return new LList<int>();//Modify this line
}

/*
	getLinkedListString() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<string>();".
*/
LinkedListInterface<string>* Factory::getLinkedListString()
{
	return new LList<string>();//Modify this line
}


