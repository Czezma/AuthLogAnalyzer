#include "log_reader.h"
#include <fstream>

// Checks if the log file is empty; returns bool.
bool isFileEmpty(const std::string& filename) {

    // Assign the file to the input stream.
    std::ifstream filetoCheck(filename);

    // Check the file for an end-of-file bit. If true, is empty.
    // if false, not empty. 
    return filetoCheck.peek() == std::ifstream::traits_type::eof();
}