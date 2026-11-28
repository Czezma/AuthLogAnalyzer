# Sentinel - Authentication Log Analyzer

Sentinel is a command-line application written in C++ designed to analyze Linux authentication logs and identify potentially suspicious login activity.

This project is being developed as a personal cybersecurity and programming project to strengthen my C++ skills while exploring security monitoring, log analysis, and threat detection.

## Sample Log File

Sentinel includes `auth_sample.log`, a sample Linux authentication log containing simulated login activity. This file is for testing and demonstration purposes. 

The sample data is fabricated and does not contain real authentication records.

## Planned Features

- [x] Interactive command-line menu
- [x] Input validation
- [x] Modular function organization
- [x] Authentication log file reading
- [x] Log entry parsing
- [ ] Failed login tracking
- [ ] IP-based login attempt analysis
- [ ] Brute-force activity detection
- [ ] Security report generation

## Technologies

- C++
- Git
- Linux authentication logs

## Project Status

Sentinel is currently under development. Features will be added incrementally as the project progresses.

## Purpose

The goal of Sentinel is to build a practical understanding of C++ programming and the fundamentals of security monitoring through the development of a functional command-line security utility.

## Build & Run

Compile with `g++` (C++17 or newer):

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o sentinel
```

Run the program:

```bash
./sentinel
```

*(On Windows PowerShell, run `.\sentinel.exe`.)* 
