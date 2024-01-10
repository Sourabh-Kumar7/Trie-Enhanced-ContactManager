#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "Contact.h"
#include "Trie.h"
#include <json/json.h>

// Function to save contacts to a JSON file
void saveContactsToFile(const Trie& contactTrie, const std::vector<Contact>& contacts, const std::string& filename);

// Function to load contacts from a JSON file
void loadContactsFromFile(Trie& contactTrie, std::vector<Contact>& contacts, const std::string& filename);

#endif
