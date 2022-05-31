#pragma once
#include <iostream>
#include "degree.h"
#include <string>
using namespace std;

class Student {

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteEachCourse[3];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteEachCourse[], DegreeProgram degreeProgram);
	~Student();

public:
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCompleteEachCourse();
	DegreeProgram getDegreeProgram();

	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteEachCourse(int daysToCompleteEachCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

};

