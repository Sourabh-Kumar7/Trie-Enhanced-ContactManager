#include "utils.h"
#include <fstream>
#include <iostream>

// Function to save contacts to a JSON file
void saveContactsToFile(const Trie& contactTrie, const std::vector<Contact>& contacts, const std::string& filename) {
    // Open the file for writing
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open " << filename << " for writing.\n";
        return;
    }

    // Create a Json::Value object to store the contacts
    Json::Value root;

    // Save contacts from the vector
    Json::Value contactsArray;
    for (const auto& contact : contacts) {
        Json::Value contactValue;
        contactValue["name"] = contact.getName();
        contactValue["phone"] = contact.getPhoneNumber();
        contactsArray.append(contactValue);
    }
    root["contacts"] = contactsArray;

    // Save contacts to the JSON file
    try {
        outFile << root;
        std::cout << "Contacts saved successfully to " << filename << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    outFile.close();
}

// Function to load contacts from a JSON file
void loadContactsFromFile(Trie& contactTrie, std::vector<Contact>& contacts, const std::string& filename) {
    // Open the file for reading
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open " << filename << " for reading.\n";
        return;
    }

    // Parse the JSON file
    Json::Value root;
    try {
        inFile >> root;

        // Check if the "contacts" field exists
        if (root.isMember("contacts") && root["contacts"].isArray()) {
            const Json::Value& contactsArray = root["contacts"];

            // Load contacts from the JSON file
            for (const Json::Value& contactValue : contactsArray) {
                std::string name = contactValue["name"].asString();
                std::string phoneNumber = contactValue["phone"].asString();

                Contact contact(name, phoneNumber);
                contacts.push_back(contact);
                contactTrie.insert(name, phoneNumber);
            }

            std::cout << "Contacts loaded successfully from " << filename << std::endl;
        } else {
            std::cerr << "Error: Invalid JSON format. Expected 'contacts' array.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    inFile.close();
}
