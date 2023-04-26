#include "iostream"
#include "iomanip"
#include "ClassFiles.h"
#include <fstream>
using namespace std;


int main(){
    //Company Information
    string name ="Lockheed Martin Corporation";
    string address = "999 Lockheed Blvd";
    string state  = "Fort Worth TX 76106";
    string missionStatement = "We solve complex challenges, advance scientific discovery and "
                              "deliver innovative solutions that help our customers keep people safe.";
    Company LockheedMartin(name, address, state, missionStatement);
    LockheedMartin.displayCompanyInformation();

    Employee newHire;
    newHire.getEmployeeInformation();
    newHire.displayEmployeeInformation();

    Salary newSalary;
    newSalary.getSalary();
    newSalary.displaySalary();



}
