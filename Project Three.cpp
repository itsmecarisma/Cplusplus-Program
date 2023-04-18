#Carisma Carter
#April 11, 2023

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std; // included to make the name 

class ItemTracker {
public:
    void readDataFile();
    void displayMenu();
private:
    map<string, int> itemFrequency;
    void searchItem();
    void printFrequencyList();
    void printHistogram();
};

// reads data from input file and updates itemFrequency map
void ItemTracker::readDataFile() {
    ifstream dataFile("CS210_Project_Three_Input_File.txt"); // opens input file
    string item;
     ofstream output_file("frequency.dat"); // output file to store backup data
    while (dataFile >> item) { // read items from file 
        itemFrequency[item]++; // increases frequency of the item 
    }
    dataFile.close(); // closes input file
}

// displays the menu and handles user input
void ItemTracker::displayMenu() {
    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print the frequency list\n";
        cout << "3. Print a histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            searchItem(); // search for an item 
            break;
        case 2:
            printFrequencyList(); // print the frequency list of all items
            break;
        case 3:
            printHistogram(); // print the histogram of all items
            break;
        case 4:
            cout << "Exiting program...\n"; // exit the program
            break;
        default:
            cout << "Invalid choice. Try again.\n"; // prompt user to enter a valid choice
        }
    } while (choice != 4); // continue to display menu until user  exits
}

// prompts user to enter an item to search for, and displays its frequency if found
void ItemTracker::searchItem() {
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;
    if (itemFrequency.find(item) == itemFrequency.end()) { // check if item exists 
        cout << item << " not found.\n"; // item not found 
    } else {
        cout << "Frequency of " << item << " = " << itemFrequency[item] << endl; // display frequency of the item
    }
}

// prints the frequency list of all the items
void ItemTracker::printFrequencyList() {
    cout << "Frequency list:\n";
    for (auto const& item : itemFrequency) { // repreat through all items 
        cout << item.first << " " << item.second << endl; // display item and frequency
    }
}

// prints a histogram of all the items
void ItemTracker::printHistogram() {
    cout << "Histogram:\n";
    for (auto const& item : itemFrequency) { // repeat through all items 
        cout << item.first << " ";
        for (int i = 0; i < item.second; i++) { // display item and frequency as asterisks
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    ItemTracker itemTracker; // create instance of ItemTracker
    itemTracker.readDataFile(); // read data from input file 
    itemTracker.displayMenu(); // display menu and handle user input
    return 0; // exits the program
}