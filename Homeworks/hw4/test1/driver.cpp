#include "csvData.h"
#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
using namespace std;

const string FILENAME = "WHO-COVID-Data.csv";
const int HASHSIZE = 17;

void readFile(vector<cvsdata> & recordList);
vector<string> split(string str, char del); 
// Reads "WHO-COVID-Data-Test.csv"
// Fills recordList with data sets 

void display(vector<cvsdata> & recordList, vector<cvsdata> & dataEntrys);
// Displays dataEntrys

void hashTable(covidDB & covidTracker, vector<string> & countryNames, vector<cvsdata> & dataEntrys);
// Fills initial hash table of data entries

int main(){
    covidDB covidTracker(HASHSIZE);
    vector<string> countryNames;
    vector<cvsdata> dataEntrys; // FOR THE TOTAL AMOUNT OF CASES/DEATHS 
    vector<cvsdata> recordList;
    readFile(recordList);

    cout << "COMBINED CASES/DEATHS DATA ENTRIES" << endl;
    display(recordList, dataEntrys);

    // Fills the hash table with country names (data entries)
    hashTable(covidTracker, countryNames, dataEntrys);
    // Displays initial hash table
    covidTracker.display();
    
    // HAVE TO IMPLEMENT ADD(), GET()

    cout << endl;
    return 0;
}

void readFile(vector<cvsdata> & recordList){
    ifstream file(FILENAME);
    string line; 

    cout << endl;

    if(file.is_open()){
        cout << "Open File Success" << endl;
        
        while(getline(file, line)){
      
            // split the content in each line
            vector<string> result = split(line, ',');

            // wrap up all the data in the string to a cvsdata type and push it to the vector
            cvsdata oneEntry = cvsdata(result[0], result[1], std::stoi(result[2]), std::stoi(result[3]));
            recordList.push_back(oneEntry);
        }
        int size = recordList.size();
        cout << "There are " << size << " records in total." << endl;
  }
  else{
    cout << "Open file failed" << endl;
  }
  cout << endl;
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

void display(vector<cvsdata> & recordList, vector<cvsdata> & dataEntrys){
    int size = recordList.size();
    int sumCases = 0, sumDeaths = 0;// count = 0, index = 0;

    for(int i = 0; i < size; i++){
        sumCases += recordList[i].getCases();
        sumDeaths += recordList[i].getDeaths();

        string name = recordList[i].getCountry();
        string name2 = recordList[i+1].getCountry();

        if(name != name2){
            string latestDate = recordList[i].getDate();
            cvsdata oneEntry = cvsdata(latestDate, name, sumCases, sumDeaths);
            dataEntrys.push_back(oneEntry);
            sumCases = 0;
            sumDeaths = 0;
        }
    }

    size = dataEntrys.size();
    for(int i = 0; i < size; i++){
        cout << dataEntrys[i].getDate() << ", ";
        cout << dataEntrys[i].getCountry() << ", ";
        cout << dataEntrys[i].getCases() << ", ";
        cout << dataEntrys[i].getDeaths()<< endl;  
    }
}

void hashTable(covidDB & covidTracker, vector<string> & countryNames, vector<cvsdata> & dataEntrys){
    cout << endl;
    int dataSize = dataEntrys.size();
    for(int index = 0; index < dataSize; index++){
        countryNames.push_back(dataEntrys[index].getCountry());
        covidTracker.add(countryNames[index]);
    }
}