//
//  main.cpp
//  C867 JYM1
//  Corey Hall
//  SID #001491899

#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
using std::cout;
using std::string;

int main(){
    
    cout << "Scripting and Programming C867" << endl;
    cout << "C++" << endl;
    cout << "#001491899" << endl;
    cout << "COREY HALL"<< endl;
    cout << endl;
    
    const string studentData[] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Corey,Hall,chal349@wgu.edu,32,12,15,31,SOFTWARE"
    };

const int numStudents = 5;
Roster classRoster;

for (int i = 0; i < numStudents; i++)classRoster.parse(studentData[i]);
cout << "STUDENT ROSTER:  " << endl;
classRoster.printAll();
    cout << endl;

cout << "INVALID EMAILS:" << endl;
classRoster.printInvalidEmails();
cout << endl;

//average days per course
cout << "AVERAGE DAYS IN COURSE PER STUDENT:  " << endl;
classRoster.printAverageDaysPerCourse("A5");
cout << endl;

//printing software students
classRoster.printByDegreeProgram(SOFTWARE);
cout << endl;
    
//removing student A3
classRoster.remove("A3");
cout << endl;
   
//new roster
classRoster.printAll();
cout << endl;
    
//remove student again
classRoster.remove("A3");
cout << endl;
    
//Destructor
classRoster.~Roster();
    
    

return 0;
}
