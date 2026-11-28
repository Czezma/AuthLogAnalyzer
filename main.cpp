#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "log_reader.h"

int main() {

    // Holds user's
    // choice.
    int choice;

    do {
        std::string logFileName;

        // Display the program name.
        printBar(50);
        centerText("SENTINEL - Authentication Log Analyzer", 50);
        printBar(50);

        displayMenu();

        // Receive user input with built-in input validation.
        choice = getIntegerInput("Please enter a number from the menu choices.\n");

        // Menu choices:
        switch (choice) {

            case 1: {

                // Prompt for file.
                std::cout << "\nPlease enter the log file's name: ";
                std::getline(std::cin, logFileName);

                std::vector<std::string> logLines;

                ReadResult fileReadResult = readLogFile(logFileName, logLines);

                switch (fileReadResult) {

                    case ReadResult::FAILED_TO_OPEN: 
                        std::cout << "The log file failed to open. Please try again.\n";
                        break;

                    case ReadResult::EMPTY_FILE:
                        std::cout << "The log file is empty. Please populate the file with log information and try again.\n";
                        break;

                    case ReadResult::SUCCESS: 
                        for (const std::string& line : logLines) {
                            std::cout << line << "\n";
                        }
                        break;
                }
                break;
            }
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