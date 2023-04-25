#include <iostream>
#include <iomanip>
#include <string>
#include "StudentClass.h"
using namespace std;

int main(){
    string name;
    int studentID;
    vector<double>Grades;
    vector<Student>students;

    char confirm;
    do {
        cout << "Enter students name: ";
        getline(cin, name);
        cout << "Enter Student ID: ";
        cin >> studentID;

        students.emplace_back(name, studentID);
        students.back().getGrades();
        students.back().displayGrades();
        students.back().calculateAverage();
        Grades.clear();

        cout << "\nWould you like to enter other students?";
        cin >> confirm;
        cin.ignore();
    } while (confirm == 'y' || confirm == 'Y');

    for (int i = 0; i < students.size(); i++) {
        cout << "\n=============================" << endl;
        cout << "Student " << i + 1 << ":" << endl;
        students[i].displayGrades();
        students[i].calculateAverage();
        students[i].calculateLetterGrade();
        cout << endl;
    }
    double highestAverage = 0;
    int highestIndex = -1;

    for(int i = 0; i < students.size();i++){
        double currentAverage = students[i].averageGrade();
        if(currentAverage > highestAverage){
            highestAverage = currentAverage;
            highestIndex = i;
        }
    }
    if(highestIndex != -1){
        cout << "The student with the highest average is " << students[highestIndex].getName()
             << " with an average of " << highestAverage <<"%"<<endl;
    }else{
        cout << "No students found" << endl;
    }
    return 0;
}
