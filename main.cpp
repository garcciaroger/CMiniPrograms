#include <iostream>
#include <vector>
using namespace std;

int main() {
    //This program will be a grade book that will allow
    //the user to enter the amount of tests and grade

    //Ask user to enter information
    int numExam, numStudents{0};
    double grades;
    vector<double> test_scores{0};
    cout << "Enter the number of exams " << endl;
    cin >> numExam;
    cout << "Enter the number of students " << endl;
    cin >> numStudents;
    //This block will start allowing the user to see the
    //grade book results5


    for(int i{0};i<numStudents;++i){
        test_scores.clear();
        cout << "Enter grades for student: " << i+1 << endl;
        for(int j{0};j<numExam;++j){
            cout << "Enter Exam Grade: " << endl;
            cin >> grades;
            while(grades < 0 || grades > 100) {
                cout << "Please enter a valid grade." << endl;
                cin >> grades;
            }
            test_scores.push_back(grades);
        }//Inner Loop

        double sumGrade = 0;
        double average = 0;
        for(int i{0};i<test_scores.size();++i){
            sumGrade += test_scores[i];
        }
        average = sumGrade/test_scores.size();
        cout << "Average Grade is " << average << endl;

        if(average >= 90){
            cout << "You got an A!" << endl;
        }else if (average>=80&&average<=89){
            cout << "You got an B!" << endl;
        }else if (average >=70&&average<=79){
            cout << "You got an C!" << endl;
        }else if (average >=60&&average<=69){
            cout << "You got an D!" << endl;
        }else{
            cout << "You got an F Idiot!" << endl;
        }
        cout << endl;
    }//Outer
}//Main Bracket

