#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        // free memory
        if (this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data : " << value << endl;
    }
};

void InsertAtHead (Node* &head, int d) {
    // create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail (Node* &tail, int d) {
    // create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtPosition (Node* &head, Node* &tail, int p, int d) {

    // insert at start
    if (p == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < p-1) {
        temp = temp -> next;
        count++;
    }

    // insert at last
    if (temp -> next == NULL) {
        InsertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}

void DeleteNode (Node* &head, Node* &tail, int p) {

    // deleting start node
    if ( p == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp; // free the memory of start node
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while (count < p) {
        prev = curr;
        curr = curr -> next;
        count++;
    }

    // deleting last node
    if (curr -> next == NULL) {
        prev -> next = curr -> next;
        tail = prev;
        delete(curr);
        return;
    }
    
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete(curr);
}

void print(Node* &head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main () {

    Node* node1 = new Node(10);
    // cout << node1 -> data << " ";
    // cout << node1 -> next << " ";

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertAtHead(head, 12);

    print(head);

    InsertAtTail(tail, 13);
    print(head);

    InsertAtPosition(head, tail, 3, 44);
    InsertAtPosition(head, tail, 5, 94);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    DeleteNode(head, tail, 3);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    DeleteNode(head, tail, 4);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    return 0;
}