#ifndef LOG_READER_H
#define LOG_READER_H
#include <fstream>

// Checks if the log file is empty or not;
// returns boolean value.
bool isFileEmpty(std::ifstream& fileStream);
#endif 