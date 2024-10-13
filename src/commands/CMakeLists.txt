# Add the lexer source files
file(GLOB_RECURSE COMMANDS_SOURCES "*.cpp")

# Add the lexer library
add_library(commands ${COMMANDS_SOURCES})

# Include directories for lexer
target_include_directories(commands PUBLIC ${CMAKE_SOURCE_DIR}/include)
