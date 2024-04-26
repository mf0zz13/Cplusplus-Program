#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#include "month.h"

// function to display start menu
void dataInputMenu(double& t_initalInvestment, double& t_monthlyDeposit, double& t_annualIntrest, int& t_numYears) { // ref vars so function can update the starting values
    bool t_contine = false; // bool value to enable exit of loop

    while (!t_contine) { // while loop to enable input validation 
        cout << "********************************" << endl;
        cout << "********** Data Input **********" << endl;
        cout << "Initial Investment Amount: ";
        cin >> t_initalInvestment; // getting inital investment value
        if (!(t_initalInvestment >= 0)) { // validating input
            cout << "invalid input\n" << endl;
            continue;
        }
        cout << "Monthly Deposit: ";
        cin >> t_monthlyDeposit; // getting monthly deposite
        if (!(t_monthlyDeposit >= 0)) { // validating input
            cout << "invalid input\n" << endl;
            continue;
        }
        cout << "Annual Intrest: ";
        cin >> t_annualIntrest; // getting annual intrest rate
        if (!(t_annualIntrest >= 0)) { // validating input
            cout << "invalid input\n" << endl;
            continue;
        }
        cout << "Number of Years: ";
        cin >> t_numYears; // getting number of years
        if (!(t_numYears > 0)) { // validating input
            cout << "invalid input\n" << endl;
            continue;
        }

        system("pause"); // have user acknoldge they are ready to contine
        t_contine = true; // exiting loop since all inputs are valid and user is ready to continue
    }
}

// function to convert the years into months
int monthsToYears(int t_numYears) { // fuction is passed number of years from main

    return t_numYears * 12; // calculate and return the number of months for amount of years
}

// function to calculate the parameters for all months
void monthlyCalculations(vector<month>& t_monthsToCalculatemonthList, double t_initalInvestment, double t_monthlyDepoist, double t_annualIntrest, int t_totalmonths) {// ref object vector and getting the inital inputs to caluate objects values
    
    month t_currMonth; // object that allows iteration in order to create all objects
    double t_currOpeningAmount; // var to hold the opening amount for each object
    double t_currOpeningAmountWithDeposit; // var to hold the opening amount with deposit for each object

    t_currOpeningAmount = t_initalInvestment; // var assigned the opening value for first object
    t_currOpeningAmountWithDeposit = t_initalInvestment; // var assigned the opening value with deposit for first object
    
    // for loop to assign all other values for object and add object to vector list
    for (int i = 0; i < t_totalmonths; ++i) {
        t_currMonth.setOpeningAmount(t_currOpeningAmount); // setting opening amount to curr object
        t_currMonth.setOpeningAmountWithDeposit(t_currOpeningAmountWithDeposit); // setting the opening amount with deposit to curr object
        t_currMonth.setMonthlyDeposit(t_monthlyDepoist); // setting monthly deposit value to curr object
        t_currMonth.setAnnualIntrestRate(t_annualIntrest); // setting annual intrest rate to curr onject
        t_currMonth.setSumOpeningAndDeposit(t_currMonth.getOpeningAmountWithDeposit() + t_currMonth.getMonthlyDeposit()); // calculating the sum of the opening amount and deposit amount and assignig it to object
        
        /* calcuating and setting intrest acrued to curr object
        calcuation: (opening amount) * ((intrest rate / 100) / 12)*/
        t_currMonth.setIntrestAcrued(t_currMonth.getOpeningAmount() * ((t_currMonth.getAnnualIntrestRate() / 100) / 12));

        /* calcuating and setting intrest acrued to curr object
        calcuation: (opening amount + deposit amount) * ((intrest rate / 100) / 12)*/
        t_currMonth.setIntrestAcruedWithDeposit(t_currMonth.getSumOpeningAndDeposit() * ((t_currMonth.getAnnualIntrestRate() / 100) / 12));

        /* calcuating and setting closing balance to curr object
        calcuation: opening amount + intest acrued*/
        t_currMonth.setClosingBalance(t_currOpeningAmount + t_currMonth.getIntrestAcrued());

        /* calcuating and setting closing balance with deposit to curr object
        calcuation: (opening amount + deposit amount) + intrest acrued with deposit*/
        t_currMonth.setClosingBalanceWithDeposit(t_currMonth.getSumOpeningAndDeposit() + t_currMonth.getIntrestAcruedWithDeposit());
        t_currMonth.setMonthNumber(i + 1);

        t_monthsToCalculatemonthList.push_back(t_currMonth); // adding current month to the vector

        t_currOpeningAmount = t_monthsToCalculatemonthList.at(i).getClosingBalance(); // setting the opening amount for the next object
        t_currOpeningAmountWithDeposit = t_monthsToCalculatemonthList.at(i).getClosingBalanceWithDeposit(); // setting the opening amount with depoist for the next object
    }
}

// output results to user
void outputResults(vector<month>& t_months) { // ref vector holding objects

    int t_startPoint = 0; // int allow iteration for calcuations

    // outputting header for output display
    cout << "|    Balance and Interest Without Additonal Monthly Deposits     |      Balance and Interest With Additional Monthly Deposits     |" << endl;
    cout << "|----------------------------------------------------------------|----------------------------------------------------------------|" << endl;
    cout << "|        Year     |  Year End Balance  | Year End Earned Intrest |        Year     |  Year End Balance  | Year End Earned Intrest |" << endl;

    // for loop to iterate through each year to get closing balances for each year
    for (unsigned int i = 11; i < t_months.size(); i += 12) { // loop iterates 12 at a time to allow selection of correct object in list
        
        double t_yearlyIntrest = 0.0; // var to hold how much intrest was generated over the year
        double t_yearlyIntrestWithDeposit = 0.0; // var to hold how much intrest was generated over the year with deposits

        for (int j = t_startPoint; j <= i; ++j) { // for loop to iterate through intrest rates for each year
            t_yearlyIntrest += t_months.at(j).getIntrestAcrued();
            t_yearlyIntrestWithDeposit += t_months.at(j).getIntrestAcruedWithDeposit();
        }    
        t_startPoint += 12;
        
        // outputting values for each year
        cout << "|" << setw(17) << left << ((i + 1) / 12);
        cout << "|" << setw(20) << right << fixed << setprecision(2) << t_months.at(i).getClosingBalance();
        cout << "|" << setw(25) << right << fixed << setprecision(2) << t_yearlyIntrest;
        cout << "|" << setw(17) << left << ((i + 1) / 12);
        cout << "|" << setw(20) << right << fixed << setprecision(2) << t_months.at(i).getClosingBalanceWithDeposit();
        cout << "|" << setw(25) << right << fixed << setprecision(2) << t_yearlyIntrestWithDeposit << "|";
        cout << endl;
    }
}

int main() {
    double initalInvestment; // inital investment
    double monthlyDepoist; // montly depoist
    double annualIntrest; // annual intrest rate
    int numYears; // number of years being calculated
    int months; // number of months
    bool quit = false; // bool to hold condition for the loop that allows exit
    char userInput = ' '; // char to hold user input

    while (!quit) { // loop that will keep program executing until user exits

        vector <month> monthList; // vector to hold each month
        bool exit = false; // bool to hold conditon for the loop that validate input for exit
        
        dataInputMenu(initalInvestment, monthlyDepoist, annualIntrest, numYears); // calling function to display inital menu and get inital inputs from user

        months = monthsToYears(numYears); // calling function to calcuate how many months will be created

        monthlyCalculations(monthList, initalInvestment, monthlyDepoist, annualIntrest, months); // calling function to create all months

        outputResults(monthList); // calling fucntion to output the results calcuated from users inputs

        // finding out if user will continue program or end it
        cout << "\n\nWould you like to preform a new calulation (Y/N)" << endl;
        cin >> userInput;

        // while loop to validate input
        while (!exit) {
            
            if (userInput == 'n' || userInput == 'N') { // if input is N or n conditions are set to end execution of program          
                cout << "Goodbye" << endl;
                quit = true;
                exit = true;
            }
            else if (userInput == 'y' || userInput == 'Y') { // if input is Y or y condtions are set to exit input valiation and allow the program to continue
                exit = true;
                
            }
            else { // if input is not Y, y, N, or n the the user is requested to try again
                cout << "Invalid input plesase try again" << endl;
                cin >> userInput;
            }
        }
    }

    return 0;
}