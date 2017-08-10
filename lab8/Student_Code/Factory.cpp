/*
 * Factory.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: aguel
 */

#include "Factory.h"
#include "QSTester.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getQS()

	Creates and returns an object whose class extends QSInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "QS", you might say, "return new QS();".
*/
QSInterface * Factory::getQS()
{
  return new QSTest();//Modify this line
}



