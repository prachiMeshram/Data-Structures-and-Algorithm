// https://www.codingninjas.com/studio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>
using namespace std;

class Node {
    Node* links[26];
    bool flag = false;

    public:

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL; 
    }

    void put (char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:

    Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;

        for (auto it: word) {
            if (!node->containsKey(it)) {
                node->put(it, new Node());
            }
            node = node->get(it);
        }

        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;

        for (auto it: word) {
            if (!node->containsKey(it)) {
                return false;
            }
            node = node->get(it);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;

        for (auto it: prefix) {
            if (!node->containsKey(it)) {
                return false;
            }
            node = node->get(it);
        }

        return true;
    }
};