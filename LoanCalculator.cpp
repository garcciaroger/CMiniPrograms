#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

//Function Prototypes
double borrowAmount(double yearlyIncome,double &debtToIncome);
double loanAmountCalculator(double loanAmount, int creditScore, double yearlyIncome);
double debtToIncomeRatio(double yearlyIncome);
//Main function
int main() {
    //Variables
    string firstName;
    string lastName;
    string Address;
    string city;
    string state;
    int creditScore{0};
    int zip{0};
    int loanTerm{0};
    double yearlyIncome{0};
    double debtToIncome{0};
    double loanAmount{0};

    //Welcome Page
    cout << "Welcome to our loan calculator! In this application, we will " << endl;
    cout << "calculate the total cost to get a loan for a house, auto or " << endl;
    cout << "Personal loan! We will give a breakdown of total payment for " << endl;
    cout << "principle payment and total loan." << endl;
    cout << endl;
    cout << "Let's get some basic information for the application process." << endl;
    cout << "We will ask for the following information:" << endl;
    cout << "\n1. Personal Information" << endl;
    cout << "2. Credit Information" << endl;
    cout << "3. Time on Job" << endl;
    cout << "4. Debt to Income" << endl;
    cout << "5. Yearly Income After Tax" << endl;
    cout << endl;
    //Validate Information
    bool correct = false;
    while (!correct) {
        cout << "Let's begin filling out the Application." << endl;
        cout << "Enter Last, First Name: " << endl;
        cin >> lastName >> firstName;
        cin.ignore();
        cout << "Enter Address: " << endl;
        getline(cin, Address);
        cout << "Enter City " << endl;
        getline(cin, city);
        cout << "Enter State" << endl;
        cin >> state;
        cout << "Enter Zip Code" << endl;
        cin >> zip;
        cout << "Enter Credit Score " << endl;
        cin >> creditScore;
        cout << "Enter Yearly Income" << endl;
        cin >> yearlyIncome;

        cout << "Is all of the information above correct? (Y/N): " << endl;

        char confirm;
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            correct = true;
        } else if (confirm == 'n' || confirm == 'N') {
            cout << endl;
            cout << "Please re-enter your information correctly!" << endl;
        }
    }

    //Menu for loan options
    cout << "This application will allow you to see if you qualify for the following: " << endl;
    cout << "1. Auto Loan " << endl;
    cout << "2. Mortgage Loan " << endl;
    cout << "3. Personal Loan " << endl;
    cout << endl;
    int choice{0};
    cout << "Select an option from our menu!" << endl;
    cin >> choice;
    while (choice <= 0 || choice > 4) {
        cout << "Please re-enter a number between 1-4" << endl;
        cin >> choice;
    }

    switch (choice) {
        case 1: {
            //Menu Display
            cout << "Auto Loan Calculator" << endl;
            cout << "\nProcess to obtain an auto loan will follow as so: " << endl;
            cout << "1. Credit Check" << endl;
            cout << "2. Debt to income ratio" << endl;
            cout << "3. Calculate Monthly Payments" << endl;
            cout << "4. Drive Away!" << endl;
            cout << endl;

            cout << "We will go ahead now and fill out an application!" << endl;
            cout << "Please fill it out correctly!" << endl;

            cout << "Now that we have your application, we will calculate your debt to income ratio!" << endl;
            debtToIncomeRatio(yearlyIncome);

            cout << "Now we will see how much you can borrow!" << endl;
            borrowAmount(yearlyIncome, debtToIncome);

            cout << "We will now calculate your monthly payment!" << endl;
            loanAmountCalculator(loanAmount, creditScore, yearlyIncome);
            break;

        }
        case 2: {
            //Menu Display
            cout << "Mortgage Loan Calculator" << endl;
            cout << "\nProcess to obtain an auto loan will follow as so: " << endl;
            cout << "1. Credit Check" << endl;
            cout << "2. Debt to income ratio" << endl;
            cout << "3. Calculate Monthly Payments" << endl;
            cout << "4. Drive Away!" << endl;
            cout << endl;

            cout << "Now that we have your application, we will calculate your debt to income ratio!" << endl;
            debtToIncomeRatio(yearlyIncome);

            cout << "Now we will see how much you can borrow!" << endl;
            borrowAmount(yearlyIncome, debtToIncome);

            cout << "We will now calculate your monthly payment!" << endl;
            loanAmountCalculator(loanAmount, creditScore, yearlyIncome);
            break;
        }
        case 3: {
            //Menu Display
            cout << "Personal Loan Calculator" << endl;
            cout << "\nProcess to obtain an auto loan will follow as so: " << endl;
            cout << "1. Credit Check" << endl;
            cout << "2. Debt to income ratio" << endl;
            cout << "3. Calculate Monthly Payments" << endl;
            cout << "4. Drive Away!" << endl;
            cout << endl;

            cout << "Now that we have your application, we will calculate your debt to income ratio!" << endl;
            debtToIncomeRatio(yearlyIncome);

            cout << "Now we will see how much you can borrow!" << endl;
            borrowAmount(yearlyIncome, debtToIncome);

            cout << "We will now calculate your monthly payment!" << endl;
            loanAmountCalculator(loanAmount, creditScore, yearlyIncome);
            break;
        }
    }
    return 0;
}
/*
 *
 *  This function will calculate your debt to income ratio
 *
 */
double debtToIncomeRatio(double yearlyIncome){
    double monthlyIncome = yearlyIncome/12;
    double monthlyDebt;
    cout << "\nWe will calculate your debt to income ratio" << endl;
    cout << "Based on the information we have, your monthly income is " << monthlyIncome << endl;
    cout << endl;
    cout << "What is your monthly debt including mortgage/rent" << endl;
    cin >> monthlyDebt;

    //Calculate Debt to Income
    cout << setprecision(2);
    double debt_Income_Ratio = (monthlyDebt/monthlyIncome)*100;
    cout << "\nDebt to Income ratio is " << debt_Income_Ratio << endl;
    return debt_Income_Ratio;
}

/*
 *
 *  This function will calculate the total loan
 *  amount based on yearly income, debt to ratio
 *  and credit score
 *
 */
double borrowAmount(double yearlyIncome, double &debtToIncome) {
    double monthlyIncome = (yearlyIncome / 12);

    cout << "Monthly income is " << monthlyIncome;
    if (monthlyIncome > 8500) {
        double disposableIncome;
        double decimalValue = debtToIncome / 100;
        double loanAmount;

        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;
        return loanAmount;
    } else if (monthlyIncome <= 8499 && monthlyIncome >= 7000) {
        double disposableIncome;
        double decimalValue = debtToIncome / 100;
        double loanAmount;

        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;
        return loanAmount;
    } else if (monthlyIncome <= 6999 && monthlyIncome >= 5000) {
        double disposableIncome;
        double decimalValue = debtToIncome / 100;
        double loanAmount;

        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;
        return loanAmount;
    } else if (monthlyIncome <= 4999 && monthlyIncome >= 3000) {
        double disposableIncome;
        double decimalValue = debtToIncome / 100;
        double loanAmount;

        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;
        return loanAmount;
    } else if (monthlyIncome <= 2999 && monthlyIncome >= 2000) {
        double disposableIncome;
        double decimalValue = debtToIncome / 100;
        double loanAmount;

        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;
        return loanAmount;
    } else {
        cout << "Your income is too low for a loan!" << endl;
    }
}



double loanAmountCalculator(double loanAmount, int creditScore, double yearlyIncome){
    //Variable
    double monthlyPayment;
    monthlyPayment=yearlyIncome/12;
    int loanTerm;

    if (creditScore > 750) {
        double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};
        double apr = 0.015;
        double r = apr / 12;

        TwentyFour = (loanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (loanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (loanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (loanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (loanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        cout << "Congrats! Based on your credit score you qualify for 1.5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        cout << "How many months would you like to finance for? " << endl;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    } else if (creditScore <= 749 && creditScore >= 720) {
        double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};
        double apr = 0.025;
        double r = apr / 12;

        TwentyFour = (loanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (loanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (loanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (loanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (loanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        cout << "Congrats! Based on your credit score you qualify for 2.5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        cout << "How many months would you like to finance for? " << endl;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }

    } else if (creditScore <= 719 && creditScore >= 700) {
        double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};
        double apr = 0.035;
        double r = apr / 12;

        TwentyFour = (loanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (loanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (loanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (loanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (loanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        cout << "Congrats! Based on your credit score you qualify for 3.5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        cout << "How many months would you like to finance for? " << endl;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    } else if (creditScore <= 699 && creditScore >= 680) {
        double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};
        double apr = 0.05;
        double r = apr / 12;

        TwentyFour = (loanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (loanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (loanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (loanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (loanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        cout << "Congrats! Based on your credit score you qualify for 5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        cout << "How many months would you like to finance for? " << endl;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }

    } else if (creditScore <= 679 && creditScore >= 650) {
        double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};
        double apr = 0.075;
        double r = apr / 12;

        TwentyFour = (loanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (loanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (loanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (loanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (loanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        cout << "Congrats! Based on your credit score you qualify for 7.5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        cout << "How many months would you like to finance for? " << endl;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    } else {
        cout << "You do not qualify for a loan based on your credit score" << endl;
    }
}
