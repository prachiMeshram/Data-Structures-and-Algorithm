// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021

#include <bits/stdc++.h> 
using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


Node* sortList(Node *head)
{
    // Write your code here.
    
    // BRUTE FORCE
    int zeroC = 0;
    int oneC = 0;  
    int twoC = 0;  
      
    Node* temp = head; 

    while (temp != NULL) {

        if (temp->data == 0) {
            zeroC++;
        }
        else if (temp->data == 1) {
            oneC++;
        }
        else if (temp->data == 2){
            twoC++;
        }
        temp = temp -> next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroC != 0) {
            temp->data = 0;
            zeroC--;
        }
        else if (oneC != 0) {
            temp->data = 1;
            oneC--;
        }
        else if (twoC != 0) {
            temp->data = 2;
            twoC--;
        } 
        temp = temp->next;
    } 

    return head;
}
