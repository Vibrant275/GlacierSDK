#include "create.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "utils.h"

void createNewProject() {
    std::string appName;
    std::string packageName;
    std::vector<std::string> supportedPlatforms;
    std::string input;

    // Prompt for the app name
    std::cout << "Enter the name of your application: ";
    std::getline(std::cin, appName);
    if (appName.empty()) {
        displayError("Application name cannot be empty.\n");
        exit(EXIT_FAILURE); // Stop execution on error
    }

    // Prompt for the package name
    std::cout << "Enter the package name (e.g., com.example.myapp): ";
    std::getline(std::cin, packageName);
    if (packageName.empty()) {
        displayError("Package name cannot be empty.\n");
        exit(EXIT_FAILURE); // Stop execution on error
    }

    // Define available platforms
      std::vector<std::string> availablePlatforms = {"ios", "android", "linux", "windows", "macos"};

    std::cout << "Select supported platforms (type the number and press Enter, e.g., 1 2):\n";
    for (size_t i = 0; i < availablePlatforms.size(); ++i) {
        std::cout << "[" << (i + 1) << "] " << availablePlatforms[i] << "\n";
    }
    std::cout << "You can select multiple platforms by typing their numbers separated by spaces: ";

    // Get user input for platforms
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string platform;

    while (iss >> platform) {
        size_t index = std::stoul(platform) - 1;
        if (index < availablePlatforms.size()) {
            supportedPlatforms.push_back(availablePlatforms[index]);
        } else {
            displayError("Invalid platform selection: ");
        }
    }

    // Display selected options
    std::cout << "\nCreating a new project:\n";
    std::cout << "Application Name: " << appName << "\n";
    std::cout << "Package Name: " << packageName << "\n";
    std::cout << "Supported Platforms: ";

    if (supportedPlatforms.empty()) {
        std::cout << "None selected.";
    } else {
        for (const auto& platform : supportedPlatforms) {
            std::cout << platform << " ";
        }
    }
    std::cout << "\n";
}
