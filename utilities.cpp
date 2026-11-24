#include "utilities.h"
#include <iostream>
#include <string>

/* Provides input validation for 
   the menu choice in main. */
int getIntegerInput(std::string prompt) {

    // Holds user input.
    int input;

    while (true) {

        // Display the prompt.
        std::cout << prompt;

        // If the input is successful,
        if (std::cin >> input) {

            // Send the input back out.
            std::cin.ignore(10000, '\n');
            return input;
        }

        // If it fails, display err.
        std::cout << "Invalid input. Please enter a number.\n";

        // Clear the input buffer.
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

/* Prints a bar of equal signs
   for formatting purposes. */
void printBar(int width) {

    std::cout << std::string(width, '=') << std::endl;
}

// Centers text within width characters.
void centerText(std::string text, int width) {

    // Calculate the padding. 
    int padding = (width - text.length()) / 2;

    // If the padding goes negative,
    if (padding < 0) {

        // Let it be zero.
        padding = 0;
    }

    // Print out the result: print the whitespace "padding" amount of times.
    std::cout << std::string(padding, ' ') << text << std::endl;
}

// Displays the main menu text.
void displayMenu() {

    // Print out menu options.
    std::cout << "1. Analyze Authentication Logs\n";
    std::cout << "2. View Project Information\n";
    std::cout << "3. Exit\n\n";
}

// Displays description of the program.
void sentinelDescription() {

    // Print out Sentinel information.
    std::cout << "SENTINEL analyzes authentication logs to identify suspicious login activity.\n";
    std::cout << "Created and maintained by Aidan Head.\n";
}