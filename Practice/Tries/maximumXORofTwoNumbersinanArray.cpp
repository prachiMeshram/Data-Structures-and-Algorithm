// https://www.codingninjas.com/studio/problems/maximum-xor_3119012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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
int maximumXor(vector<int> A)
{
    // Write your code here.  
    Tries trie;

    trie.insert(A[0]);

    int maxi = 0;
    int maxNum = 0;
    
    for (int i = 1; i < A.size(); i++) {
        maxNum = trie.getMax(A[i]);
        maxi = max(maxi, maxNum);
        trie.insert(A[i]);
    }

    return maxi;
}