# CMakeList.txt : CMake project for StudioWeaveServer, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif ()

project("Glacier")

# Add subdirectories for modularity
add_subdirectory(utils)
add_subdirectory(src/commands)

# Add source to this project's executable.
add_executable(
        Glacier
        src/main.cpp
        src/commands/create.cpp
        src/main.cpp
        include/create.h
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Glacier PROPERTY CXX_STANDARD 20)
endif ()


find_package(fmt CONFIG REQUIRED)
#  find_package(OpenSSL CONFIG REQUIRED)
#  find_package(libpqxx CONFIG REQUIRED)
#  find_package(Boost REQUIRED COMPONENTS system filesystem)
#  find_package(nlohmann_json CONFIG REQUIRED)


if (MINGW)
    link_libraries(ws2_32 wsock32)
endif ()

target_link_libraries(Glacier
        #    Boost::system
        #    Boost::filesystem
        fmt::fmt
        utils
        commands
        #    OpenSSL::SSL
        #    OpenSSL::Crypto
        #    libpqxx::pqxx
        #    nlohmann_json::nlohmann_json
)
