/*
 * GPA.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: alexis
 */
#include "GPA.h"
#include "Student.h"
#include <iostream>
using namespace std;

GPA::GPA()
{
}


GPA::~GPA()
{
	clear();
}

set<StudentInterface*, Comparator> GPA::getSet()
{
	return sSet;
}

map<unsigned long long int, StudentInterface*> GPA::getMap()
{
	return sMap;
}

void GPA::printSet()
{
	for (setIterator it = sSet.begin(); it != sSet.end(); ++it)
	{
		cout << (it == sSet.begin() ? "": "\n\n") << (*it)->toString() << endl;
		//cout << "ID: " << (*it)->getID() << "\tStudent: " << (*it)->getName() << endl;
	}

}
void GPA::printMap()
{

	for (mapIterator it = sMap.begin(); it != sMap.end(); ++it)
	{
		cout << (it == sMap.begin() ? "": "\n\n") << it->second->toString() << endl;
		//cout << "ID: " << it->second->getID() << "\tStudent: " << it->second->getName() << endl;
	}
}

bool GPA::isValidGradeFile(string fName) const
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int idNum;

	while (in >> idNum)
	{
		in.ignore();

		string className = "";
		getline(in, className);
		if (className == "")
			return false;


		string gradeLetter = "";
		getline(in, gradeLetter);
		if (gradeLetter == "")
			return false;
	}

	if (!in.eof())
		return false;

	in.close();

	return true;
}
bool GPA::isValidStudentFile(string fName) const
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int idNum;
	while (in >> idNum)
	{
		in.ignore();

		string name = "";
		getline(in, name);
		if (name == "")
			return false;

		string address = "";
		getline(in, address);
		if (address == "")
			return false;

		string phoneNumber = "";
		getline(in, phoneNumber);
		if (phoneNumber == "")
			return false;

	}

	if (!in.eof())
		return false;

	in.close();

	return true;
}

//Precondition: Must be a valid file
bool GPA::importStudentsMap(string fName)
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int tempID;
	while (in >> tempID)
	{
		in.ignore();

		string tempName;
		getline(in, tempName);

		string tempAddress;
		getline(in, tempAddress);

		string tempNumber;
		getline(in, tempNumber);

		StudentInterface* temp = new Student(tempID,tempName,tempAddress,tempNumber);
		sMap[tempID] = temp;

	}

	in.close();
	return true;
}

//Precondition: Must be a valid file
bool GPA::importStudentsSet(string fName)
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int tempID;
	while (in >> tempID)
	{
		in.ignore();

		string tempName;
		getline(in, tempName);

		string tempAddress;
		getline(in, tempAddress);

		string tempNumber;
		getline(in, tempNumber);

		StudentInterface* temp = new Student(tempID, tempName, tempAddress, tempNumber);
		sSet.insert(temp);
	}


	in.close();
	return true;

}

bool GPA::importStudents(string mapFName, string setFName)
{
	if (!isValidStudentFile(mapFName) || !isValidStudentFile(setFName))
		return false;

	importStudentsMap(mapFName);
	importStudentsSet(setFName);
	return true;
}

bool GPA::InMap(unsigned long long int IDP)
{
	for(mapIterator it = sMap.begin();it != sMap.end();++it)
	{
		if (it->second->getID() == IDP)
			return true;
	}

	return false;
}
bool GPA::InSet(unsigned long long int IDP)
{
	for(setIterator it = sSet.begin();it != sSet.end();++it)
	{
		if ((*it)->getID() == IDP)
			return true;
	}

	return false;
}



//Precondition: IDP must be valid (in either the set or map).
bool GPA::addGrade(unsigned long long int IDP, string gradeLetter)
{
    bool inMap = InMap(IDP);
    bool inSet = InSet(IDP);

	if(!inMap && !inSet)
	{
		cout << "Error: ID was not found." << endl;
		return false;
	}

	if(inMap && inSet)
		cout << "Error: Found ID " << IDP << " in map and set." << endl;

    double gradeValue = getGrade(gradeLetter);

	if(inMap)
	{
		for(mapIterator it = sMap.begin();it != sMap.end();++it)
		{
			if (it->second->getID() == IDP)
			{
				it->second->addGPA(gradeValue);
				return true;
			}
		}
	}
	else if(inSet)
	{
		for(setIterator it = sSet.begin(); it != sSet.end(); ++it)
		{
			if((*it)->getID() == IDP)
			{
				(*it)->addGPA(gradeValue);
				return true;
			}
		}
	}
	else
	{
		cout << "Error: ID was not found" << endl;
		return false;
	}


	return true;
}

double GPA::getGrade(string gradeLetter)
{
    if(gradeLetter == "A")
        return 4;
    if(gradeLetter == "A-")
        return 3.7;
    if(gradeLetter == "B+")
        return 3.4;
    if(gradeLetter == "B")
        return 3;
    if(gradeLetter == "B-")
        return 2.7;
    if(gradeLetter == "C+")
        return 2.4;
    if(gradeLetter == "C")
        return 2;
    if(gradeLetter == "C-")
        return 1.7;
    if(gradeLetter == "D+")
        return 1.4;
    if(gradeLetter == "D")
        return 1;
    if(gradeLetter == "D-")
        return .7;
    if(gradeLetter == "E")
        return 0;

    //Invalid grade
    return -1;

}
bool GPA::importGrades(string fName)
{
	if (!isValidGradeFile(fName))
		return false;

	ifstream in;
	in.open(fName.c_str());

	unsigned long long int idNum;
	while (in >> idNum)
	{
		in.ignore();

		string className = "";
		getline(in, className);
		if (className == "")
			return false;

		string gradeLetter = "";
		getline(in, gradeLetter);
		if (gradeLetter == "")
			return false;

		addGrade(idNum,gradeLetter);
	}

	return true;
}


string GPA::querySet(string fName)
{
	if (!isValidQuery(fName))
		return "";

	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return "";


	stringstream output("");
	unsigned long long int idNum;

	while (in >> idNum)
	{
		for (setIterator it = sSet.begin(); it != sSet.end(); ++it)
		{
			if ((*it)->getID() == idNum)
			{
				output << (*it)->getID() << " "
					<< (*it)->getGPA() << " "
					<< (*it)->getName() << "\n";

				break;
			}
		}
	}

	return output.str();
}
bool GPA::isValidQuery(string fName)
{
    ifstream in;
    in.open(fName.c_str());

    if (in.fail())
        return false;

    unsigned long long int idNum;
    while (in >> idNum) {}

    if (!in.eof())
        return false;

    return true;
}
string GPA::queryMap(string fName)
{
	if (!isValidQuery(fName))
		return "";

	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return "";


	stringstream output("");
	unsigned long long int idNum;

	while (in >> idNum)
	{
		for (mapIterator it = sMap.begin(); it != sMap.end(); ++it)
		{
			if (it->first == idNum)
			{
				output << it->second->getID() << " "
					<< it->second->getGPA() << " "
					<< it->second->getName() << "\n";

				break;
			}
		}
	}

	return output.str();
}


void GPA::clearMap()
{
	mapIterator it = sMap.begin();


	while (it != sMap.end())
	{
		delete it->second;
		++it;
	}

	sMap.clear();
}
void GPA::clear()
{
	clearSet();
	clearMap();
}
void GPA::clearSet()
{
    setIterator it = sSet.begin();

    while (it != sSet.end())
    {
        delete *it;
        ++it;

    }


    sSet.clear();
}
