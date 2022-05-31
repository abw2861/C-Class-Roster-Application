#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteEachCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SECURITY;
	
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteEachCourse[], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
	}
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}

/*Setters*/
void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
 }

void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToCompleteEachCourse(int daysToCompleteEachCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

/*Getters*/
string Student::getStudentId() {
	return this->studentId;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToCompleteEachCourse() {
	return this->daysToCompleteEachCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::print() {

	cout << this->getStudentId() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t' << '\t';
	cout << "Days in Course: " << '{' << this->getDaysToCompleteEachCourse()[0] << ',';
	cout << this->getDaysToCompleteEachCourse()[1] << ',';
	cout << this->getDaysToCompleteEachCourse()[2] << '}' << '\t';
	cout << "Degree: " << degreeProgramStrings[this->getDegreeProgram()] << endl; 
	
}
