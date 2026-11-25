#include "log_reader.h"
#include <fstream>

// Checks if the log file is empty; returns bool.
bool isFileEmpty(std::ifstream& fileStream) {

    // Check the file for an end-of-file bit. If true, is empty.
    // if false, not empty. 
    return fileStream.peek() == std::ifstream::traits_type::eof();
}