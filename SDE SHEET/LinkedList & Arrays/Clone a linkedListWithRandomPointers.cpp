// https://www.codingninjas.com/studio/problems/clone-a-linked-list-with-random-pointers_983604?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

//  Definition for linked list.
 class Node {
  public:
		int data;
		Node *next;
 		Node *random;
		Node() : data(0), next(nullptr), random(nullptr){};
		Node(int x) : data(x), next(nullptr), random(nullptr) {}
		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 };


// USING HASHING

Node *cloneLL(Node *head){
	// Write your code here
	map<Node*, Node*> mpp;
	Node*temp = head;
	
	while (temp != NULL) {
		Node* node = new Node(temp->data);
		mpp[temp] = node;
		temp = temp->next;
	}
	
	temp = head;
	while (temp != NULL) {
		Node* sec = mpp[temp];
		sec->next = (temp->next != NULL) ? mpp[temp->next] : NULL;
		sec->random = (temp->random != NULL) ? mpp[temp->random] : NULL;
		temp = temp->next;
	}
	return mpp[head];
}

// OPTIMISED APPROACH
Node *cloneLL(Node *head){
	// Write your code here
	Node* temp = head;
	
	while (temp != NULL) {
		Node* newNode = new Node(temp->data);
		newNode->next = temp->next;
		temp->next = newNode;
		temp = temp->next->next;
	}
	
	Node* f = head;
	while (f != NULL) {
		if (f->random != NULL) {
			f->next->random = f->random->next;
		}
		f = f->next->next;
	}
	Node* dummy = new Node(-1);
	f = head;
	temp = dummy;
	Node* s;

	while (f != NULL) {
		s = f->next->next;
		temp->next = f->next;
		f->next = s;
		temp = temp->next;
		f = s;
	}
	return dummy->next;
}