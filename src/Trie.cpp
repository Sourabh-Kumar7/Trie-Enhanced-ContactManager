#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    // Call a helper function to recursively delete nodes starting from the root
    deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* node) {
    if (!node) {
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            deleteTrie(node->children[i]);
        }
    }

    delete node;
}

Trie::TrieNode::TrieNode() {
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
    isEndOfWord = false;
}

void Trie::insert(const std::string& word, const std::string& phoneNumber) {
    TrieNode* current = root;

    for (char ch : word) {
        int index = ch - 'a';

        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = true;
    current->phoneNumber = phoneNumber;
}

bool Trie::search(const std::string& word, std::vector<std::string>& results) const {
    TrieNode* node = root;

    for (char ch : word) {
        int index = ch - 'a';

        if (!node->children[index]) {
            return false;  // Prefix not found, no words to retrieve
        }

        node = node->children[index];
    }

    // Start recursive retrieval from the node corresponding to the prefix
    findAllWordsWithPrefixRecursive(node, word, results);
    return !results.empty();  // Return true if results are not empty
}


bool Trie::searchRecursive(const TrieNode* node, const std::string& word, size_t index) const {
    if (index == word.size()) {
        return node && node->isEndOfWord;
    }

    int chIndex = word[index] - 'a';
    if (node->children[chIndex]) {
        return searchRecursive(node->children[chIndex], word, index + 1);
    }

    return false;
}

void Trie::findAllWordsWithPrefix(const std::string& prefix, std::vector<std::string>& results) const {
    TrieNode* node = root;

    for (char ch : prefix) {
        int index = ch - 'a';

        if (!node->children[index]) {
            return;  // Prefix not found, no words to retrieve
        }

        node = node->children[index];
    }

    // Start recursive retrieval from the node corresponding to the prefix
    findAllWordsWithPrefixRecursive(node, prefix, results);
}

void Trie::findAllWordsWithPrefixRecursive(const TrieNode* node, const std::string& currentPrefix, std::vector<std::string>& results) const {
    if (node->isEndOfWord) {
        results.push_back(currentPrefix + " " + node->phoneNumber);
    }

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char ch = 'a' + i;
            findAllWordsWithPrefixRecursive(node->children[i], currentPrefix + ch, results);
        }
    }
}
