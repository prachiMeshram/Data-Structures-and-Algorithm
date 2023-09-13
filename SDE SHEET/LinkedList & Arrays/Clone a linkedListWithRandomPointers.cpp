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

#include<bits/stdc++.h>

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