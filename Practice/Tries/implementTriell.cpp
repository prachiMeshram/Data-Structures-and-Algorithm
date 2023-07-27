// https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h> 
using namespace std;

class Node {
    Node* links[26];
    int countEndWith = 0;
    int countPrefix = 0;

    public:

    bool isContains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void add(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    void increaseEnd() {
        countEndWith++;
    }
    void deleteEnd() {
        countEndWith--;
    }

    void increasePrefix() {
        countPrefix++;
    }
    void reducePrefix() {
        countPrefix--;
    }
    
    int getWordsEnd () {
        return countEndWith;
    }
    int getWordsStarting () {
        return countPrefix;
    }
   
};
class Trie{
    Node* root;
    public:

    Trie( ){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;

        for (auto it: word) {
            if(!node->isContains(it)) {
                node->add(it, new Node());
            }
            node = node->get(it);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;

        for (auto it: word) {
            if(node->isContains(it)) {
                node = node->get(it);
            }
            else {
                return 0;
            }
        }

        return node->getWordsEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;

        for (auto it: word) {
            if(!node->isContains(it)) {
                return 0;
            }
            node = node->get(it);
        }

        return node->getWordsStarting();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;

        for (auto it: word) {
            if(!node->isContains(it)) {
                return;
            }
            node = node->get(it);
            node->reducePrefix();
        }

        node->deleteEnd();
    }
};
