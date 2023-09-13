// https://www.codingninjas.com/studio/problems/920454?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// * Definition for singly-linked list.
 class Node {
 public:
     int data;
     Node *next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
 };

// BRUTE FORCE
Node *rotate(Node *head, int k) {
     // Write your code here.
     if (head == NULL || head->next == NULL || k == 0) return head;
     
     for (int i = 0; i < k; i++) {
          Node* temp = head;
          while (temp->next->next != NULL){
               temp = temp->next;
          }
          Node* end = temp->next;;
          temp->next = NULL;
          end->next = head;
          head = end;
     }
     return  head;
}

// OPTIMAL APPROACH
Node *rotate(Node *head, int k) {
     // Write your code here.
     
     Node* temp = head;
     int cnt = 1;
     
     while (temp->next != NULL) {
          temp = temp->next;
          cnt++;
     }
     
     k = k%cnt;
     temp->next = head;
     int n = cnt-k;
     while (n--) {
          temp = temp->next;
     }
     head = temp->next;
     temp->next = NULL;
     return head; 
}