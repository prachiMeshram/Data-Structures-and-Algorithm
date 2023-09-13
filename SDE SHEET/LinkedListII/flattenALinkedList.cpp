// https://www.codingninjas.com/studio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;


//   Definition for linked list.
 class Node {
  public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 };


Node* merge(Node* f, Node* s) {
	if (f == NULL) return s;
	if (s == NULL) return f;
	
	Node* head = new Node(-1);
	Node* temp = head;
	
	while (f != NULL && s != NULL) {
		if (f->data > s->data) {
			temp->child = s;
			temp = s;
			s = s->child;
		}
		else {
			temp->child = f ;
			temp = f;
			f = f->child;
		}
	}
	if (f != NULL) {
		temp->child = f;
	}
	if (s != NULL) {
		temp->child = s;
	}
	return head->child;
} 

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if (head == NULL || head->next == NULL) return head;
	Node* down = head;
	Node* right = flattenLinkedList(head->next);
	down->next = NULL;
	Node* ans = merge(down, right);
	return ans;
}
