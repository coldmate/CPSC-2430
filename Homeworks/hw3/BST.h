// Alen Ovalles
// BST.h
// 05/16/2022
//
 
#ifndef BST_H
#define BST_H

class BST{
    private:    
        struct TreeNode {
            int val;
            TreeNode * left;
            TreeNode * right;
        };
        TreeNode * root;

        void insert(TreeNode * & t, int x); 
        // Inserts given value into BST
        // Doesn't accept duplicates 

        int search(TreeNode * t, int x);
        // Returns 1 if given value is stored in BST
        // Returns -1 if given value isn't stored in BST

        void preSucNode(TreeNode * t, TreeNode * & pre, TreeNode * & suc, int x);
        // Uses same function for preNode and sucNode 
        // Find if given value has a predecessor and successor

        void inorder(TreeNode * t);
        // Displays BST inorder traversal

        void preorder(TreeNode * t);
        // Displays BST preorder traversal

        void postorder(TreeNode * t);
        // Displays BST postorder traversal

        int numOfNodes(TreeNode * t);
        // Returns # of nodes in BST

        int height(TreeNode * t);
        // Returns the height of the BST

        void deleteNode(TreeNode * & t, int x);
        // Deletes only if given value is a leaf node

        int balanceCheck(TreeNode * t);
        // Returns 1 if BST is a balanced binary tree
        // Returns -1 if BST isn't a balanced binary tree

        void destoryTree(TreeNode * & t);
        // Destorys BST
        
    public:
        BST();
        void insertNode(int x);

        int searchedNode(int x);
        // If return 1, delcare node was found
        // If return -1, delcare node was not found

        void preNode(int x); 
        void sucNode(int x); 
        int heightOfTree();
        int nodes();
        void inorderDisplay();
        void preorderDisplay();
        void postorderDisplay();
        void deleted(int x); 

        int balanced(); 
        // If return 1, delcare BST a balanced BST
        // If return -1, delcare BST not a balanced BST

        void destroyed();    
};
#endif