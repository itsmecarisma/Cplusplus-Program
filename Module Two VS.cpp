/*
 * Calculator.cpp
 *
 *  Date: [March 10, 2023]
 *  Author: [Carisma Carter]
 */

#include <iostream>

using namespace std; // included to make the name 

void main()
{
	char statement[100];
	int op1, op2; //both variables are declared as double
	char operation; //this variable will store operator
	char answer=='Y' //character variables are in single quotes
	while (answer=='y') // changes the while statement for capital and lower case y
	{
		cout << "Enter expression" << endl; // spacing
		cin >> op2 >> operation >> op1; //take the input
		if (operation == '+'); //brackets for if statements and character variables are in single quotes
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // changed >> to << 
		else if (operation == '-'); //changed if statement to else-if statement
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; //chnaged >> to <<
		else if (operation == '*'); // changed if statement to else-if statement
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // added semicolon and changed '*' to match output
		else if (operation == '/'); //added semicolon and changed if statement to else-if
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //changed '/' to match output

		cout << "Do you wish to evaluate another expression? " << endl; //asks user if they wish to continue the program 
		cin >> answer; //store user answer

        if ( answer =='N')
        while (answer == 'n') 
        {
            cout << "Program Finished" << endl; //when user wants to exit the program 

    }
    return 0;
	}
