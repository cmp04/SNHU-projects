/*
 * Calculator.cpp
 *
 *  Date: [3/13/26]
 *  Author: [Celeste Pauna]
 */

#include <iostream>

using namespace std;

//return int
int main()
{
	int op1, op2;
	char operation;
    //fixed using double qoutes for a char variable and no semicolin
	string answer = "y";
    //check if answer is lowercase y
	while (answer == "y")
	{
		cout << "Enter expression" <<endl;
        //op1 and op2 were swapped on input
		cin >> op1 >> operation >> op2;
        //again double quotes were used for char and no brackets were used for any of the if statements
        //there were also some mix ups with cin and cout using the wrong symbols and wrong math opperations too
		if (operation == '+') {
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }
        //changed to else if to make sure only one brach executes
		else if (operation == '-') {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }
		else if (operation == '*') {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }
		else if (operation == '/') {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
        }
		else {
			cout << "Invalid opperation" << endl;
		}

		cout << "Do you wish to evaluate another expression? " << endl;
		cout << "Type y or n: " << endl;
		cin >> answer;
		while ((answer != "y") && (answer != "n")) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "You must enter lowercase y or n: " << endl;
			cout << "Try again: " << endl;
			cin >> answer;
		}
	}
    //if answer not Y or y loop exits and prints message
    cout << "Program Finished." << endl;
}