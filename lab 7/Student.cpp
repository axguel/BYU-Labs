/*
 * Student.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: alexis
 */
#include "Student.h"
#include <iostream>


Student::Student(unsigned long long int idP, string nameP, string addressP, string phoneNumberP)
{
	name = nameP;
	id = idP;
	address = addressP;
	phoneNumber = phoneNumberP;

	totalGradePoints = 0;
	numGrades = 0;
}


Student::~Student()
{
}

//Returns total number of courses taken
int Student::getNumberCourses() const
{
	return numGrades;
}

unsigned long long int Student::getID()
{
	return id;
}

string Student::getName()
{
	return name;
}

double Student::getGPADb()
{
	if (numGrades == 0)
		return 0;

	double gpa = totalGradePoints / numGrades;

	return gpa;

}

string Student::getGPA()
{
//	cout << "GPA is " << getGPADb() << endl;
//	cout << getGPADb() << "\t" << int(getGPADb()) << endl;
//	stringstream s("");
//
//	s << getGPADb();
//	if (getGPADb() == int(getGPADb()))
//	{
//		s << ".00";
//		cout << "1: Returning " << s.str() << endl;
//		return s.str();
//	}
//
//	if (s.str().length() > 4)
//	{
//		stringstream newS("");
//		newS << setprecision(3) << getGPADb();
//		cout << "2: Returning " << newS.str() << endl;
//		return newS.str();
//	}
//	if (s.str().length() == 3)
//	{
//		s << "0";
//	}

	//if (s.str() == "2")
		//return "2.00";

//	cout << "3: Returning " << s.str() << endl;

	stringstream s("");

	s << fixed << setprecision(2) << getGPADb();
	return s.str();
}

void Student::addGPA(double classGrade)
{
	totalGradePoints += classGrade;
	numGrades++;
}

string Student::toString()
{
	stringstream ret("");

	ret << id << "\n"
		<< name << "\n"
		<< address << "\n"
		<< phoneNumber << "\n"
	    << getGPA();

	return ret.str();
}
