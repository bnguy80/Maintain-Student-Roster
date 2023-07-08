#include <iostream>
#include "student.h"
/*
using namespace std;
*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, vector<int> numDaysPerCourse, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDaysPerCourse = numDaysPerCourse;
	this->degreeProgram = degreeProgram;
}


//getters
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

vector<int> Student::GetNumDaysPerCourse() const {
	return numDaysPerCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}


//setters
void Student::SetStudentID(string studentid) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetNumDaysPerCourse(vector<int> const& numDaysPerCourse) {
	this->numDaysPerCourse = numDaysPerCourse;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << this->studentID << "\t";
	cout << "First Name: " << this->firstName << "\t";
	cout << "Last Name: " << this->lastName << "\t";
	cout << "Age: " << this->age << "\t";
	cout << "daysInCourse: " << "{" << GetNumDaysInCourseAsString() << "}" << "\t";
	cout << "Degree Program: " << GetDegreeProgramAsString();
}

string Student::GetDegreeProgramAsString() {
	string output = "";

	switch (this->degreeProgram)
	{
	case DegreeProgram::SECURITY:
		output = "Security";
		break;
	case DegreeProgram::NETWORK:
		output = "Network";
		break;
	case DegreeProgram::SOFTWARE:
		output = "Software";
		break;
	}

	return output;
}

string Student::GetNumDaysInCourseAsString() {
	string output = "";
	int size = this->numDaysPerCourse.size();

	for (int i = 0; i < size; ++i) {
		string numToString = to_string(this->numDaysPerCourse.at(i));
		if (i < size - 1) {
			output = output + numToString + ", ";
		}
		else {
			output = output + numToString;
		}
	}

	return output;
}
