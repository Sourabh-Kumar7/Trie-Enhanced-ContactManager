#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber);
    Contact(const std::string& id, const std::string& name, const std::string& phoneNumber);

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getPhoneNumber() const;

    // Setters
    void setName(const std::string& name);
    void setPhoneNumber(const std::string& phoneNumber);

private:
    std::string id;
    std::string name;
    std::string phoneNumber;
};

#endif
