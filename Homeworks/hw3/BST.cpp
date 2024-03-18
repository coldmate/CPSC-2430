// Alen Ovalles
// BST.cpp
// 05/16/2022
//

#include <iostream> 
#include "BST.h"
using namespace std;

// PRIVATE FUNCTIONS
void BST::insert(TreeNode * & t, int x){
    if(search(t, x) == -1){
        TreeNode * newNode = nullptr;
        newNode = new TreeNode;

        newNode->val = x;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(!t){ 
            t = newNode;
        }   
        else if(x < t->val){
            insert(t->left, x);
        }
        else{
           insert(t->right, x);
        }
    }
    else{
        cout << "No duplicates accepted" << endl;
    }
}

int BST::search(TreeNode * t, int x){
    if(!t){
        return -1;
    }
    else if(t->val == x){
        return 1;
    }
    else{
        if(t->val < x){
            return search(t->right, x);
        }
        else{
            return search(t->left, x);
        }
    }
}

void BST::preSucNode(TreeNode * t, TreeNode * & pre, TreeNode * & suc, int x){
    if(!t || (search(t, x) == -1)){
        return;
    }
    if(t->val == x){
        if(t->left != nullptr){
            TreeNode * temp = t->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }
        if(t->right != nullptr){
            TreeNode * temp = t->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }
    if(t->val > x){
        suc = t;
        preSucNode(t->left, pre, suc, x);
    }
    else{
        pre = t;
        preSucNode(t->right, pre, suc, x);
    }
}

int BST::height(TreeNode * t){
    if(!t){
        return -1;
    }
    else{
        int lHeight = height(t->left);
        int rHeight = height(t->right);

        if(lHeight > rHeight){
            return lHeight + 1;
        }
        else{
            return rHeight + 1;
        }
    }
}

int BST::numOfNodes(TreeNode * t){
    if(!t){
        return 0;
    }
    else{
        return(1 + numOfNodes(t->left) + numOfNodes(t->right));
    }
}

void BST::inorder(TreeNode * t) {
    if(!t){
        return;
    }
    else{
        inorder(t->left);
        cout << t->val << " ";
        inorder(t->right);
    }
}

void BST::preorder(TreeNode * t) {
    if(!t){
        return;
    }
    else{
        cout << t->val << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

void BST::postorder(TreeNode * t) {
    if(!t){
        return;
    }
    else{
        postorder(t->left);
        postorder(t->right);
        cout << t->val << " ";
    }
}

void BST::deleteNode(TreeNode * & t, int x){
    if(!t || (search(t, x) == -1)){
        return;
    }
    else{
        deleteNode(t->left, x);
        deleteNode(t->right, x);

        if(t->val == x && !t->left && !t->right){
            delete t;
            t = nullptr;
        }
    }
}

int BST::balanceCheck(TreeNode * t){
    if(!t){
        return -1;
    }
    else{
        if(abs(height(t->left) - height(t->right)) <= 1 && balanceCheck(t->left) && balanceCheck(t->right)){
            return 1;
        }
        else{
            return -1;
        }
    }
}

void BST::destoryTree(TreeNode * & t){
    if(!t){
        return;
    }
    else{
        destoryTree(t->left);
        destoryTree(t->right);
        cout << "Deleting " << t->val << " from the BST" << endl;
        delete t;
    }
    t = nullptr;
}

// PUBLIC FUNCTIONS
BST::BST(){
    root = nullptr;
}

void BST::insertNode(int x){
    insert(root, x);
}

int BST::searchedNode(int x){
    return search(root, x);
}

void BST::preNode(int x){
    TreeNode * pre = nullptr;
    TreeNode * suc = nullptr;
    preSucNode(root, pre, suc, x);
    if(pre != nullptr){
        cout << "Predecessor is: " << pre->val << endl;
    }
    else{
        cout << x << " doesn't have a predecessor" << endl;
    }
}

void BST::sucNode(int x){
    TreeNode * pre = nullptr;
    TreeNode * suc = nullptr;
    preSucNode(root, pre, suc, x);
    if(suc != nullptr){
        cout << "Successor is: " << suc->val << endl;
    }
    else{
        cout << x << " doesn't have a successor" << endl;
    }
}

void BST::inorderDisplay(){
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}
    
void BST::preorderDisplay(){
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
}

void BST::postorderDisplay(){
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}

int BST::nodes(){
    return numOfNodes(root);
}

int BST::heightOfTree(){
    return height(root);
}

void BST::deleted(int x){
    deleteNode(root, x);
}

int BST::balanced(){
    return balanceCheck(root);
}

void BST::destroyed(){
    destoryTree(root);
}
