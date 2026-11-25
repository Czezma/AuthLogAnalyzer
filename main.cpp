#include <iostream>
#include <fstream>
#include "utilities.h"
#include "log_reader.h"

int main() {

    // Holds user's
    // choice.
    int choice;

    do {

        std::ifstream logFile;
        std::string logFileName, item;

        // Display the program name.
        printBar(50);
        centerText("SENTINEL - Authentication Log Analyzer", 50);
        printBar(50);

        displayMenu();

        // Receive user input with built-in input validation.
        choice = getIntegerInput("Please enter a number from the menu choices.\n");

        // Menu choices:
        switch (choice) {

            case 1:

                // Prompt for file.
                std::cout << "\nPlease enter the log file's name: ";
                std::getline(std::cin, logFileName);

                logFile.open(logFileName);

                // If it fails,
                if (!logFile.is_open()) {

                    // Print err and break out.
                    std::cerr << "Log file failed to open. Please try again.\n";
                    break;
                } 

                // If the file is empty,
                if (isFileEmpty(logFile)) {

                    // Print err and break out.
                    std::cerr << "Log file is empty. Please try again.\n";
                    break;
                }

                // While the file is being 
                // read in line-by-line,
                while (std::getline(logFile, item)) {

                    // Print each item.
                    std::cout << item << "\n";
                }

                logFile.close();
                break;

            case 2:
                sentinelDescription();
                break;

            case 3:
                std::cout << "Exiting program...\n";
                break;
                

            default: 
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);


    return 0;
}