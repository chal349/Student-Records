//
//  roster.h
//  C867 JYM1
//  Corey Hall
//  SID #001491899

#pragma once
#include "student.h"
class Roster
{
public:
    void parse(string row);
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree);
    void remove(string studentId);
    void printAll();
    void printAverageDaysPerCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    ~Roster();

private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
};

