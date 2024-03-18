// Alen Ovalles
// assignment4.cpp
// 06/01/2022
//
#ifndef COVIDDATA_H
#define COVIDDATA_H
#include <iostream>
#include <vector> 
using namespace std;

class dataEntry{
    private:
        string newDate;
        string newCountry;
        int newCases;
        int newDeaths;
    public: 
        void setDate(string);
        void setCountry(string);
        void setCases(int);
        void setDeaths(int);

        string getDate();
        string getCountry();
        int getCases();
        int getDeaths();

};  

class covidDB{
    private:
        int tableSize;
        vector<vector<dataEntry>> newEntry;
    public:
        covidDB(int m);
        bool inital;
        int hash(string country);
        int getIndex(string country);
        bool add(dataEntry entry);

        //void get(string country);
        dataEntry get(string country);

        void remove(string country);
        void display();
        vector<string> split(string str, char del); 
};

#endif