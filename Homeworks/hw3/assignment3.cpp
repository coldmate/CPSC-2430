// Alen Ovalles
// assignment3.cpp
// 05/16/2022
//
// Purpose: BST Operations Implementation
// Input: Given operation number
// Process: Given operation process
// Output: Given opeartion display
//

#include <iostream>
#include "BST.h"
using namespace std;
 
void menu(int & input);
void output(BST & t, int & input);

int main(){
    BST t;
    int input = 1;

    cout << endl;

    while(input != 0) {
        menu(input);

        output(t, input);  
    }
    return 0;
}

void menu(int & input){
    cout << "****** MENU INTERFACE ****** " << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Search for a value" << endl;
    cout << "3. Find predecessor for an existing value" << endl;
    cout << "4. Find successor for an existing value" << endl;
    cout << "5. Find height of tree" << endl;
    cout << "6. Find total number of nodes in tree" << endl;
    cout << "7. Delete a leaf node" << endl;
    cout << "8. Traverse inorder and display" << endl;
    cout << "9. Traverse preorder and display" << endl;
    cout << "10. Traverse postorder and display" << endl;
    cout << "11. Check if tree is balanced" << endl;
    cout << "12. Destroy tree" << endl;
    cout << "0. Quit" << endl;   
    cout << endl;
    cout << "Please select an operation to test: ";
    cin >> input;
}

void output(BST & t, int & input){
    int num;
    if(input == 1){
        cout << "Enter a number to insert into the BST: ";
        cin >> num;
        t.insertNode(num);
        cout << endl;
    }
    else if(input == 2){
        cout << "Enter a number to search into the BST: ";
        cin >> num;

        if(t.searchedNode(num) == 1){
            cout << "The number is stored in the BST" << endl;
        }
        else{
            cout << "The number is not stored in the BST" << endl;
        }
        cout << endl;
    }
    else if(input == 3){
        cout << "Enter an existed value to know the predecessor: ";
        cin >> num;
        t.preNode(num);
        cout << endl;
    }
    else if(input == 4){
        cout << "Enter an existed value to know the succesor: ";
        cin >> num;
        t.sucNode(num);
        cout << endl;
    }
    else if(input == 5){
        cout << "The height of the BST is: " << t.heightOfTree() << endl;
        cout << endl;
    }
    else if(input == 6){
        cout << "The total number of nodes in the BST is: " << t.nodes() << endl;
        cout << endl;
    }
    else if(input == 7){
        cout << "Enter a leaf node to delete: ";
        cin >> num;
        t.deleted(num);
        cout << endl;
    }
    else if(input == 8){
        t.inorderDisplay();
        cout << endl;
    }
    else if(input == 9){
        t.preorderDisplay();
        cout << endl;
    }
    else if(input == 10){
        t.postorderDisplay();
        cout << endl;
    }
    else if(input == 11){
        if(t.balanced() == 1){
            cout << "This is a balanced BST" << endl;
        }
        else{
            cout << "This is not a balanced BST" << endl;
        }
        cout << endl;
    }
    else if(input == 12){
        t.destroyed();
        cout << endl;
    }
    else{
        input = 0;
    }
}