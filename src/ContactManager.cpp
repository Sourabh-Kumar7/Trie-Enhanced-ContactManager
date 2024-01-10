#include "ContactManager.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <json/json.h>  // Using JsonCpp library

ContactManager::ContactManager() {
    // Load contacts from the data file
    loadContactsFromFile("../data/contacts.json");
    // Optionally, initialize other components
}

ContactManager::~ContactManager() {
    // Save contacts to the data file upon destruction or exit
    // saveContactsToFile(contactTrie, "data/contacts.json");
    saveContactsToFile(contactTrie, contacts, "../data/contacts.json");

}

void ContactManager::run() {
    while (true) {
        std::cout << "FastContacts - Main Menu\n";
        std::cout << "1. Add a Contact\n";
        std::cout << "2. Search for a Contact\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                searchContact();
                break;

            case 3:
                std::cout << "Exiting FastContacts. Goodbye!\n";
                return;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }
}

void ContactManager::addContact() {
    std::string name, phoneNumber;
    std::cout << "Enter Contact Name: ";
    std::cin >> name;
    std::cout << "Enter Contact Phone Number: ";
    std::cin >> phoneNumber;

    Contact newContact(name, phoneNumber);

    // Add the contact to the trie and vector
    contacts.push_back(newContact);
    addContactToTrie(newContact);

    saveContactsToFile(contactTrie, contacts, "../data/contacts.json");
    std::cout << "Contact added successfully!\n";
}

void ContactManager::searchContact() {
    std::string searchQuery;
    std::cout << "Enter Search Query: ";
    std::cin >> searchQuery;

    std::vector<std::string> searchResults;
    bool found = contactTrie.search(searchQuery, searchResults);

    if (found) {
        std::cout << "Search Results:\n";
        for (const auto& result : searchResults) {
            std::cout << " - " << result << "\n";
        }
    } else {
        std::cout << "No contacts found with the given search query.\n";
    }
}


void ContactManager::loadContactsFromFile(const std::string& filename) {
    std::ifstream contactsFile(filename);
    if (contactsFile.is_open()) {
        Json::Value root;
        contactsFile >> root;

        const Json::Value& contactsArray = root["contacts"];
        for (const Json::Value& contactValue : contactsArray) {
            std::string name = contactValue["name"].asString();
            std::string phoneNumber = contactValue["phone"].asString();

            Contact contact(name, phoneNumber);
            contacts.push_back(contact);
            addContactToTrie(contact);
        }

        contactsFile.close();
    }
}

void ContactManager::addContactToTrie(const Contact& contact) {
    // Extract the name for simplicity, you can include more details if needed
    const std::string& name = contact.getName();
    const std::string& contactPhoneNumber = contact.getPhoneNumber();

    contactTrie.insert(name, contactPhoneNumber);
}
