#include<iostream>
#include<limits>
#include<iomanip>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int application(string,string,string,string,string,int,int,double,double,double);
int calculateAutoLoan(int choice);
int calculateMortgage(int choice);
int calculatePersonalLoan(int choice);
int calculateDebtRefinance(int choice);

int main() {

    //Variables
    string firstName, lastName, Address, city, state;
    int creditScore{0}, zip{0};
    double yearlyIncome{0}, debtToIncome{0}, timeOnJob{0};
    application(firstName,lastName,Address,city,state,creditScore,zip,yearlyIncome,debtToIncome, timeOnJob);

    cout << "This application will allow you to see if you qualify for the following: " << endl;
    cout << "1. Auto Loan " << endl;
    cout << "2. Mortgage Loan " << endl;
    cout << "3. Personal Loan " << endl;
    cout << "4. Auto Loan " << endl;
    cout << endl;
    int choice{0};
    cout << "Select an option from our menu!" << endl;
    cin >> choice;
    while(choice<=0||choice>4){
        cout << "Please re-enter a number between 1-4" << endl;
        cin >> choice;
    }

    switch(choice) {
        case 1: {
            //Menu Display
            cout << "Auto Loan Calculator" << endl;
            cout << "\nProcess to obtain an auto loan will follow as so: " << endl;
            cout << "1. Credit Check" << endl;
            cout << "2. Debt to income ratio" << endl;
            cout << "3. Calculate Monthly Payments" << endl;
            cout << "4. Drive Away!" << endl;
            cout << endl;

            //Variables
            int creditScore{};
            double montlyIncome{};
            string firstName;
            string lastName;

            //Get user information
            cout << "We will begin the application, please fill out the following information: " << endl;
            cout << endl;
            cout << "Enter Last Name, First" << endl;
            cin >> lastName >> firstName;
            cout << "Enter Monthly Income after tax" << endl;
            cin >> montlyIncome;
            cout << "Enter your Credit Score" << endl;
            cin >> creditScore;
            cout << endl;

            //Validate Information
            bool correct = false;
            while(!correct){
                cout << "========Information=========" << endl;
                cout << "Last Name, First Name: "<< lastName << ", "<< firstName << endl;
                cout << "Monthly Income: " << montlyIncome << endl;
                cout << "Credit Score: " << creditScore << endl;
                cout << endl;
                cout << "Is all of the information above correct? (Y/N)" << endl;

                char confrim;
                cin >> confrim;

                if(confrim=='y'||confrim=='Y'){
                    correct = true;
                }else if (confrim == 'n'||confrim=='N'){
                    cout << "Please re-enter your information:" << endl;
                    cout << "Last Name: ";
                    cin >> lastName;
                    cout << "First Name: ";
                    cin >> firstName;
                    cout << "Monthly Income: ";
                    cin >> montlyIncome;
                    cout << "Credit Score: ";
                    cin >> creditScore;
                }else{
                    cout << "INVALID INFORMATION " << endl;
                }
            }

            //This Algorithm will calculate APR based on credit score
            cout << "\nWe will now conduct a credit check......." << endl;
            if(creditScore > 750) {
                cout << "Based on your Credit Score you qualify for 2.50% APR!" << endl;
                //Calculate loan amount based on debt to income ratio and yearly income
                if (montlyIncome > 8500) {
                    cout << "The maximum you can borrow is $65,000" << endl;
                    cout << "Out of the $65000, how much would you like to borrow?" << endl;
                    double loanAmount = 0;
                    cin >> loanAmount;

                    //Validate the loan amount entered by the user
                    while (loanAmount > 65000) {
                        cout << "Please Enter a loan amount less than $65000" << endl;
                        cin >> loanAmount;
                    }
                    //Variables
                    double apr = 0.025;
                    double ThirtySix = 36;
                    double fourtyEight = 48;
                    double sixty = 60;
                    double sevetyTwo = 72;
                    double r = apr / 12;

                    //Total Cost per month
                    double ThirtySixMonthlyPayment = {};
                    double fourtyEightMonthlyPayment = {};
                    double sixtySixMonthlyPayment = {};
                    double SeventyTwoMonthlyPayment = {};

                    //Calculate 36 month loan term
                    ThirtySixMonthlyPayment = (loanAmount * r * pow(1 + r, ThirtySix)) / (pow(1 + r, ThirtySix) - 1);
                    //Calculate 48 month loan term
                    fourtyEightMonthlyPayment =
                            (loanAmount * r * pow(1 + r, fourtyEight)) / (pow(1 + r, fourtyEight) - 1);
                    //Calculate 60 month loan term
                    sixtySixMonthlyPayment = (loanAmount * r * pow(1 + r, sixty)) / (pow(1 + r, sixty) - 1);
                    //Calculate 72 month loan term
                    SeventyTwoMonthlyPayment = (loanAmount * r * pow(1 + r, sevetyTwo)) / (pow(1 + r, sevetyTwo) - 1);

                    cout << "\nHere are your loan terms and monthly payments" << endl;
                    cout << "=============================================" << endl;
                    cout << "36 Month Loan Term: $" << ThirtySixMonthlyPayment << endl;
                    cout << "48 Month Loan Term: $" << fourtyEightMonthlyPayment << endl;
                    cout << "60 Month Loan Term: $" << sixtySixMonthlyPayment << endl;
                    cout << "72 Month Loan Term: $" << SeventyTwoMonthlyPayment << endl;

                } else if (montlyIncome > 6500 && montlyIncome < 8499){ //Income between 8499 - 6500
                    cout << "The maximum you can borrow is $55,000" << endl;
                    cout << "Out of the $5000, how much would you like to borrow?" << endl;
                    double loanAmount = 0;
                    cin >> loanAmount;

                    //Validate the loan amount entered by the user
                    while (loanAmount > 65000) {
                        cout << "Please Enter a loan amount less than $65000" << endl;
                        cin >> loanAmount;
                    }
                    //Variables
                    double apr = 0.025;
                    double ThirtySix = 36;
                    double fourtyEight = 48;
                    double sixty = 60;
                    double sevetyTwo = 72;
                    double r = apr / 12;

                    //Total Cost per month
                    double ThirtySixMonthlyPayment = {};
                    double fourtyEightMonthlyPayment = {};
                    double sixtySixMonthlyPayment = {};
                    double SeventyTwoMonthlyPayment = {};

                    //Calculate 36 month loan term
                    ThirtySixMonthlyPayment = (loanAmount * r * pow(1 + r, ThirtySix)) / (pow(1 + r, ThirtySix) - 1);
                    //Calculate 48 month loan term
                    fourtyEightMonthlyPayment =
                            (loanAmount * r * pow(1 + r, fourtyEight)) / (pow(1 + r, fourtyEight) - 1);
                    //Calculate 60 month loan term
                    sixtySixMonthlyPayment = (loanAmount * r * pow(1 + r, sixty)) / (pow(1 + r, sixty) - 1);
                    //Calculate 72 month loan term
                    SeventyTwoMonthlyPayment = (loanAmount * r * pow(1 + r, sevetyTwo)) / (pow(1 + r, sevetyTwo) - 1);

                    cout << "\nHere are your loan terms and monthly payments" << endl;
                    cout << "=============================================" << endl;
                    cout << "36 Month Loan Term: $" << ThirtySixMonthlyPayment << endl;
                    cout << "48 Month Loan Term: $" << fourtyEightMonthlyPayment << endl;
                    cout << "60 Month Loan Term: $" << sixtySixMonthlyPayment << endl;
                    cout << "72 Month Loan Term: $" << SeventyTwoMonthlyPayment << endl;

                }else if(montlyIncome > 5000  && montlyIncome < 6499){ //Income between 5000 - 6499
                    cout << "The maximum you can borrow is $45,000" << endl;
                }else if(montlyIncome > 3000  && montlyIncome < 4999){ //Income between 3000 - 4999
                    cout << "The maximum you can borrow is $35,000" << endl;
                }else if(montlyIncome > 2000  && montlyIncome < 2999){ //Income between 2000 - 2999
                    cout << "The maximum you can borrow is $25,000" << endl;
                }else if(montlyIncome < 1999){
                    cout << "The maximum you can borrow is " << endl;
                }
            //
            //
            //APR based on credit score
            //
            //
            }else if(creditScore > 720 && creditScore < 750){
                cout << "Based on your Credit Score you qualify for 4.50% APR!" << endl;
            }else if(creditScore > 690 && creditScore < 719){
                cout << "Based on your Credit Score you qualify for 5.50% APR!" << endl;
            }else if(creditScore > 650 && creditScore < 689){
                cout << "Based on your Credit Score you qualify for 6.50% APR!" << endl;
            }else if(creditScore < 650){
                cout << "Based on your Credit Score you DO NOT QUALIFY!" << endl;
            }
            else{
                cout << "INVALID DATA!" << endl;
            }
            break;
        }//End of case 1
        case 2: {
            cout << "You selected option 2" << endl;
            break;
        }
        case 3: {
            cout << "You selected option 3" << endl;
            break;
        }
        case 4: {
            cout << "You selected option 4" << endl;
            break;
        }



    }

    return 0;
}

int application(string firstName,string lastName,string Address,string city, string state,int zip,int creditScore,double yearlyIncome,double debtToIncome, double timeOnJob){
    //Validate Information
    bool correct = false;
    while (!correct) {
        cout << "Let's get some basic information for the application process." << endl;
        cout << "We will ask for the following information:" << endl;
        cout << "\n1. Personal Information" << endl;
        cout << "2. Credit Information" << endl;
        cout << "3. Time on Job" << endl;
        cout << "4. Debt to Income" << endl;
        cout << "5. Yearly Income After Tax" << endl;
        cout << endl;

        cout << "Let's begin filling out the Application." << endl;
        cout << "Enter Last, First Name: ";
        cin >> lastName >> firstName;
        cout << "Enter Address: ";
        cout << "Enter city" << endl;
        cin >> city;
        cout << "State and Zip Code: ";
        cin >> state >> zip;
        cout << "Enter Credit Score and Income (Yearly): ";
        cin >> creditScore >> yearlyIncome;
        cout << "Enter Debt to Income Ratio: ";
        cin >> debtToIncome;
        cout << "Time on job (Years): ";
        cin >> timeOnJob;
        cout << "Is all of the information above correct? (Y/N): ";

        char confirm;
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            correct = true;
        } else if (confirm == 'n' || confirm == 'N'){
            cout << endl;
            cout << "Please re-enter your information correctly!" << endl;
        }
    }
    cout << "Here is the information we have!" << endl;
    cout << "================================" << endl;
    cout << "First Name, Last Name: " << firstName << " " << lastName << endl;
    cout << "Address: " << Address << endl;
    cout << "Credit Score: " << creditScore << endl;
    cout << "Yearly Income: " << yearlyIncome << endl;
    cout << "Debt to Income: " << debtToIncome << endl;
    cout << "Time on job: " << timeOnJob << "Years" << endl;
}
int calculateAutoLoan(int choice){
    //Menu Display
    cout << "Auto Loan Calculator" << endl;
    cout << "\nProcess to obtain an auto loan will follow as so: " << endl;
    cout << "1. Credit Check" << endl;
    cout << "2. Debt to income ratio" << endl;
    cout << "3. Calculate Monthly Payments" << endl;
    cout << "4. Drive Away!" << endl;
    cout << endl;

    //Variables
    int creditScore{};
    double montlyIncome{};
    string firstName;
    string lastName;

    //Get user information
    cout << "We will begin the application, please fill out the following information: " << endl;
    cout << endl;
    cout << "Enter Last Name, First" << endl;
    cin >> lastName >> firstName;
    cout << "Enter Monthly Income after tax" << endl;
    cin >> montlyIncome;
    cout << "Enter your Credit Score" << endl;
    cin >> creditScore;
    cout << endl;

    //Validate Information
    bool correct = false;
    while(!correct){
        cout << "========Information=========" << endl;
        cout << "Last Name, First Name: "<< lastName << ", "<< firstName << endl;
        cout << "Monthly Income: " << montlyIncome << endl;
        cout << "Credit Score: " << creditScore << endl;
        cout << endl;
        cout << "Is all of the information above correct? (Y/N)" << endl;

        char confrim;
        cin >> confrim;

        if(confrim=='y'||confrim=='Y'){
            correct = true;
        }else if (confrim == 'n'||confrim=='N'){
            cout << "Please re-enter your information:" << endl;
            cout << "Last Name: ";
            cin >> lastName;
            cout << "First Name: ";
            cin >> firstName;
            cout << "Monthly Income: ";
            cin >> montlyIncome;
            cout << "Credit Score: ";
            cin >> creditScore;
        }else{
            cout << "INVALID INFORMATION " << endl;
        }
    }

    //This Algorithm will calculate APR based on credit score
    cout << "\nWe will now conduct a credit check......." << endl;
    if(creditScore > 750) {
        cout << "Based on your Credit Score you qualify for 2.50% APR!" << endl;
        //Calculate loan amount based on debt to income ratio and yearly income
        if (montlyIncome > 8500) {
            cout << "The maximum you can borrow is $65,000" << endl;
            cout << "Out of the $65000, how much would you like to borrow?" << endl;
            double loanAmount = 0;
            cin >> loanAmount;

            //Validate the loan amount entered by the user
            while (loanAmount > 65000) {
                cout << "Please Enter a loan amount less than $65000" << endl;
                cin >> loanAmount;
            }
            //Variables
            double apr = 0.025;
            double ThirtySix = 36;
            double fourtyEight = 48;
            double sixty = 60;
            double sevetyTwo = 72;
            double r = apr / 12;

            //Total Cost per month
            double ThirtySixMonthlyPayment = {};
            double fourtyEightMonthlyPayment = {};
            double sixtySixMonthlyPayment = {};
            double SeventyTwoMonthlyPayment = {};

            //Calculate 36 month loan term
            ThirtySixMonthlyPayment = (loanAmount * r * pow(1 + r, ThirtySix)) / (pow(1 + r, ThirtySix) - 1);
            //Calculate 48 month loan term
            fourtyEightMonthlyPayment =
                    (loanAmount * r * pow(1 + r, fourtyEight)) / (pow(1 + r, fourtyEight) - 1);
            //Calculate 60 month loan term
            sixtySixMonthlyPayment = (loanAmount * r * pow(1 + r, sixty)) / (pow(1 + r, sixty) - 1);
            //Calculate 72 month loan term
            SeventyTwoMonthlyPayment = (loanAmount * r * pow(1 + r, sevetyTwo)) / (pow(1 + r, sevetyTwo) - 1);

            cout << "\nHere are your loan terms and monthly payments" << endl;
            cout << "=============================================" << endl;
            cout << "36 Month Loan Term: $" << ThirtySixMonthlyPayment << endl;
            cout << "48 Month Loan Term: $" << fourtyEightMonthlyPayment << endl;
            cout << "60 Month Loan Term: $" << sixtySixMonthlyPayment << endl;
            cout << "72 Month Loan Term: $" << SeventyTwoMonthlyPayment << endl;

        } else if (montlyIncome > 6500 && montlyIncome < 8499){ //Income between 8499 - 6500
            cout << "The maximum you can borrow is $55,000" << endl;
            cout << "Out of the $5000, how much would you like to borrow?" << endl;
            double loanAmount = 0;
            cin >> loanAmount;

            //Validate the loan amount entered by the user
            while (loanAmount > 65000) {
                cout << "Please Enter a loan amount less than $65000" << endl;
                cin >> loanAmount;
            }
            //Variables
            double apr = 0.025;
            double ThirtySix = 36;
            double fourtyEight = 48;
            double sixty = 60;
            double sevetyTwo = 72;
            double r = apr / 12;

            //Total Cost per month
            double ThirtySixMonthlyPayment = {};
            double fourtyEightMonthlyPayment = {};
            double sixtySixMonthlyPayment = {};
            double SeventyTwoMonthlyPayment = {};

            //Calculate 36 month loan term
            ThirtySixMonthlyPayment = (loanAmount * r * pow(1 + r, ThirtySix)) / (pow(1 + r, ThirtySix) - 1);
            //Calculate 48 month loan term
            fourtyEightMonthlyPayment =
                    (loanAmount * r * pow(1 + r, fourtyEight)) / (pow(1 + r, fourtyEight) - 1);
            //Calculate 60 month loan term
            sixtySixMonthlyPayment = (loanAmount * r * pow(1 + r, sixty)) / (pow(1 + r, sixty) - 1);
            //Calculate 72 month loan term
            SeventyTwoMonthlyPayment = (loanAmount * r * pow(1 + r, sevetyTwo)) / (pow(1 + r, sevetyTwo) - 1);

            cout << "\nHere are your loan terms and monthly payments" << endl;
            cout << "=============================================" << endl;
            cout << "36 Month Loan Term: $" << ThirtySixMonthlyPayment << endl;
            cout << "48 Month Loan Term: $" << fourtyEightMonthlyPayment << endl;
            cout << "60 Month Loan Term: $" << sixtySixMonthlyPayment << endl;
            cout << "72 Month Loan Term: $" << SeventyTwoMonthlyPayment << endl;

        }else if(montlyIncome > 5000  && montlyIncome < 6499){ //Income between 5000 - 6499
            cout << "The maximum you can borrow is $45,000" << endl;
        }else if(montlyIncome > 3000  && montlyIncome < 4999){ //Income between 3000 - 4999
            cout << "The maximum you can borrow is $35,000" << endl;
        }else if(montlyIncome > 2000  && montlyIncome < 2999){ //Income between 2000 - 2999
            cout << "The maximum you can borrow is $25,000" << endl;
        }else if(montlyIncome < 1999){
            cout << "The maximum you can borrow is " << endl;
        }
        //
        //
        //APR based on credit score
        //
        //
    }else if(creditScore > 720 && creditScore < 750){
        cout << "Based on your Credit Score you qualify for 4.50% APR!" << endl;
    }else if(creditScore > 690 && creditScore < 719){
        cout << "Based on your Credit Score you qualify for 5.50% APR!" << endl;
    }else if(creditScore > 650 && creditScore < 689){
        cout << "Based on your Credit Score you qualify for 6.50% APR!" << endl;
    }else if(creditScore < 650){
        cout << "Based on your Credit Score you DO NOT QUALIFY!" << endl;
    }
    else{
        cout << "INVALID DATA!" << endl;
    }
}
