#include <iostream>
#include <string>
#include "../utils/utils.h"
#include "create.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        showHelp();
        return 1;
    }

    std::string command = argv[1];

    if (command == "help" || command == "-h" || command == "--help") {
        showHelp();
    } else if (command == "create") {

        if (argc < 3) {
            displayError("No application name specified. Please specify an app name.");
            std::cout << "\033[34m" // Blue color
                      << "Usage: glacier create <app-name>\n"
                      << "\033[0m"; // Reset color
            displayInfo("For more details, check the documentation at: <website-url>");
            return 1;
        }

          if (argc > 3) {
            displayError("Multiple output directories specified.");
            return 1;
        }

        std::string appName = argv[2];

        createNewProject();
    } else if (command == "run") {
        // Logic for running the project
    } else if (command == "upgrade") {
        // Logic for upgrading the SDK
    } else if (command == "doctor") {
        // Logic for showing environment info
    } else {
        handleUnknownCommand(command);
        return 1;
    }

    return 0;
}

