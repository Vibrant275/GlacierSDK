#include "utils.h"
#include <iostream>

const std::string RED_COLOR = "\033[31m"; // Red text
const std::string RESET_COLOR = "\033[0m"; // Reset to default color

void handleUnknownCommand(const std::string& command) {
    std::cout << RED_COLOR
              << "Could not find a command named \"" << command << "\".\n"
              << "Run 'Glacier -h' for available Glacier commands and options."
              << RESET_COLOR << std::endl;
}

void showHelp() {
    std::cout << "Glacier Command-Line Interface\n";
    std::cout << "Usage: glacier <command> [options]\n";
    std::cout << "Available commands:\n";
    std::cout << "  create <output directory>   Create a new Glacier project\n";
    std::cout << "  run [options]               Run the Glacier application\n";
    std::cout << "  upgrade                      Upgrade the Glacier SDK\n";
    std::cout << "  downgrade                    Downgrade the Glacier SDK\n";
    std::cout << "  doctor                       Show information about the environment\n";
    std::cout << "  config                       Configure SDK settings\n";
    // Add more commands as needed
    std::cout << "For more help, use: glacier help <command>\n";
}


void displayError(const std::string& message) {
    std::cout << RED_COLOR
              << "Error: " << message << "\n"
              << RED_COLOR;
}

void displayInfo(const std::string& message) {
    std::cout << "\033[32m" // Green color for info messages
              << message << "\n"
              << "\033[0m"; // Reset color
}