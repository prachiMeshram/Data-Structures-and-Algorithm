// https://www.codingninjas.com/studio/problems/maximum-xor_973113?utm_source=youtube&utm_medium=affiliate&utm_campaign=

#include<bits/stdc++.h>
using namespace std;

class Node {
    Node* links[2];

    public:
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void add(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    } 
};

class Tries {
    Node* root;

    public:
    Tries() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->add(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Tries trie;

    for (auto it: arr1) {
        trie.insert(it);
    } 
    int maxi = 0;
    for (auto it: arr2) {
        int maxNum = trie.getMax(it);
        maxi = max(maxi, maxNum);
    }

    return maxi;
}