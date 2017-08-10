/*
 * Factory.h
 *
 *  Created on: Feb 17, 2016
 *      Author: aguel
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "QSInterface.h"

using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================

class Factory
{
	public:
		static 	QSInterface * getQS();
};
//=======================================================================================


#endif /* FACTORY_H_ */
