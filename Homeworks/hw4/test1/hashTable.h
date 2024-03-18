#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
using namespace std;


class covidDB{
    private:
        int tableSize;
        vector<vector<string>> v;
    public:
        // constructor
        covidDB(int m);

        // hash function
        int getIndex(string dataEntry);
        
        // add a dataEntry to hash table
        void add(string dataEntry);

        // returns a specfic data entry 
        void get(string dataEntry);

        // delete a dataEntry from hash table
        void remove(string dataEntry);
    
        // Display the contents
        void display();
};
#endif