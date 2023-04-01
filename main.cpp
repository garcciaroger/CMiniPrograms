//
// Created by Roger Garcia on 4/1/2023.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    //This program will be a grade book that will allow
    //the user to enter the amount of tests and grade

    //Ask user to enter information
    int numExam, numStudents;
    double averageGrade, sumGrade;
    cout << "Enter the number of exams " << endl;
    cin >> numExam;
    cout << "Enter the number of students " << endl;
    cin >> numStudents;

    //This block of code will allow the user to start entering the number of
    //grades and number of students
    for (int i{0}; i < numStudents; ++i) {
        cout << "Enter Grades for student: " << i + 1 << endl;
        for (int j{0}; j < numExam; ++j) {

            vector<double> examGrade{};
            //User enters the exam grade
            cout << "Enter Exam " << (j + 1) << endl;
            cin >> grades;


            //Validates grade entry
            if (grades < 0 || grades > 100) {
                cout << "Please enter a valid grade." << endl;
                cin >> grades;
            }
            //Calculate the grade average
            sumGrade = grades += grades;
            averageGrade = sumGrade / grades;
        }
        cout << "The Average Grade for student One is " << averageGrade << endl;
    }
}





