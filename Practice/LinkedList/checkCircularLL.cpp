#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node (int d) {
        this -> data = d;
        this -> next = NULL;
    }

    ~Node () {
        int value = this -> data;
        if (next != NULL) {
            delete(next);
            next = NULL;
        }
        cout << "memory is free for node with data : " << value << endl;
    }
};

void insertNode (Node* &tail, int elem, int d) {
    
    if (tail == NULL) {
        // empty
        Node* newNode = new Node (d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else {
        // non-empty

        Node* temp = tail;

        while (temp->data != elem) {
            temp = temp -> next;
        }

        Node* newNode = new Node (d);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

bool isCircular (Node* &head) {
    if (head == NULL) {
        return true;
    }
    
    Node* temp = head -> next;

    while (temp != NULL && temp != head) {
        temp = temp -> next;
    } 

    if (temp == NULL) {
        return false;
    }
    else if (temp == head) {
        return true;
    }
}

void print (Node* &tail) {
    Node* temp = tail;

    // empty check
    if (tail == NULL) {
        cout << "list is empty" << endl;
        return;
    }

    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while (temp != tail);

    cout << endl;
}

int main () {
    Node* tail = NULL;

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 9, 6);
    // print(tail);
    
    // insertNode(tail, 6, 10);
    // print(tail);

    // insertNode(tail, 10, 4);
    // print(tail);
    
    if (isCircular(tail)) {
        cout << "Linked List is circular" << endl;
    }
    else {
        cout << "linked list is not circular" << endl;
    }

    return 0;
}