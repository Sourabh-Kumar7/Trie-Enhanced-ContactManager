#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include "Contact.h"
#include "Trie.h"

class ContactManager {
public:
    ContactManager();
    ~ContactManager();

    void run();
    void addContact();
    void searchContact();

private:
    Trie contactTrie;
    std::vector<Contact> contacts;

    // Additional private helper methods as needed
    void loadContactsFromFile(const std::string& filename);
    void addContactToTrie(const Contact& contact);
};

#endif
