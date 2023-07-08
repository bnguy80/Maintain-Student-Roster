
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;
int main()
{
    cout << "Scripting and Programming Application C867" << std::endl;
    cout << "Language: C++" << std::endl;
    cout << "WGU ID:03964281" << std::endl;
    cout << "Name: Brandon Nguyen" << std::endl;
    cout << "-----------------------------------------------------------------------" << std::endl;

    Roster* classRoster = new Roster();



    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Nguyen,bnguy80@wgu.edu,24,20,30,40,SOFTWARE"
    };

    for (int i = 0; i < 5; ++i) {
        vector<string> results;
        stringstream s_stream(studentData[i]);
        while (s_stream.good()) {
            string substr;
            getline(s_stream, substr, ',');
            results.push_back(substr);
        }

        DegreeProgram degreeProgram;
        if (results[8] == "Security") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        else if (results[8] == "Network") {
            degreeProgram = DegreeProgram::NETWORK;
        }
        else {
            degreeProgram = DegreeProgram::SOFTWARE;
        }

        (*classRoster).add(results[0], results[1], results[2], results[3], stoi(results[4]),
            stoi(results[5]), stoi(results[6]), stoi(results[7]), degreeProgram);
    }

     
    (*classRoster).printAll();
    (*classRoster).printInvalidEmails();
    for (int i = 0; i < 5; ++i) {
        
        (*classRoster).printAverageDaysInCourse((*classRoster).students[i]->GetStudentID());
    }

    (*classRoster).printByDegreeProgram(DegreeProgram::SOFTWARE);
    (*classRoster).remove("A3");
    (*classRoster).printAll();
    (*classRoster).remove("A3");
    
   
    delete classRoster;
}
