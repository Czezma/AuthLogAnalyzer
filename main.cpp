#include <iostream>
#include "utilities.h"
using namespace std;

int main() {

    int choice;

    do {

        // Display the program name.
        printBar(50);
        cout << "\nSENTINEL - Authentication Log Analyzer\n";
        printBar(50);

        displayMenu();

        // Receive user input with built-in input validation.
        choice = getIntegerInput("Please enter a number from the menu choices.\n");

        // Menu choices:
        switch (choice) {

            case 1:
                cout << "Log analysis functionality coming soon.\n";
                break;

            case 2:
                sentinelDescription();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;
                

            default: 
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);


    return 0;
}