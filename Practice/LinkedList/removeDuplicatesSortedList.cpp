// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=0&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan

/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if (head == NULL) {
        return NULL;
    }
    
    Node* curr = head;
    
    while (curr->next != NULL && curr!= NULL) {
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr -> next = nodeToDelete->next;
            delete (nodeToDelete);
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}