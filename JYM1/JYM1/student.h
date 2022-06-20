//
//  student.h
//  C867 JYM1
//  Corey Hall
//  SID #001491899

#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "degree.h"
using std::string;
using std::cout;

using namespace std;

class Student {

public:
    //constructor/deconstructor
    Student();
    Student(string studentId, string firstName, string lastName, string email, int age, DegreeProgram degree, int daysInCourse[]);
    ~Student();
    
    //daysInCourse array
    const static int daysArray = 3;
    
    // to print
    static void printHeader();
    void printAll();
    
    //getters
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    DegreeProgram getDegree();
    int* getDaysInCourse();
    
    
    //setters
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDegree(DegreeProgram degree);
    void setDaysInCourse(int daysInCourse[]);
    

private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    DegreeProgram degree;
    int daysInCourse[daysArray];
};


