// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>
using namespace std;

class Node {
    Node* links[26];

    public: 

    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void add(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node* root = new Node();

    int count = 0;
    int n =s.size();

    for (int i = 0; i < n; i++) {
        Node* node = root;
        for (int j = i; j < n; j++) {
            if (!node->containsKey(s[j])) {
                count++;
                node->add(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    return count + 1;
}