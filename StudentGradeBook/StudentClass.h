#ifndef STUDENTGRADEBOOK_STUDENTCLASS_H
#define STUDENTGRADEBOOK_STUDENTCLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Student{
private:
    string Name;
    int StudentID;
    vector<double> Grades;
public:
    Student(string name, int ID, vector<double>&Grades)
    {
       Name = name;
       StudentID = ID;
    }
    void getGrades(vector<double> &Grades){
        int totalOfGrades;
        cout << "How many grades are you going to enter?" << endl;
        cin >> totalOfGrades;
        for(int i = 0; i < totalOfGrades; i++){
            double grades;
            cout << "Enter Exam Grade: ";
            cin >> grades;
            Grades.push_back(grades);
        }
        cout << endl;
    }
    void displayGrades(vector<double>&Grades, string name, int StudentID    ){
        cout << "Name: " << name << endl;
        cout << "ID: " << StudentID << endl;
        for(int i = 0; i < Grades.size(); i++){
            cout << "Grade " << i + 1  << " - " << Grades[i] << endl;
        }
    }
    void calculateGrades(vector<double> &Grades){
        double sum = 0;
        for(int i = 0; i < Grades.size(); i++){
           sum += Grades[i];
        }
        double average = sum/Grades.size();
        cout << "The average grade for is: " << average << "%" << endl;
    }
};
#endif //STUDENTGRADEBOOK_STUDENTCLASS_H
