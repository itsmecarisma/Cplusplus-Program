#Carisma Carter
#March 29, 2023

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

float initInv, monDep, AnuInt, months, years; // variables to store input
float totalAm, intAmt, yearTotInt; //variables to store year end total amount, year end interest, and interest


//present form to user
cout << "********************************\n";
cout << "********** Data Input **********\n";
cout << "Initial Investment Amount: \n";
cout << "Monthly Deposit: \n";
cout << "Annual Interest: \n";
cout << "Number of years: \n";


system("PAUSE"); //wait for user input

//gather data from user
cout << "********************************\n";
cout << "********** Data Input **********\n";
cout << "Initial Investment Amount: $";
cin >> initInv;
cout << "Monthly Deposit: $";
cin >> monDep;
cout << "Annual Interest: %";
cin >> AnuInt;
cout << "Number of years: ";
cin >> years;
months = years * 12;

system("PAUSE"); //wait for user input

totalAm = initInv; //update the total amount to initial investment

//display year data without monthly deposits
cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
cout << "==============================================================\n";
cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
cout << "--------------------------------------------------------------\n";


for (int i = 0; i < years; i++) {


intAmt = (totalAm) * ((AnuInt / 100)); //calculate the yearly interest

totalAm = totalAm + intAmt; //calculate the year end total


cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n"; // print the results in two decimal points

}


totalAm = initInv; //update the total amount to initial investment

//display the year data with monthly deposits
cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
cout << "==============================================================\n";
cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
cout << "--------------------------------------------------------------\n";

for (int i = 0; i < years; i++) {


yearTotInt = 0; //set the yearly interest to zero at the beginning of the year

for (int j = 0; j < 12; j++) {


intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12); //calculate monthly interest


yearTotInt = yearTotInt + intAmt; //calculate the month end interest


totalAm = totalAm + monDep + intAmt; //calculate the month end total

}

cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n"; // print the results in two decimal points


}

return 0;
}