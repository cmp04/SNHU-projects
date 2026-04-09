//Celeste Pauna
#include <iostream>
#include <iomanip>
using namespace std;

//declare variables
double initial_investment;
double monthly_deposit;
int num_years;
double interest_rate;
double interest_amount;
double total_amount;
bool input_invalid = true;
int i;
int j;

//Print the welcome and start message to user
void PrintWelcome() {
    char decor = '*';
    int length = 32;

    for (i = 0; i < length; ++i) {
        cout << decor;
    }
    cout << endl;
    cout << "********** DATA INPUT *********" << endl;
}

//Calculate the interest with no extra monthly deposits
void Calc_NoMonthly() {
    cout << endl;
    cout << "BALANCE AND INTEREST WITHOUT MONTHLY DEPOSITS" << endl;
    cout << "==============================================" << endl;
    cout << "YEAR       YEAR END BALANCE        YEAR END INTEREST" << endl;
    cout << "----------------------------------------------------" << endl;
    total_amount = initial_investment;
    for (i = 0; i < num_years; ++i) {
       double yearlyTotalInterest = 0.00;
       for (j = 0; j < 12; ++j) {
        interest_amount = (total_amount) * ((interest_rate/100.00)/12.00);
        yearlyTotalInterest = yearlyTotalInterest + interest_amount;
        total_amount = total_amount + interest_amount;
       }
    cout << i+1 << "|"<< "\t    " << fixed << setprecision(2) << "$" << total_amount << "\t     " << "$" << yearlyTotalInterest << endl;
    }
    cout << endl;
}

//Calculate the interest with the user defined monthly deposits
void Calc_MonthlyDeoposit() {
    cout << endl;
    cout << "BALANCE AND INTEREST WITH MONTHLY DEPOSITS" << endl;
    cout << "==============================================" << endl;
    cout << "YEAR       YEAR END BALANCE        YEAR END INTEREST" << endl;
    cout << "----------------------------------------------------" << endl;
    total_amount = initial_investment;
    for (i = 0; i < num_years; ++i) {
       double yearlyTotalInterest = 0.00;
       for (j = 0; j < 12; ++j) {
        interest_amount = (total_amount+ monthly_deposit) * ((interest_rate/100.00)/12.00);
        yearlyTotalInterest = yearlyTotalInterest + interest_amount;
        total_amount = total_amount + interest_amount + monthly_deposit;
       }
       cout << i+1 << "|" << "\t    " << fixed << setprecision(2) << "$" << total_amount << "\t     " << "$" << yearlyTotalInterest << endl;
    }
    cout << endl;
}

//Main, get user inputs
int main() {
    
    PrintWelcome();

    //while the users input is invalid, not an integer
    while (input_invalid) {
        cout << "Initial Investment Amount: "; 
        cin >> initial_investment;
        if (!cin) {
            cout << "You must enter a number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            PrintWelcome();
            continue;
        }
        cout << "Monthly Deposit: ";
        cin >> monthly_deposit;
        if (!cin) {
            cout << "You must enter a number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            PrintWelcome();
            continue;
        }
        cout << "Annual Interest: ";
        cin >> interest_rate;
        if (!cin) {
            cout << "You must enter a number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            PrintWelcome();
            continue;
        }
        cout << "Number of years: ";
        cin >> num_years;
        if (!cin) {
            cout << "You must enter a number" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            PrintWelcome();
            continue;
        }
        input_invalid = false;
    }
    Calc_NoMonthly();
    Calc_MonthlyDeoposit();
}

