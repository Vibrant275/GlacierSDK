#ifndef GLACIER_CREATE_H
#define GLACIER_CREATE_H

#include <string>

void createNewProject();
void createNewProjectFromConfig(int argc, char* argv[]);
void setupProject();

void createGlobalConfigFile();

void buildForPlatform(const std::string& platform);

void buildForWindows();

void buildForLinux();

void buildForMacOS();

#endif