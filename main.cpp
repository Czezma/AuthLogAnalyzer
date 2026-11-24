#include <iostream>
#include <fstream>
#include "utilities.h"
#include "log_reader.h"
using namespace std;

int main() {

    // Holds user's
    // choice.
    int choice;

    do {

        ifstream logFile;
        string logFileName, item;

        // Display the program name.
        printBar(50);
        centerText("SENTINEL - Authentication Log Analyzer\n", 50);
        printBar(50);

        displayMenu();

        // Receive user input with built-in input validation.
        choice = getIntegerInput("Please enter a number from the menu choices.\n");

        // Menu choices:
        switch (choice) {

            case 1:

                // Prompt for file.
                cout << "\nPlease enter the log file's name: ";
                cin >> logFileName;

                // Open input stream with the
                // file name.
                logFile.open(logFileName);

                // If it fails,
                if (!logFile.is_open()) {

                    // Print err and exit program early.
                    cerr << "Log file failed to open. Please try again.\n";
                    return -1;
                } 

                // If the file is empty,
                if (isFileEmpty(logFileName)) {

                    // Print err and exit program early.
                    cerr << "Log file is empty. Please try again.\n";
                    return -1;
                };

                // While the file is being 
                // read in line-by-line,
                while (getline(logFile, item)) {

                    // Print each item.
                    cout << item << "\n";
                }

                // Close the file.
                logFile.close();
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