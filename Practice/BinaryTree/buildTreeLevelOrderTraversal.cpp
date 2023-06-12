#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
    public:

    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void leverOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        
        if (!temp) {
            cout << endl;
            
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void levelOrderBuildTree (TreeNode* &root) {
    queue<TreeNode*> q;
    cout <<"enter data for root " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data); 
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << "enter left data for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout << "enter right data for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp -> right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
}

int main () {

    TreeNode* root = NULL;

    levelOrderBuildTree(root);
    leverOrderTraversal(root);

    return 0;
}