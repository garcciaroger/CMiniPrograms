#ifndef EMPLOYEEMANAGMENTSYSTEM_CLASSFILES_H
#define EMPLOYEEMANAGMENTSYSTEM_CLASSFILES_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Company Class
class Company{
private:
    string companyName;
    string companyAddress;
    string companyState;
    string mission;

public:
    Company(string name, string address, string state, string statement){
        companyName = name;
        companyAddress = address;
        companyState = state;
        mission = statement;
    }
    void displayCompanyInformation(){
        cout << "Company Name: " << companyName << endl;
        cout << "Company Address: " << companyAddress << endl;
        cout << "Company Mission: " << mission << endl;
    }
};

//Employee Class
class Employee{
private:
    string firstName;
    string lastName;
    string Address;
    string city;
    string state;
    string phoneNumber;
    string email;
    string position;
    int zip;
    int employeeID;

public:
    void getEmployeeInformation(){
        cout << "First Name: " << endl;
        getline(cin, firstName);
        cout << "Last Name: " << endl;
        getline(cin, lastName);
        cout << "Address: " << endl;
        getline(cin, Address);
        cout << "City: " << endl;
        getline(cin, city);
        cout << "State: " << endl;
        getline(cin, state);
        cout << "Zip Code: " << endl;
        cin >> zip;
        cin.ignore();
        cout << "Phone Number: " << endl;
        getline(cin, phoneNumber);
        cout << "Email: " << endl;
        getline(cin, email);
        cout << "Position: " << endl;
        getline(cin, position);
        cout << "Employee ID: " << endl;
        cin >> employeeID;
        cin.ignore();
    }
    void displayEmployeeInformation(){
        cout << "Employee Information" << endl;
        cout << "====================" << endl;
        cout << "First Name - " << firstName << endl;
        cout << "Last Name - " << lastName << endl;
        cout << "Address - " << Address << endl;
        cout << "City - " << city << endl;
        cout << "State - " <<  state << endl;
        cout << "Phone Number - " << phoneNumber << endl;
        cout << "Position - " << position << endl;
        cout << "Empolyee - " << employeeID << endl;
    }
};

//Salary Class
class Salary{
private:
    double salary;
    double bonus;
    double signOnBonus;
    double stockOption;

public:
    void getSalary(){
        cout << "Enter Base Salary: " << endl;
        cin >> salary;
        cout << "Enter Sign-on Bonus: " << endl;
        cin >> signOnBonus;
        cout << "Enter Stock Options: " << endl;
        cin >> stockOption;
        cout << "Enter Other incentives: " << endl;
        cin >> bonus;
    }
    void displaySalary(){
        cout << "Salary Information" << endl;
        cout << "==================" << endl;
        cout << "Base Salary  : $" << salary << endl;
        cout << "Sign-On Bonus: $" << salary << endl;
        cout << "Stock Option : $" << salary << endl;
        cout << "Incentives   : $" << salary << endl;
    }
};

//Benefit Class
class Benefits{
    private:
        string healthInsurance;
        string retirementPlan;

};

//Position Class
class Position{
    private:
        string title;
        string jobDescription;
};

//Department Class
class Department{
    private:
        int departmentID;
        string departmentName;
        string departmentDescription;
        vector<Employee> empolyees;
};

//Payroll Class
class Payroll{
    private:
};

//Project Class
class Projects{
    private:
        int projectID;
        string projectDescription;
};


#endif //EMPLOYEEMANAGMENTSYSTEM_CLASSFILES_H
