#ifndef LOG_PARSER_H
#define LOG_PARSER_H
#include <string>
#include <vector>

// Represents if the log passes authentication check.
enum class AuthStatus { FAILED, ACCEPTED };

// Holds each section of a typical sshd entry.
struct LogEntry {

    std::string timestamp;

    AuthStatus status;

    std::string username;

    std::string ipAddress;

    int port;
};

// Parses individual lines for each component of the log.
bool parseLine(const std::string& line, LogEntry& outEntry);

// Parses the entire log as a whole using parseLine.
std::vector<LogEntry> parseLogLines(const std::vector<std::string>& lines);

// Helper function to convert AuthStatus enum 
// to a string for main.
std::string statusToString(AuthStatus status);

// Helper function to test if IPv4 address
// formatting is correct and valid.
bool isValidIPv4(const std::string& ip);

// Helper function to test if port number
// is in valid range.
bool isValidPort(const std::string& port);

#endif