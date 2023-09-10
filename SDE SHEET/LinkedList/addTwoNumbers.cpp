// https://www.codingninjas.com/studio/problems/add-two-numbers-as-linked-lists_1170520?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

//  Definition of linked list:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// optimal approach
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *l1 = num1;
    Node *l2 = num2;

    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;

    while (carry || l1 != NULL || l2 != NULL)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;

        carry = sum / 10;
        int digit = sum % 10;
        Node *node = new Node(digit);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}


// other approach but not encouraged due to overflow
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    if (num1 == NULL) return num2; 
    if (num2 == NULL) return num1; 

    long long n1 = 0;
    long long n2 = 0;

    Node* temp = num1;
    int p = 0;
    while (temp != nullptr) {
        n1 += temp->data*pow(10, p);
        temp = temp->next;
        p++;
    }

    temp = num2;
    p = 0;
    while (temp != nullptr) {
        n2 += temp->data*pow(10, p);
        temp = temp->next;
        p++;
    }

    long long n3 = n1 + n2;

    Node* newH = nullptr;
    Node* current = nullptr;
    if (n3 == 0) {
        return new Node(0); // Special case for sum equal to zero.
    }

    while (n3) {
        int digit = n3 % 10;
        n3 /= 10;
        Node* node = new Node(digit);
        if (newH == nullptr) {
            newH = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }

    return newH;
}
