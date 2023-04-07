#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

void Application(string *fullName, string *streetAddress, string *city, string *state, int *zipCode, int *creditScore, double *income);
double borrowAmount(double, double*);
double calculateAutoLoan(int creditScore, double totalAmountBorrowed);

int main(){
    //Declaring Variables
    string fullName, streetAddress, city, state;
    int zipCode, creditScore;
    double income, debtToIncomeRatio, totalAmountBorrowed, monthlyIncome, debt, monthlyPayment;

    //Intro to the program
    cout << "Hello! This application will allow you to see if you " << endl;
    cout << "qualify for loans and see how much you can borrow!" << endl;
    cout << "\nLets fill out the application first!" << endl;
    Application(&fullName, &streetAddress, &city, &state, &zipCode, &creditScore, &income);
    //Calculating monthly income
    monthlyIncome = (income/12);
    //Debt to Income Calculation
    debtToIncomeRatio = (debt/monthlyIncome)*100;
    cout << "What is your monthly debt including rent/mortgage?" << endl;
    cin >> debt;

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

    //Option Menu
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
            totalAmountBorrowed = borrowAmount(monthlyIncome, &debtToIncomeRatio);
            calculateAutoLoan(creditScore,totalAmountBorrowed);
            break;

        }
    }



}

void Application(string *fullName, string *streetAddress, string *city, string *state, int *zipCode, int *creditScore, double *income){
    cout << "We will now fill out the application for a loan" << endl;
    cout << "Please make sure to fill it out correctly" << endl;

    bool correct=false;
    while(!correct) {
        cout << "Enter Full Name: " << endl;
        getline(cin, *fullName);
        cout << "Enter Street Address: " << endl;
        getline(cin, *streetAddress);
        cout << "Enter City" << endl;
        getline(cin, *city);
        cout << "Enter State" << endl;
        getline(cin, *state);
        cout << "Enter Zip Code" << endl;
        cin >> *zipCode;
        cout << "Enter Credit Score" << endl;
        cin >> *creditScore;
        cout << "Enter your income(Yearly)" << endl;
        cin >> *income;
        cin.ignore();

        cout << "\nThis is the following information we have" << endl;
        cout << "=========================================" << endl;
        cout << "Full Name - " << *fullName << endl;
        cout << "Street Address - " << *streetAddress << endl;
        cout <<  *city << " " << *state  << " " << *zipCode << endl;
        cout << "Income - " << *income << endl;
        cout << "Credit Score - " << *creditScore << endl;

        cout << "\nIs the information above correct? (Yes/Y or No/n)" << endl;
        char confirm;
        cin >> confirm;
        cin.ignore();

        if ( confirm == 'y' ||  confirm == 'Y') {
            correct = true;
        } else if (confirm == 'n' || confirm == 'N') {
            cout << endl;
            cout << "Please enter the information correctly again!" << endl;
        }
    }

}

double borrowAmount(double monthlyIncome, double *debtToIncomeRatio){
    if (monthlyIncome > 8500) {
        double disposableIncome;
        double decimalValue = *debtToIncomeRatio / 100;
        double loanAmount;
        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;

        return loanAmount;

    } else if (monthlyIncome <= 8499 && monthlyIncome >= 7000) {
        double disposableIncome;
        double decimalValue = *debtToIncomeRatio / 100;
        double loanAmount;
        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;

        return loanAmount;

    } else if (monthlyIncome <= 6999 && monthlyIncome >= 5000) {
        double disposableIncome;
        double decimalValue = *debtToIncomeRatio / 100;
        double loanAmount;
        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;

        return loanAmount;

    } else if (monthlyIncome <= 4999 && monthlyIncome >= 3000) {
        double disposableIncome;
        double decimalValue = *debtToIncomeRatio / 100;
        double loanAmount;
        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;

        return loanAmount;

    } else if (monthlyIncome <= 2999 && monthlyIncome >= 2000) {
        double disposableIncome;
        double decimalValue = *debtToIncomeRatio / 100;
        double loanAmount;
        disposableIncome = monthlyIncome * (1 - decimalValue);
        loanAmount = disposableIncome * 15;

        return loanAmount;

    } else {
        cout << "Your income is too low for a loan!" << endl;
    }
}

double calculateAutoLoan(int creditScore, double totalAmountBorrowed){
    //Ask user how much they would like to borrow
    cout << "your total loan amount is $"<< totalAmountBorrowed<< endl;
    cout << "How much would you like to borrow of that amount? " << endl;
    int userLoanAmount;
    cin >> userLoanAmount;
    //Validate user amount is within range
    while(userLoanAmount <= 2500 || userLoanAmount > totalAmountBorrowed){
        cout << "Please enter a valid loan amount between $2500 and " << totalAmountBorrowed << endl;
        cin >> userLoanAmount;
    }
    cout << "Total loan amount is $" << userLoanAmount << endl;
    //Variables to Calculate loan amount
    double TwentyFour{0}, thirtySix{0}, fourtyEight{0}, sixty{0}, seventyTwo{0};

    //Begin Calculating Based on credit score
    if(creditScore >= 750){
        cout << "Congrats! Based on your credit score you qualify for 1.50% APR!" << endl;
        double apr = 0.015;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

        //Display Menu Options
        cout << "Congrats! Based on your credit score you qualify for 1.5% APR!" << endl;
        cout << "\nHere are your loan term Length Options: " << endl;
        cout << "======================================= " << endl;
        cout << "24 Months: $" << TwentyFour << endl;
        cout << "36 Months: $" << thirtySix << endl;
        cout << "48 Months: $" << fourtyEight<< endl;
        cout << "60 Months: $" << sixty <<endl;
        cout << "72 Months: $" << seventyTwo <<endl;
        cout << endl;

        //Finance Term
        cout << "How many months would you like to finance for? " << endl;
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
        //Finance BreakDown
        switch (loanTerm) {
            case 24:{
                //Variables
                int intrest {0};
                intrest = userLoanAmount *(apr/12)*24;

                cout << "Here is a breakdown  of the 24 month loan term!" << endl;
                cout << "Base Price: $" << userLoanAmount << endl;
                cout << "APR: 1.5%" << endl;
                cout << "Intrest Cost: $" << intrest << endl;
                cout << "Total Cost: $" << userLoanAmount + intrest << endl;
                cout << "Monthly Payment: $" << TwentyFour << endl;
                cout << endl;

                // Calculate the total cost of the car loan
                double total_paid = 0;
                double remaining_balance = userLoanAmount;
                for (int month = 1; month <= 24; month++) {
                    // Calculate principal payment for the month
                    double principal_payment = TwentyFour;
                    total_paid += TwentyFour;

                    // Calculate remaining balance after the payment
                    remaining_balance -= principal_payment;

                    // Output the results for the month
                    cout << "Month " << month << ": Payment: $" << fixed << setprecision(2) << TwentyFour
                         << ", Principal: $" << principal_payment << ", Balance: $" << remaining_balance << endl;

                    // Check if the car loan has been fully paid off
                    if (remaining_balance <= 0) {
                        total_paid += remaining_balance + principal_payment;
                        break;
                    }
                }
                break;
            }
            case 36:{
                //Variables
                int intrest {0};
                intrest = userLoanAmount *(apr/12)*36;

                cout << "Here is a breakdown  of the 36 month loan term!" << endl;
                cout << "Base Price: $" << userLoanAmount << endl;
                cout << "APR: 1.5%" << endl;
                cout << "Intrest Cost: $" << intrest << endl;
                cout << "Total Cost: $" << userLoanAmount + intrest << endl;
                cout << "Monthly Payment: $" <<   thirtySix << endl;
                cout << endl;
            }
            case 48:{
                //Variables
                int intrest {0};
                intrest = userLoanAmount *(apr/12)*48;

                cout << "Here is a breakdown  of the 48 month loan term!" << endl;
                cout << "Base Price: $" << userLoanAmount << endl;
                cout << "APR: 1.5%" << endl;
                cout << "Intrest Cost: $" << intrest << endl;
                cout << "Total Cost: $" << userLoanAmount + intrest << endl;
                cout << "Monthly Payment: $" << fourtyEight << endl;
                cout << endl;

            }
            case 60:{
                //Variables
                int intrest {0};
                intrest = userLoanAmount *(apr/12)*60;

                cout << "Here is a breakdown  of the 60 month loan term!" << endl;
                cout << "Base Price: $" << userLoanAmount << endl;
                cout << "APR: 1.5%" << endl;
                cout << "Intrest Cost: $" << intrest << endl;
                cout << "Total Cost: $" << userLoanAmount + intrest << endl;
                cout << "Monthly Payment: $" << sixty << endl;
                cout << endl;

            }
            case 72:{
                //Variables
                int intrest {0};
                intrest = userLoanAmount *(apr/12)*72;

                cout << "Here is a breakdown  of the 72 month loan term!" << endl;
                cout << "Base Price: $" << userLoanAmount << endl;
                cout << "APR: 1.5%" << endl;
                cout << "Intrest Cost: $" << intrest << endl;
                cout << "Total Cost: $" << userLoanAmount + intrest << endl;
                cout << "Monthly Payment: $" << seventyTwo << endl;
                cout << endl;

            }
        }

    }
    else if(creditScore <= 749 && creditScore >= 720){
        cout << "Congrats! Based on your credit score you qualify for 2.75% APR!" << endl;

        double apr = 0.275;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

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
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }

    }
    else if(creditScore <= 719 && creditScore >= 700){
        cout << "Congrats! Based on your credit score you qualify for 3.50% APR!" << endl;

        double apr = 0.350;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

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
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    }
    else if(creditScore <= 699 && creditScore >= 680){
        cout << "Congrats! Based on your credit score you qualify for 4.50% APR!" << endl;

        double apr = 0.450;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

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
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    }
    else if(creditScore <= 680 && creditScore >= 650){
        cout << "Congrats! Based on your credit score you qualify for 6.50% APR!" << endl;

        double apr = 0.650;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

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
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    }
    else if(creditScore <= 649 && creditScore >= 630){
        cout << "Congrats! Based on your credit score you qualify for 10.50% APR!" << endl;

        double apr = 0.1050;
        double r = apr / 12;

        //Calculate Total monthly Payment
        TwentyFour = (userLoanAmount * r * pow(1 + r, 24)) / (pow(1 + r, 24) - 1);
        thirtySix = (userLoanAmount * r * pow(1 + r, 36)) / (pow(1 + r, 36) - 1);
        fourtyEight = (userLoanAmount * r * pow(1 + r, 48)) / (pow(1 + r, 48) - 1);
        sixty = (userLoanAmount * r * pow(1 + r, 60)) / (pow(1 + r, 60) - 1);
        seventyTwo = (userLoanAmount * r * pow(1 + r, 72)) / (pow(1 + r, 72) - 1);

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
        int loanTerm;
        cin >> loanTerm;
        while(loanTerm!=24 && loanTerm!=36 && loanTerm!=48 && loanTerm!=60 && loanTerm !=72){
            cout << "Please enter a valid term length!" << endl;
            cin >> loanTerm;
        }
    }
    else {
        cout << "INVALID DATA" << endl;
    }

}
