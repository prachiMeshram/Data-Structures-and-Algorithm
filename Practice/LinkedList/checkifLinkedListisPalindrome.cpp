// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1


#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  private: 
    Node* getMid(Node* head) {
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast!= NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
  public:
    //Function to check whether the list is palindrome.
    
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr!=NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        // BRUTE FORCE (storing data in vector then checking for palindrome)
        if (head->next == NULL) {
            return true;
        } 
        
        // get mid 
        Node* mid = getMid(head);
        
        
        Node* temp = mid->next;
        mid->next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = mid->next;
        
        while (head2!=NULL) {
            if (head1->data != head2->data) {
                return false;
            }
            head1= head1->next;
            head2= head2->next;
        }
        
        temp = mid->next;
        mid->next = reverse(temp);
        
        return true;
    }
};
