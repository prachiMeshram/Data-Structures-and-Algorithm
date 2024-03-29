// https://www.codingninjas.com/studio/problems/800332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

    // Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if (first == NULL) return second;
    if (second == NULL) return first;
    
    if (first->data > second->data) {
        Node<int> *temp = first;
        first = second;
        second = temp;
    }
    
    Node<int>* res = first;
    
    while (first != NULL && second != NULL) {
        Node<int>* temp = NULL;
        while (first != NULL && first->data <= second->data) {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        Node<int> *t = first;
        first = second;
        second = t;
    }

    return res;
}
