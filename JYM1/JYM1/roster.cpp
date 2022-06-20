//
//  roster.cpp
//  C867 JYM1
//  Corey Hall
//  SID #001491899
#include <string>
#include "student.h"
#include "roster.h"

//parse student info
void Roster::parse (string studentData){
    
DegreeProgram degree = UNDECLARED;
        if (studentData.at(1) == '1') degree = SECURITY;
        else if (studentData.at(1) == '2') degree = NETWORK;
        else if (studentData.at(1) == '3') degree = SOFTWARE;
        else if (studentData.at(1) == '4') degree = SECURITY;
        else if (studentData.at(1) == '5') degree = SOFTWARE;
    
    int rhs = studentData.find(",");
    string sId = studentData.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAdd = studentData.substr(lhs, rhs -lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age_ = stoi(studentData.substr(lhs, rhs -lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day1 = stod(studentData.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day2 = stod(studentData.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day3 = stod(studentData.substr(lhs, rhs-lhs));
    
    
    add(sId, fName, lName, emailAdd, age_, day1, day2, day3, degree);
}

//update roster
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree) {
    int daysArray[3] = { days1, days2, days3 };
    
    classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, degree, daysArray);
}

//remove
void Roster::remove(string studentId){
    bool found = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        
    if (classRosterArray[i]->getStudentId() == studentId){
        found = true;
        if (i < numStudents - 1){
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
                }
            Roster::lastIndex--;
        }
    }
    if (found){
        cout << studentId << ": Removed from Roster." << endl;
    }
    else{
        cout << studentId << " Student not found" << endl;
    }
}
//print functions
    void Roster::printAll(){
        Student::printHeader();
        
        for (int i = 0; i <= Roster::lastIndex; i++){
        cout << classRosterArray[i]->getStudentId(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]->getEmail(); cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
        cout << DegreeStrings[classRosterArray[i]->getDegree()] << std::endl;
        }
    }

//prints average days per course
    void Roster::printAverageDaysPerCourse(string studentId){
        
        for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << classRosterArray[i]->getStudentId() << ": ";
        cout << (classRosterArray[i]->getDaysInCourse()[0]
                 + classRosterArray[i]->getDaysInCourse()[1]
                 + classRosterArray[i]->getDaysInCourse()[2]) / 3
                 << std::endl;
        }
        return;
    }

//Prints invalid email addresses
    void Roster::printInvalidEmails() {
    
        for (int i = 0; i < 5; ++i) {
        string emailAddress = classRosterArray[i]->getEmail();
        if ((emailAddress.find(' ') != string::npos) || (emailAddress.find('.') == string::npos) || (emailAddress.find('@') == string::npos)) {
            cout << classRosterArray[i]->getStudentId() << "'s email address " << emailAddress  << endl;
        }
    }
    return;
}

//Prints all students by degree program
void Roster::printByDegreeProgram(DegreeProgram degree) {
    string DegreeStrings;
    if (degree == SECURITY) {
        DegreeStrings = "SECURITY";
    }
    else if (degree == NETWORK) {
        DegreeStrings = "NETWORK";
    }
    else if (degree == SOFTWARE) {
        DegreeStrings = "SOFTWARE";
    }
    else {
        DegreeStrings = "UNDECLARED";
    }
    cout << DegreeStrings << " Students:"  << endl;
    int numStudents = 0;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->getDegree() == degree) {
            classRosterArray[i]->printAll();
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "No students with this degree found." << endl;
    }
    return;
}

// destructor
Roster::~Roster() {
    cout << "Roster Deleted" << endl;
        delete classRosterArray[numStudents];
    
}


