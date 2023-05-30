#include <bits/stdc++.h>
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

Node* reverseKelems(Node* &head, int k) {
    // base case
    if (head == NULL) {
        return NULL;
    }

    // reverse first k nodes
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    int count = 0;

    while (curr!=NULL && count< k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // recursion
    if (next!=NULL) {
        head -> next = reverseKelems(curr, k);
    }
    return prev;
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

    Node* node1 = new Node(0);

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    

    for (int i = 1; i < 6 ; i++) {
        InsertAtHead(head, i);
        print(head);
    }

    cout << "reversed LL is : " << endl;
    // reverseLL(head)
    // reverseLLrecursion(head, head, NULL);
    Node* newhead = reverseKelems(head,3);
    print(newhead);


    return 0;
}