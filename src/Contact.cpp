#include "Contact.h"
#include <fstream>
#include <iostream>
#include <json/json.h>  // Using JsonCpp library

Contact::Contact(const std::string& name, const std::string& phoneNumber)
    : name(name), phoneNumber(phoneNumber) {
    // Load the last used ID from config.json
    std::ifstream configFile("../config/config.json");

    if (configFile.is_open()) {
        Json::Value root;
        configFile >> root;

        if (!root["lastUsedId"].isNull()) {
            int oldId = root["lastUsedId"].asInt();
            id = "C" + std::to_string(++oldId);
        } else {
            // If lastUsedId is not present, generate a new ID
            static int counter = 100;  // Start from 100 if not found
            id = "C" + std::to_string(counter++);
        }

        configFile.close();
    } else {
        // If config.json is not present, generate a new ID
        static int counter = 100;  // Start from 100 if not found
        id = "C" + std::to_string(counter++);
    }

    // Increment the last used ID and save it back to config.json
    std::ofstream configFileOut("../config/config.json");

    if (configFileOut.is_open()) {
        Json::Value root;
        root["lastUsedId"] = std::stoi(id.substr(1));;  // Extract the numeric part
        configFileOut << root;
        configFileOut.close();
    } else {
        // Handle the case where config.json cannot be written
        std::cerr << "Error: Unable to write to config.json\n";
    }
}

// Constructor for creating a contact with a specified ID
Contact::Contact(const std::string& id, const std::string& name, const std::string& phoneNumber)
    : id(id), name(name), phoneNumber(phoneNumber) {
    // You can optionally perform validation or additional logic here
}

// Getters
std::string Contact::getId() const {
    return id;
}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

// Setters
void Contact::setName(const std::string& newName) {
    name = newName;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}
