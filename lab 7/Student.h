/*
 * Student.h
 *
 *  Created on: Jan 28, 2016
 *      Author: alexis
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "StudentInterface.h"
#include <sstream>
#include <iomanip>

class Student :
	public StudentInterface
{
public:
	Student();
	Student(unsigned long long int idP, string nameP, string addressP,string phoneNumberP);
	~Student();
	unsigned long long int getID();
	string getName();
	string getGPA();
	double getGPADb();
	int getNumberCourses() const;
	void addGPA(double classGrade);
	string toString();

private:
	unsigned long long int id;
	string name;
	string address;
	string phoneNumber;

	double totalGradePoints;
	int numGrades;
};
#endif /* STUDENT_H_ */
