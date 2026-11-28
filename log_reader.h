#ifndef LOG_READER_H
#define LOG_READER_H
#include <vector>
#include <string>

// Represents the result of a log file read attempt.
enum class ReadResult { SUCCESS, FAILED_TO_OPEN, EMPTY_FILE };

// Takes in the file path and output lines, returns the Status enum.
ReadResult readLogFile(const std::string& filePath, std::vector<std::string>& outputLines);

#endif 