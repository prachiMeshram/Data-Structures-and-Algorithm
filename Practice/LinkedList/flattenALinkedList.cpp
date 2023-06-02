// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;


//  Definition for linked list.
 class Node {
  public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 };
 

Node* solve(Node* first, Node* second) {
	
    Node* temp = new Node(0);

	Node* res = temp;

	while (first && second) {

		if (first->data < second->data) {
			temp->child = first;
			temp = temp->child;
			first = first->child;
		}
		else {
			// temp->child = second;
			// second = second->child;
			// temp = temp->child;
			temp->child = second;
			temp = temp->child;
			second = second->child;
		}
	}

	if (first) {
		temp -> child = first;
	}
	else {
		temp -> child = second;
	}

	return  res->child;
}

 
Node* flattenLinkedList(Node* head) 
{
	// Write your code here

	if (head == NULL || head->next == NULL) {
		return  head;
	} 

	Node* down = head;
	Node* right = head->next;
	
	right= flattenLinkedList(right);
	down->next = NULL;

	Node* ans = solve(down, right);

	return ans;

}
