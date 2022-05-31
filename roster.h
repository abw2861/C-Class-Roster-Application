#pragma once
#include "student.h"
#include <string>

class Roster {

private:
	int index = -1;

public:
	void parse(string row);
	void add(string studentId, 
		string firstName,
		string lastName, 
		string emailAddress, 
		int age, 
		int numDays1, 
		int numDays2, 
		int numDays3, 
		DegreeProgram degreeProgram);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void remove(string studentId);

public:
	Student* classRosterArray[5];
	~Roster();




};

