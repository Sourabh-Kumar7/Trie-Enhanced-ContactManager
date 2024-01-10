#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class Trie {
public:
    Trie();
    ~Trie();

    void insert(const std::string& word, const std::string& phoneNumber);
    // bool search(const std::string& word) const;
    bool search(const std::string& word, std::vector<std::string>& results) const;
    void findAllWordsWithPrefix(const std::string& prefix, std::vector<std::string>& results) const;

private:
    struct TrieNode {
        TrieNode* children[26];  // Assuming only lowercase alphabets
        bool isEndOfWord;
        std::string phoneNumber;

        TrieNode();
    };

    TrieNode* root;

    // Helper function for recursive word search
    bool searchRecursive(const TrieNode* node, const std::string& word, size_t index) const;

    // Helper function for recursive retrieval of all words with a given prefix
    void findAllWordsWithPrefixRecursive(const TrieNode* node, const std::string& prefix, std::vector<std::string>& results) const;
    void deleteTrie(TrieNode* node);
};

#endif
