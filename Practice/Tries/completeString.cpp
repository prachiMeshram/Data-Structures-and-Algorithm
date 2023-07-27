// https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h> 
using namespace std;

class Node {
    Node* links[26];
    bool flag = false;

    public:
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    } 
};
class Trie {
    Node* root;

    public:
    Trie() {
        root = new Node();
    }

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
    bool checkIfAllPrefixExist(string word) {
        Node* node = root;
        bool flag = true;
        for (auto it: word) {
            if(node->containsKey(it)) {
                node = node->get(it);
                flag = flag & node->isEnd();
            }
            else {
                return false;
            }
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* obj = new Trie();

    for (auto it: a) {
        obj->insert(it);
    }

    string longest = "";

    for (auto it: a) {
        if (obj->checkIfAllPrefixExist(it)) {
            if (it.size() > longest.size()) {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest) {
                longest = it;
            }
        }
    }

    if (longest == "") return "None";

    return longest;
}