#include <iostream>
#include <string>
#include "utils.h"
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

        if (argc > 2) {
            displayError("Unknown option specified with create.");
            return 1;
        }

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

