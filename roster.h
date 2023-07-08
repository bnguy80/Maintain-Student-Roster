#ifndef ROSTER_H
#define ROSTER_H

using namespace std;

#include <string>
#include <vector>
#include "degree.h"
#include "student.h"

class Roster {

public:
	vector<Student*> students;

	Roster();


	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);	

	~Roster(); 
};
#endif
