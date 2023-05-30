#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node() {
        int val = this -> data;
        if (next != NULL) {
            delete( next);
            this -> next = NULL;
        }
        cout << "memory is free for node with data : " << val << endl;
    }

};

// prints LL
void print (Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

// gives length of LL
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;

    while (temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

// INSERT HEAD
void insertAtHead (Node* &head, Node* &tail, int d) {

    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp; 
    }
}

// INSERT TAIL
void insertAtTail (Node* &head, Node* &tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition (Node* &head, Node* &tail, int d, int p) {
    // at first position
    if (p == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1; 

    while (count < p-1) {
        temp = temp -> next;
        count++;
    }

    // at last position 
    if (temp->next ==  NULL ) {
        insertAtTail(head, tail, d);
        return;
    }

    Node* insert = new Node(d);

    temp -> next -> prev = insert;
    insert -> next = temp -> next;
    temp -> next = insert;
    insert -> prev = temp;

}

void DeleteNode (Node* &head, Node* &tail, int p) {

    // deleting start node
    if ( p == 1) {
        Node* temp = head;

        temp -> next -> prev = NULL;
        head = temp -> next;
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
        prev -> next = NULL;
        tail = prev;
        curr -> prev = NULL;
        delete(curr);
        return;
    }
    
    curr -> prev = NULL;
    prev -> next = curr -> next;
    curr -> next -> prev = prev;
    curr -> next = NULL;
    delete(curr);
}

int main () {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, tail, 76);
    print(head);

    insertAtTail(head, tail, 978);
    print(head);

    insertAtPosition(head, tail, 7, 3);
    print(head);

    insertAtPosition(head, tail, 77, 5);
    print(head);

    insertAtPosition(head, tail, 60, 1);
    print(head);

    cout << "delete " << endl;
    DeleteNode(head, tail, 6);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "head : " << head -> prev << endl;
    cout << "tail : " << tail -> data << endl;
    cout << "tail : " << tail -> next << endl;

    return 0;
}