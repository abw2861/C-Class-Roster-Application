#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


void Roster::parse(string row) {
	DegreeProgram degreeProgram = SECURITY;

	if (row.at(row.size() - 1) == 'Y') {
		degreeProgram = SECURITY;
	}
	else if (row.at(row.size() - 1) == 'K') {
		degreeProgram = NETWORK;
	}
	else if (row.at(row.size() - 1) == 'E') {
		degreeProgram = SOFTWARE;
	}

	size_t rhs = row.find(",");
	string studentId = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays3 = stoi(row.substr(lhs, rhs - lhs));

	add(studentId, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeProgram);

	}

void Roster::add(string studentId,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int numDays1,
	int numDays2,
	int numDays3,
	DegreeProgram degreeProgram) {

	int numDaysEachCourse[3] = { numDays1, numDays2, numDays3 };

	classRosterArray[++index] = new Student(studentId, firstName, lastName, emailAddress, age, numDaysEachCourse, degreeProgram);

}

void Roster::printAverageDaysInCourse(string studentId) {

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			cout << "Student ID: " << classRosterArray[i]->getStudentId() << ", average days in course is: ";
			cout << (((classRosterArray[i]->getDaysToCompleteEachCourse()[0])
				+ (classRosterArray[i]->getDaysToCompleteEachCourse()[1])
				+ (classRosterArray[i]->getDaysToCompleteEachCourse()[2])) / 3) << endl;
		}
	}
}

void Roster::printInvalidEmails() {

	cout << "Displaying invalid emails:" << endl << endl;

	for (int i = 0; i < 5; i++) {
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if ((emailAddress.find(' ') != string::npos) || (emailAddress.find('@') == string::npos) || (emailAddress.find('.') == string::npos)) {
			cout << classRosterArray[i]->getEmailAddress() << '\t' << " - is an invalid email." << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Displaying students in degree program: " << degreeProgramStrings[degreeProgram] << endl << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}

	}
	cout << endl;
}
void Roster::printAll() {

	cout << "Displaying all students:" << endl << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::remove(string studentId) {
	int arrSize = 5;
	bool found = false;

	for (int i = 0; i < arrSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentId() == studentId) {
				found = true;
				cout << "Removing " << studentId << ":" << endl;
				classRosterArray[i] = nullptr;
				cout << "The student with the ID '" << studentId << "' was successfully removed." << endl << endl;
			}
		}
	}
	if (!found) {
		cout << "Removing " << studentId << ":" << endl;
		cout << "The student with the ID '" << studentId << "' was not found." << endl << endl;
	}
}

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "DONE" << endl;
}