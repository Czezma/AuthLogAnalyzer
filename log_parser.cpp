#include <exception>
#include "log_parser.h"
#include <sstream>

// Parses individual lines for each component of the log.
bool parseLine(const std::string& line, LogEntry& outEntry) {

    /*------------------------------*/
    /* FAILED/ACCEPTED PREFIX CHECK */
    /*------------------------------*/

    const std::string failedPrefix = "Failed password for ";

    const std::string acceptedPrefix = "Accepted password for ";

    // Timestamps are always 15 characters.
    if (line.size() < 15) { return false; }

    outEntry.timestamp = line.substr(0, 15);

    // pos: Find where the text starts, and set
    // it's position to it.
    size_t pos = line.find(failedPrefix);

    // If we found the start,
    if (pos != std::string::npos) { 

        // Make the status reflect the failure state.
        outEntry.status = AuthStatus::FAILED;

        // Move position to the end
        // of the failed passwd prefix.
        pos += failedPrefix.size();
    } 

    else if ((pos = line.find(acceptedPrefix)) != std::string::npos) {

        // Make the status reflect the accepted state.
        outEntry.status = AuthStatus::ACCEPTED;

        // Move position to the end
        // of the accepted passwd prefix.
        pos += acceptedPrefix.size();
    } else { 

        // If neither is valid.
        return false; 
    }

    /*--------------------------------------------------------------------------------------*/
    /* INVALID USER PREFIX CHECK (Optional: not mandatory to appear in log text to be valid)*/
    /*--------------------------------------------------------------------------------------*/

    const std::string invalidPrefix = "invalid user ";

    // If the invalidprefix appears at pos,
    if (line.find(invalidPrefix, pos) == pos) {

        // Move pos forward to the end
        // of invalid prefix.
        pos += invalidPrefix.size();
    }

    /*--------------------------------*/
    /* "FROM" MARKER / USERNAME CHECK */
    /*--------------------------------*/

    const std::string fromMarker = " from ";

    size_t fromPos = line.find(fromMarker, pos);

    if (fromPos == std::string::npos || fromPos == pos) {

        // Not valid if 
        // the from marker 
        // isn't present.
        return false;
    }

    // Extracting username from the line.
    // Username is in between current pos (end of for) and fromPos lengths.
    outEntry.username = line.substr(pos, fromPos - pos);

    // Jump pos to right after marker.
    pos = fromPos + fromMarker.size();
    
    /*----------------------------------*/
    /* "PORT" MARKER / IP ADDRESS CHECK */
    /*----------------------------------*/

    const std::string portMarker = " port ";

    size_t portPos = line.find(portMarker, pos);

    if (portPos == std::string::npos || portPos == pos) { return false; }

    // Extracting IP address from the line.
    // IP address is in between current pos and portPos lengths.
    outEntry.ipAddress = line.substr(pos, portPos - pos);

    // Test if it is a valid IPv4 address.
    if (!isValidIPv4(outEntry.ipAddress)) { return false; }

    // Jump pos to right after marker.
    pos = portPos + portMarker.size();
    
    /* SSHD MARKER CHECK / PORT NUM CHECK */

    std::string portStr; 

    size_t spacePos = line.find(' ', pos);

    // If whitespace not found,
    if (spacePos == std::string::npos) {

        // Grab the rest of the line.
        portStr = line.substr(pos);
    } else {

        // Grab just the port.
        portStr = line.substr(pos, spacePos - pos);
    }

    // Make sure it is a valid port number.
    if (!isValidPort(portStr)) { return false; }

    try {
    // Convert port num
    // to an integer and assign it
    // to the port variable.
    outEntry.port = std::stoi(portStr);
    }

    // In case port num is malformed,
    catch (const std::exception&) {
        return false;
    }

    // Line passed all checks.
    return true;
}

std::vector<LogEntry> parseLogLines(const std::vector<std::string>& lines) {

    // Holds valid entries that pass 
    // parseLine.
    std::vector<LogEntry> validEntries;

    // For every line,
    for (const std::string& line : lines) {

        LogEntry entry;

        // Let parseLine check 
        // each line one-by-one.
        // If the line passes,
        if (parseLine(line, entry)) {

            // Push the line into the valid 
            // entries vector.
            validEntries.push_back(entry);
        }
    }

    // Send the valid entries back
    // to caller.
    return validEntries;
}

// Helper function to convert AuthStatus enum 
// to a string for main.
std::string statusToString(AuthStatus status) {

    if (status == AuthStatus::ACCEPTED) {
        return "ACCEPTED";
    } else {
        return "FAILED";
    } 
}

bool isValidIPv4(const std::string& ip) {

    // Check for immediate disqualifiers.
    if (ip.empty() || ip.back() == '.') { return false; }

    std::stringstream ss(ip);
    std::string part;

    // To track if 4 octets are reached.
    int octetCount = 0;

    while (std::getline(ss, part, '.')) {
        
        // Ensure the octet is only 1-3 digits long per octet.
        if (part.empty() || part.size() > 3) { return false; }

        // Ensure the octet is only digits.
        for (char c : part) {
            
            if (c < '0' || c > '9') { return false; }
        }

        // If octet is bigger than 2^8 - 1,
        if (std::stoi(part) > 255) { return false; }

        // Increment octet and move to the next.
        octetCount++;
    }

    // To prove if ip is standard octet count.
    return octetCount == 4;
}


// Helper function to test if port number
// is in valid range.
bool isValidPort(const std::string& port) {

    // Cannot be empty nor have more than 5 digits.
    if (port.empty() || port.size() > 5) { return false; }

    // Ensure the port num is only digits.
    for (char p : port) {

        if (p < '0' || p > '9') { return false; }
    }

    int portNum = std::stoi(port);

    // Must be within range.
    return portNum >= 1 && portNum <= 65535;
}