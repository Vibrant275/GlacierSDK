#ifndef UTILS_H
#define UTILS_H

#include <string>

void handleUnknownCommand(const std::string& command);
void showHelp();
void displayError(const std::string& message);
void displayInfo(const std::string& message);

#endif
