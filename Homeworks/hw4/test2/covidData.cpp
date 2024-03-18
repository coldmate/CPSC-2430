// Alen Ovalles
// assignment4.cpp
// 06/01/2022
//
#include "covidData.h"
#include <iostream>
using namespace std;

void dataEntry::setDate(string date){
    newDate = date;
}

void dataEntry::setCountry(string country){
    newCountry = country;
}

void dataEntry::setCases(int cases){
    newCases = cases;
}

void dataEntry::setDeaths(int deaths){
    newDeaths = deaths;
}
string dataEntry::getDate(){
    return newDate;
}

string dataEntry::getCountry(){
    return newCountry;
}

int dataEntry::getCases(){
    return newCases;
}

int dataEntry::getDeaths(){
    return newDeaths;
}

covidDB::covidDB(int m){
    newEntry = vector<vector<dataEntry>>(m);
    this->tableSize = m;
}

int covidDB::hash(string country){
    int ascii = 0;
    int size = country.size();

    for(int i = 1; i <= size; i++){
        ascii += (i * int(country[i]));
    }    
    
    return ascii % tableSize;
}

bool covidDB::add(dataEntry entry){
    if(inital == false){
        newEntry[hash(entry.getCountry())].push_back(entry);
    }
    else{ // After initial hash table is created 
        bool validCountry = false;
        int i = hash(entry.getCountry()); 
        int size = newEntry[i].size();
        string oldDate = "";
        int oldCases = 0, oldDeaths = 0;

        for(int j = 0; j < size; j++){
            if(newEntry[i][j].getCountry() == entry.getCountry()){
                oldDate = newEntry[i][j].getDate();
                oldCases = newEntry[i][j].getCases();
                oldDeaths = newEntry[i][j].getDeaths();
                validCountry = true;
            }
        }

        if(validCountry == false){
            cout << "There is no country: " << entry.getCountry() << " in hash table!" << endl;
            return false;
        }

        vector<string> oldResult = split(oldDate, '/');
        int oldMonth = stoi(oldResult[0]);
        int oldDay = stoi(oldResult[1]);
        int oldYear = stoi(oldResult[2]);

        string newDate = entry.getDate();
        vector<string> newResult = split(newDate, '/');
        int newMonth = stoi(newResult[0]);
        int newDay = stoi(newResult[1]);
        int newYear = stoi(newResult[2]);
    
        if(oldYear > newYear){
            cout << "Already have an latest year entry for " << entry.getCountry() << " in hash table!" << endl;
            return false;
        }
        else if(oldYear == newYear){
            if(oldMonth > newMonth){
                cout << "Already have an latest month entry for " << entry.getCountry() << " in hash table!" << endl;
                return false;
            }
            else if(oldMonth == newMonth){
                if(oldDay >= newDay){
                    cout << "Already have an latest day entry for " << entry.getCountry() << " in hash table!" << endl;
                    return false;
                }
            }
        }

        int newCases = oldCases + entry.getCases();
        int newDeaths = oldDeaths + entry.getDeaths();

        for(int j = 0; j < size; j++){
            if(newEntry[i][j].getCountry() == entry.getCountry()){
                newEntry[i][j].setDate(newDate);
                newEntry[i][j].setCases(newCases);
                newEntry[i][j].setDeaths(newDeaths);
            }
        }
        return true;
    }
   return true;
}

dataEntry covidDB::get(string country){
    dataEntry oneEntry;

    int i = hash(country);
    int size = newEntry[i].size();

    for(int j = 0; j < size; j++){
        if(newEntry[i][j].getCountry() == country){ 
            oneEntry.setDate(newEntry[i][j].getDate());
            oneEntry.setCountry(newEntry[i][j].getCountry());
            oneEntry.setCases(newEntry[i][j].getCases());
            oneEntry.setDeaths(newEntry[i][j].getDeaths());
        }
    }
    return oneEntry;
}

void covidDB::remove(string country){

    // get index first
    int i = hash(country);
    int size = newEntry[i].size();

    // traverse ith list(vector) to search 
    for(int j = 0; j < size; j++){
        // if found, delete
        if(newEntry[i][j].getCountry() == country){
            newEntry[i].erase(newEntry[i].begin() + j);
            cout << "The data entry of " << country << " is deleted!" << endl;
            return;
        }
    }
    cout << "There is no country: " << country << " in hash table!" << endl;
}

void covidDB::display(){
    cout << "Hash Table" << endl;
    int size = newEntry.size();

    for(int i = 0; i < size; i++) {
        cout << i;
        int sizeV = newEntry[i].size();
                
        for(int j = 0; j < sizeV; j++){
            cout << " -> " << newEntry[i][j].getCountry();
        }
        cout << endl;
    }
}

vector<string> covidDB::split(string str, char del){ 
    vector<string> result;
    // declaring temp string to store the curr "word" upto del
    string temp = "";
    for(int i=0; i<(int)str.size(); i++){
        // If current char is not ',', then append it to the "word", otherwise you have completed the word, and start the next word
        if(str[i] != del){
	    temp += str[i];
        }else{
            result.push_back(temp);
            temp = "";
        }
    }
    // push the last substring after the last ',' to the result
    result.push_back(temp);
    return result;
}