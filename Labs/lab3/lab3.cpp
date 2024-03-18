// Alen Ovalles
// lab3.cpp
// 05/06/2022
//
// Purpose: Binary Search Tree Insertion and Traverse
// Input: Hardcoded/given input into insert function
// Process: Code and compile insert, inorder, preorder, and postorder functions 
// Output: Display inorder, preorder, and postorder traversal
//
// Professor's in class hint: In what order of the commands would postorder traversal be?
// 1) postorder(t->left)
// 2) postorder(t->right)
// 3) cout << t->value << endl;
// 4) if(t == null){ return; } 
// Correct Order: 4 1 2 3 
//
// Example: [10, 7, 29, 30, 9]
//
//          Inorder: 7 9 10 29 30 
//          Preorder: 10 7 9 29 30 
//          Postorder: 9 7 30 29 10 
//

#include <iostream>
using namespace std;

/* 
** Binary Search Tree Insertion and Traverse
** Lab 3, CPSC 2430
** Xin Zhao
*/

class BST {
private:    
    struct TreeNode {
        int val;
        TreeNode * left;
        TreeNode * right;
    };
    TreeNode * root;

    TreeNode * insert(TreeNode * t, int x) {
        TreeNode * newNode = nullptr;
        newNode = new TreeNode;

        newNode->val = x;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(!t){ // if t == nullptr
            t = newNode;
        }
        else if(x < t->val){
            t->left = insert(t->left, x);
        }
        else{
            t->right = insert(t->right, x);
        }

        return t;
    }

    void inorder(TreeNode * t) {
        if(!t){
            return;
        }
        else{
            inorder(t->left);
            cout << t->val << " ";
            inorder(t->right);
        }
    }

    void preorder(TreeNode * t) {
        if(!t){
            return;
        }
        else{
            cout << t->val << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    void postorder(TreeNode * t) {
        if(!t){
            return;
        }
        else{
            postorder(t->left);
            postorder(t->right);
            cout << t->val << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insertNode(int x){
        root = insert(root, x);
    }

    void inorderDisplay(){
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
    
    void preorderDisplay(){
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void postorderDisplay(){
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

// in your main function, test your implementations. For example,  
int main() {
    BST t;
    
    t.insertNode (10);                          
    t.insertNode (7);                        
    t.insertNode (29);               
    t.insertNode (30);
    t.insertNode (9);

    cout << endl; 

    // inorder display
    t.inorderDisplay();  // the output should be: 7, 9, 10, 29, 30

    // preorder display
    t.preorderDisplay();  // the output should be: 10, 7, 9, 29, 30

    // postorder display
    t.postorderDisplay();  // the output should be: 9, 7, 30, 29, 10

    cout << endl;
    return 0;
}