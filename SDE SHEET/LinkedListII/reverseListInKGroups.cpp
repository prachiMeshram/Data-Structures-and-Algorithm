// https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan

#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};


Node* kReverse(Node* head, int k) {
    // Write your code here.

        int size = 0;
        Node* temp = head;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        if (size < k) {
            return head;
        }

        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;

        int count = 0;

        while (curr!=NULL && count < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL) head -> next = kReverse(curr, k);

        return prev;
}