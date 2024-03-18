// Alen Ovalles
// assignment4.cpp
// 06/01/2022
//
#include "covidData.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
using namespace std;

const string FILENAME = "WHO-COVID-Data.csv";
const int HASHSIZE = 17;

void readFile(vector<dataEntry> & recordList);
vector<string> split(string str, char del); 
void combine(vector<dataEntry> & recordList, vector<dataEntry> & combinedRecords);
void hashTable(vector<dataEntry> & combinedRecords, covidDB & entry);

void userInterface(int & choice, bool & createdHash);
void outcome(int & choice, covidDB & entrys);

int main(){
    vector<dataEntry> recordList;
    vector<dataEntry> combinedRecords;
    covidDB entrys(HASHSIZE);
    int choice = 0;
    bool createdHash = false;

    userInterface(choice, createdHash);

    if(choice != 0){
        readFile(recordList);
        combine(recordList, combinedRecords);
        hashTable(combinedRecords, entrys);
    }

    while(choice >= 1 && choice <= 5){
        userInterface(choice, createdHash);
        outcome(choice, entrys);
    }

    return 0;
}

void readFile(vector<dataEntry> & recordList){
    ifstream file(FILENAME);
    string line; 

    if(file.is_open()){
        cout << "Open File Success" << endl;
        
        while(getline(file, line)){
      
            // split the content in each line
            vector<string> result = split(line, ',');

            // wrap up all the data in the string to a dataEntry type and push it to the vector
            dataEntry oneEntry;
            oneEntry.setDate(result[0]);
            oneEntry.setCountry(result[1]);
            oneEntry.setCases(stoi(result[2]));
            oneEntry.setDeaths(stoi(result[3]));

            recordList.push_back(oneEntry);
        }
        int size = recordList.size();
        cout << "There are " << size << " records in total." << endl;
  }
  else{
    cout << "Open file failed" << endl;
  }
}

vector<string> split(string str, char del){
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

void combine(vector<dataEntry> & recordList, vector<dataEntry> & dataEntrys){
    int size = recordList.size();
    int sumCases = 0, sumDeaths = 0;

    for(int i = 0; i < size; i++){
        sumCases += recordList[i].getCases();
        sumDeaths += recordList[i].getDeaths();

        string name = recordList[i].getCountry();
        string name2 = recordList[i+1].getCountry();

        if(name != name2){
            string latestDate = recordList[i].getDate();
            dataEntry oneEntry;
            oneEntry.setDate(latestDate);
            oneEntry.setCountry(name);
            oneEntry.setCases(sumCases);
            oneEntry.setDeaths(sumDeaths);
            dataEntrys.push_back(oneEntry);
            sumCases = 0;
            sumDeaths = 0;
        }
    }
}

void hashTable(vector<dataEntry> & combinedRecords, covidDB & entry){
    int size = combinedRecords.size();
    for(int i = 0; i < size; i++){
        entry.add(combinedRecords[i]);
    }
    entry.inital = true;
}

void userInterface(int & choice, bool & createdHash){
    cout << endl;
    cout << "Covid Tracker" << endl;
    cout << "1. Create the initial hash table" << endl; 
    cout << "2. Add a new data entry" << endl;
    cout << "3. Get a data entry" << endl;
    cout << "4. Remove a data entry" << endl;
    cout << "5. Display hash table" << endl;
    cout << "0. Quit the system" << endl;
    cout << endl;
    cout << "Please choose the operation you want: ";
    cin >> choice;
    cout << endl;

    if(choice == 1){
        createdHash = true;
    }

    while(createdHash == false){
        cout << "Initial hash table hasn't been created" << endl;
        cout << "Enter 1 to initialize hash table first: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            createdHash = true;
        }
        if(choice == 0){
            return;
        }
    }
}

void outcome(int & choice, covidDB & entrys){
    if(choice == 1){
        cout << "Initial hash table has already been created" << endl;
    }
    else if(choice == 2){
        dataEntry newEntry;
        string latestDate = ""; 
        string country = "";
        int cases = 0;
        int deaths = 0;
        bool valid = false;

        cout << "Enter the country: ";
        cin.ignore();
        cin.clear();
        getline(cin, country);
        cout << "Enter the month/day/year of the new dataEntry: ";
        cin >> latestDate;
        cout << "Enter the amount of new cases and deaths: "; 
        cin >> cases >> deaths;

        newEntry.setDate(latestDate);
        newEntry.setCountry(country);
        newEntry.setCases(cases);
        newEntry.setDeaths(deaths);

        valid = entrys.add(newEntry);

        if(valid == true){
            cout << "Updated data entry for the country: " << country << endl;
        }
    }   
    else if(choice == 3){
        dataEntry oneEntry;
        string country;

        cout << "Enter a country: ";
        cin.ignore();
        cin.clear();
        getline(cin, country);
        oneEntry = entrys.get(country);

        if(oneEntry.getDate() != ""){
            cout << oneEntry.getDate() << ", ";
            cout << oneEntry.getCountry() << ", ";
            cout << oneEntry.getCases() << ", ";
            cout << oneEntry.getDeaths() << endl;
        }
        else{
            cout << "There is no country: " << country << " in the hash table!" << endl;
        }
    }
    else if(choice == 4){
        string country = "";
        cout << "Enter a country: ";
        cin.ignore();
        cin.clear();
        getline(cin, country);
        entrys.remove(country);
    }
    else if(choice == 5){
        entrys.display();
    }
    else{
        choice = 0;
    }
}