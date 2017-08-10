/*
 * GPA.h

 *
 *  Created on: Jan 29, 2016
 *      Author: alexis
 */
#pragma once
#include "GPAInterface.h"
#include <fstream>
#include <sstream>
typedef map<unsigned long long int, StudentInterface*>::iterator mapIterator;
typedef set<StudentInterface*, Comparator>::iterator setIterator;

class GPA :
	public GPAInterface
{
public:
	GPA();
	~GPA();
        
	map<unsigned long long int, StudentInterface*> getMap(); 
	set<StudentInterface*, Comparator> getSet();
//prints out the map
	void printMap(); 
        //prints out the set
	void printSet(); 
        //searched for the students in the map and if not, then it is in the set
	bool InMap(unsigned long long int); 
        //vice versa of the map
	bool InSet(unsigned long long int); 
        //adds the grade into the GPA of the student
	bool addGrade(unsigned long long int IDP, string gradeLetter); 
	string querySet(string fName);
	string queryMap(string fName);
        //gets the grade and returns it for the GPS value
	double getGrade(string gradeLetter); 
	//clears set
        void clearSet();
        //clears map
	void clearMap();
        //clears things in the datatype
	void clear();
        //imports students from tile and puts them in a set or a map
        bool importStudents(string mapFileName, string setFileName)
        //puts the students into a map
	bool importStudentsMap(string fName);
        //puts students into a set
	bool importStudentsSet(string fName);
        //imports grades for the students
	bool importGrades(string fName); 
        //checks for validity
	bool isValidStudentFile(string fName) const;
	bool isValidGradeFile(string fName) const; 
	bool isValidQuery(string fName);
private:
	map<unsigned long long int, StudentInterface*> sMap;
	set<StudentInterface*, Comparator> sSet;
};

