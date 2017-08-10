/*
 * Factory.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: aguel
 */

#include "Factory.h"
#include "Tree.h"
#include "AVLInterface.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getAVL()

	Creates and returns an object whose class extends AVLInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
AVLInterface * Factory::getAVL()
{
	return new Tree();//Modify this line
}


