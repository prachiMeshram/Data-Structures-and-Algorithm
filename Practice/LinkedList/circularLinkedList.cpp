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

void deleteNode (Node* &tail, int d) {
    // empty
    if (tail == NULL) {
        cout << "list is empty" << endl;
    }
    // only one 
    else if (tail -> next == tail) {
        tail -> next = NULL;
        delete (tail);
    }
    else {
        // two or more element 
        Node* prev = tail;
        Node* curr = prev -> next;
        
        while (curr -> data != d) {
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;

        if (tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }

}

int main () {
    Node* tail = NULL;

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 9, 6);
    print(tail);
    
    insertNode(tail, 6, 10);
    print(tail);

    insertNode(tail, 10, 4);
    print(tail);
    

    deleteNode(tail, 10);
    print(tail);

    deleteNode(tail, 4);
    print(tail);

    deleteNode(tail, 7);
    print(tail);


    return 0;
}