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
    double average;
    vector<double> Grades;
public:
    Student(string name, int ID)
    {
       Name = name;
       StudentID = ID;
    }
    string getName() const {
        return Name;
    }
    void getGrades(){
        int totalOfGrades;
        cout << "How many grades are you going to enter?" << endl;
        cin >> totalOfGrades;
        while(totalOfGrades < 0){
            cout << "Please enter valid number of grades" << endl;
            cin >> totalOfGrades;
        }
        for(int i = 0; i < totalOfGrades; i++){
            double grades;
            cout << "Enter Exam Grade: ";
            cin >> grades;
            Grades.push_back(grades);
        }
        cout << endl;
    }
    double averageGrade(){
        double sum = 0;
        for(int i = 0; i < Grades.size(); i++){
            sum += Grades[i];
        }
        average = Grades.empty() ? 0.0 : sum / Grades.size();
        return average;
    }
    double calculateAverage(){
        double sum = 0;
        for(int i = 0; i < Grades.size(); i++){
            sum += Grades[i];
        }
        average = Grades.empty() ? 0.0 : sum / Grades.size();
        cout << "Average Grade: " << average << endl;
        return average;
    }
    void displayGrades(){
        cout << "Name: " << Name << endl;
        cout << "ID: " << StudentID << endl;
        for(int i = 0; i < Grades.size(); i++){
            cout << "Grade " << i + 1  << " - " << Grades[i] << endl;
        }
    }
    void calculateLetterGrade(){
        if(average >=90){
            cout << "You earned an A!" << endl;
        }else if(average <= 89 && average >= 80){
            cout << "You earned a B!" << endl;
        }else if(average <= 79 && average >=70){
            cout << "You earned a C!" << endl;
        }else if(average <=69){
            cout << "You failed dumbass!" << endl;
        }
    }
};
#endif //STUDENTGRADEBOOK_STUDENTCLASS_H
