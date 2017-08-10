/*
 * Station.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: aguel
 */

#include "Station.h"

const int NONE = -1;
/*int Station::nextID = 0;

Station::Station(int ID, int currentCar){
ID = nextID++;
currentCar = 0;
}*/

bool Station::addToStation(int car){
	if(currentCar!=NONE){
		return false;
	} else if(car <= NONE){
		return false;
	}else{

		currentCar = NONE;
		return true;
	}
}

//removes car from station by setting currentCar back to -1
bool Station::removeFromStation(){
	if(currentCar==NONE){
		return false;
	}else{
		currentCar=NONE;
		return true;
	}
}

int Station::showCurrentCar(){
	return currentCar;
}
