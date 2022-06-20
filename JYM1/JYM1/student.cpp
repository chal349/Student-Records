//
//  student.cpp
//  C867 JYM1
//  Corey Hall
//  SID #001491899


#include "student.h"
#include "degree.h"

using namespace std;

//constructor
Student::Student(){
    this-> studentId = "";
    this-> firstName = "";
    this-> lastName = "";
    this-> email = "";
    this-> age = 0;
    this-> degree = DegreeProgram::UNDECLARED;
    for (int i = 0; i < daysArray; i++)
        this->daysInCourse[i] = 0;
    
}
Student::Student(string studentId, string firstName, string lastName, string email, int age, DegreeProgram degree, int daysInCourse[]){
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->degree = degree;
    for (int i = 0; i < daysArray; i++)
        this->daysInCourse[i] = daysInCourse[i];
    
}

//deconstructor
Student::~Student(){
}

//getters
string Student::getStudentId(){
    return this->studentId;}
string Student::getFirstName(){
    return this->firstName;}
string Student::getLastName(){
    return this->lastName;}
string Student::getEmail(){
    return this->email;}
int Student::getAge(){
    return this->age;}
int* Student::getDaysInCourse(){
    return this->daysInCourse;}
DegreeProgram Student::getDegree(){
    return this->degree;}

//setters
void Student::setStudentId(string studentId){
    this->studentId = studentId;}
void Student::setFirstName(string firstName){
    this->firstName = firstName;}
void Student::setLastName(string lastName){
    this->lastName = lastName;}
void Student::setEmail(string email){
    this->email = email;}
void Student::setAge(int age){
    this->age = age;}
void Student::setDegree(DegreeProgram degree){
    this->degree = degree;}
void Student::setDaysInCourse(int daysInCourse[]){
    for (int i = 0; i < daysArray; i++)
        this->daysInCourse[i] = daysInCourse[i];}

//print header
void Student::printHeader(){
    cout << "-------------------------------------------------------------------\n";
    cout << "ID     | Student |   Age   |  Email  |  Days In Course | Degree\n";
    cout << "-------------------------------------------------------------------\n";
    }
//print student info
void Student::printAll()
{
    cout << this->getStudentId() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getDaysInCourse()[0] << ' ';
    cout << this->getDaysInCourse()[1] << ' ';
    cout << this->getDaysInCourse()[2] << '\t';
    cout << DegreeStrings[this->getDegree()] << '\n';
}



