#include "hashTable.h"
#include <iostream>
#include <vector>
using namespace std;

// constructor
covidDB::covidDB(int m){
    v = vector<vector<string>>(m);
    this->tableSize = m;
}
        
// hash function
int covidDB::getIndex(string dataEntry){
    int ascii = 0;
    int size = dataEntry.size();

    for(int i = 1; i <= size; i++){
        ascii += (i * int(dataEntry[i]));
    }    

    return ascii % tableSize;
}

// add a dataEntry to hash table
void covidDB::add(string dataEntry){
    v[getIndex(dataEntry)].push_back(dataEntry);
}


// delete a dataEntry from hash table
void covidDB::remove(string dataEntry){
    // get index first
    int i = getIndex(dataEntry);
    int size = v[i].size();

    // traverse ith list(vector) to search 
    for(int j = 0; j < size; j++){
        // if found, delete
        if(v[i][j] == dataEntry){
            v[i].erase(v[i].begin() + j);
            cout << dataEntry << " dataEntry: " << dataEntry << " is deleted!" << endl;
            return;
        }
     }
    cout << "No dataEntry: " << dataEntry << " in hash table!";
}

// Display the contents
void covidDB::display(){

    cout << "Hash Table" << endl;
    int size = v.size();

    for(int i = 0; i < size; i++) {
        cout << i;
        int sizeV = v[i].size();
                
        for (int j = 0; j < sizeV; j++)
            cout << " -> " << v[i][j];
        cout << endl;
    }
}
