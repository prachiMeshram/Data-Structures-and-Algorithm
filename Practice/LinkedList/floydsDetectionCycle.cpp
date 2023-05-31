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

void print(Node* &head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

bool detectLoop (Node* &head) {
    
    if (head == NULL) {
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != NULL) {
        if (visited[temp] == true) {
            cout << "present on element " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;

    }

    return false;
}

Node* floydDetect (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartNode (Node* head) {
    Node* intersection = floydDetect(head);
    Node* slow = head;
    Node* fast = intersection;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node* head) {

    Node* startNode = getStartNode(head);
    Node* temp = startNode;

    while (temp->next != startNode) {
        temp = temp->next;
    }

    temp->next = NULL;
    cout << "loop removed" << endl;
}


int main () {

    Node* node1 = new Node(10);
    // cout << node1 -> data << " ";
    // cout << node1 -> next << " ";

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    // print(head);

    InsertAtHead(head, 12);

    // print(head);

    InsertAtTail(tail, 13);
    // print(head);

    InsertAtPosition(head, tail, 3, 44);
    InsertAtPosition(head, tail, 3, 99);
    // InsertAtPosition(head, tail, 5, 94);
    print(head);

    tail -> next = head ->next -> next;

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> next -> data << endl;
    // print(head); // code error

    if (floydDetect(head) == NULL) {
        cout << "cycle is not present " << endl;
    }
    else {
        cout << "cycle is present and starts at " << getStartNode(head) -> data << endl;
    }

    removeLoop(head);

    if (floydDetect(head) == NULL) {
        cout << "cycle is not present " << endl;
    }
    else {
        cout << "cycle is present and starts at " << getStartNode(head) -> data << endl;
    }

    // DeleteNode(head, tail, 3);
    // print(head);
    // cout << "head : " << head -> data << endl;
    // cout << "tail : " << tail -> data << endl;

    // DeleteNode(head, tail, 4);
    // print(head);
    // cout << "head : " << head -> data << endl;
    // cout << "tail : " << tail -> data << endl;

    return 0;
}