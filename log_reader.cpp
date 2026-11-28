#include "log_reader.h"
#include <fstream>

// Takes in the file path and output lines, returns the Status enum.
ReadResult readLogFile(const std::string& filePath, std::vector<std::string>& outputLines) {

    // In case caller reuses
    // same vector.
    outputLines.clear();

    std::ifstream inputFile(filePath);
    std::string line;

    if (!inputFile) {

        return ReadResult::FAILED_TO_OPEN;
    }

    // Push back every line in the input file into the outputLines vector.
    while (std::getline(inputFile, line)) {
        outputLines.push_back(line);
    }

    if (outputLines.empty()) {

        return ReadResult::EMPTY_FILE;
    } else {
        return ReadResult::SUCCESS;
    }
}