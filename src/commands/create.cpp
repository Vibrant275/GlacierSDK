#include "create.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "utils.h"
#include "../utils/AppConfig.cpp"

AppConfig config;

AppConfig getConfig() {
    AppConfig appConfig;

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
        for (const auto &platform: supportedPlatforms) {
            std::cout << platform << " ";
        }
    }
    std::cout << "\n";

    appConfig.appName = appName;
    appConfig.package = packageName;
    appConfig.platforms = supportedPlatforms;

    return appConfig;
}

AppConfig getConfigFromArguments(int argc, char *argv[]) {
    AppConfig config;
    std::vector<std::string> supportedPlatforms;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--name" && i + 1 < argc) {
            config.appName = argv[++i];
        } else if (arg == "--package" && i + 1 < argc) {
            config.package = argv[++i];
        } else if (arg == "--platforms" && i + 1 < argc) {
            ++i;
            while (i < argc && argv[i][0] != '-') {
                supportedPlatforms.push_back(argv[i]);
                ++i;
            }
            --i;
        } else {
            displayError("Unknown argument: " + arg);
            exit(EXIT_FAILURE);
        }
    }

    config.platforms = supportedPlatforms;
    return config;
}

void createNewProject() {
    config = getConfig();
    setupProject();
}

void createNewProjectFromConfig(int argc, char *argv[]) {
    config = getConfigFromArguments(argc, argv);
    setupProject();
}

void setupProject() {
    createGlobalConfigFile();

    for (const std::string& platform : config.platforms) {
        buildForPlatform(platform);
    }
}

void buildForPlatform(const std::string& platform) {
    if (platform == "windows") {
        buildForWindows();
    } else if (platform == "linux") {
        buildForLinux();
    } else if (platform == "macos") {
        buildForMacOS();
    } else {
        std::cerr << "Unsupported platform: " << platform << std::endl;
    }
}

void buildForMacOS() {

}

void buildForLinux() {

}

void buildForWindows() {
    std::string platformDirectory = "Windows";
    std::filesystem::create_directory(platformDirectory);

    std::cout << "Creating build structure for Windows..." << std::endl;

    // Create subdirectories
    std::filesystem::create_directory(platformDirectory + "/src");
    std::filesystem::create_directory(platformDirectory + "/include");
    std::filesystem::create_directory(platformDirectory + "/bin");
    std::filesystem::create_directory(platformDirectory + "/lib");

    std::ofstream cmakeFile(platformDirectory + "/CMakeLists.txt");
    if (cmakeFile.is_open()) {
        cmakeFile << "# CMake configuration for Prismio project on Windows\n";
        cmakeFile << "cmake_minimum_required(VERSION 3.14)\n";
        cmakeFile << "project(Prismio LANGUAGES CXX)\n\n";

        // Set binary name and flags
        cmakeFile << "set(BINARY_NAME \"" << config.appName << "\")\n";
        cmakeFile << "set(CMAKE_CXX_STANDARD 23)\n";
        cmakeFile << "add_definitions(-DUNICODE -D_UNICODE)\n\n";

        // Add source files
        cmakeFile << "file(GLOB_RECURSE SOURCES src/*.cpp)\n";
        cmakeFile << "add_executable(${BINARY_NAME} ${SOURCES})\n";

        // Add include directories
        cmakeFile << "target_include_directories(${BINARY_NAME} PRIVATE include)\n";

        // Install rules
        cmakeFile << "install(TARGETS ${BINARY_NAME} DESTINATION bin)\n";

        cmakeFile.close();
        std::cout << "CMakeLists.txt created successfully." << std::endl;
    } else {
        std::cerr << "Failed to create CMakeLists.txt." << std::endl;
    }

    std::cout << "Finished setting up build structure for Windows." << std::endl;
}

void createGlobalConfigFile() {
    std::ofstream configFile("config.toml");

    if (!configFile) {
        std::cerr << "Error: Unable to create config.toml file." << std::endl;
        return;
    }

    // Write application configuration to the file
    configFile << "# Application Configuration\n";
    configFile << "app_name = \"" << config.appName << "\"\n";
    configFile << "package = \"" << config.package << "\"\n";
    configFile << "platforms = [";

    for (size_t i = 0; i < config.platforms.size(); ++i) {
        configFile << "\"" << config.platforms[i] << "\"";
        if (i < config.platforms.size() - 1) {
            configFile << ", ";
        }
    }

    configFile << "]\n\n";

    // Add packages section
    configFile << "# List your project's packages or dependencies here\n";
    configFile << "[packages]\n";
    configFile << "# You can list your packages in the format: package_name = \"version\"\n";

    configFile.close();

    std::cout << "config.toml created successfully." << std::endl;
}
