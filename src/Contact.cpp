#include "Contact.h"
#include <fstream>
#include <iostream>
#include <json/json.h>  // Using JsonCpp library

Contact::Contact(const std::string& name, const std::string& phoneNumber)
    : name(name), phoneNumber(phoneNumber) {
    // You can optionally perform validation or additional logic here
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
