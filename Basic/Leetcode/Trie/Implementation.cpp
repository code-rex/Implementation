// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];
    bool isEndOfWord;
    Trie() {
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
        this->isEndOfWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this; //this is root
        for (int i = 0; word[i]; i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == NULL) {
                cur->children[idx] = new Trie();
            } 
            cur = cur->children[idx];
        }
        cur->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for (int i = 0; word[i]; i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == NULL) 
                return false;
            else 
                cur = cur->children[idx];
        }
        return cur != NULL && cur->isEndOfWord == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int i = 0; prefix[i]; i++) {
            int idx = prefix[i] - 'a';
            if (cur->children[idx] == NULL) 
                return false;
            else 
                cur = cur->children[idx];
        }
        return true;
    }
};
