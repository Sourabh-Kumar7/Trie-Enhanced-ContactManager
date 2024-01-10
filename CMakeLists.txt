cmake_minimum_required(VERSION 3.10)

project(FastContacts)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(FastContacts
    src/main.cpp
    src/Contact.cpp
    src/ContactManager.cpp
    src/Trie.cpp
    src/utils.cpp
)

# Add include directories
target_include_directories(FastContacts PRIVATE include)

# Specify the path to the JsonCpp library
target_include_directories(FastContacts PRIVATE /opt/homebrew/Cellar/jsoncpp/1.9.5/include)
target_link_directories(FastContacts PRIVATE /opt/homebrew/Cellar/jsoncpp/1.9.5/lib)
target_link_libraries(FastContacts PRIVATE jsoncpp)
