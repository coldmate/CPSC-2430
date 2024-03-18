#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int HASH_SIZE = 17;
const string FILENAME = "WHO-COVID-Data-Test.csv";

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

class seperateChaining{
    private:
        int tableSize;
        vector<vector<int>> v;
    public:
        // constructor
        seperateChaining(int m){
          v = vector<vector<int>>(m);
          this->tableSize = m;
        }
        // hash function
        int getIndex(int key){
            return key%tableSize;
        }
        // add a key to hash table
        void add(int key){
            v[getIndex(key)].push_back(key);
        }
        // delete a key from hash table
        void deleteKey(int key){

            // get index first
            int i = getIndex(key);
            int size = v[i].size();

            // traverse ith list(vector) to search 
            for(int j = 0; j < size; j++){
                // if found, delete
                if(v[i][j] == key){
                    v[i].erase(v[i].begin() + j);
                    cout << key << " key: " << key << " is deleted!" << endl;
                    return;
                }
            }
            cout << "No key: " << key << " in hash table!";
        }
    
        // Display the contents
        void display(){

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
};

class DataEntry{
    private:
        string date;
        string country;
        int c_cases;
        int c_deaths;
    public:
        string getDate();
        string getCountry();
        int getCases();
        int getDeaths();

        string setDate(string date);
        string setCountry(string country);
        int setCases(int cases);
        int setDeaths(int deaths);
 };

class cvsdata{
  string date;
  string country;
  int cases;
  int deaths;
public:
  cvsdata(string date, string country, int cases, int deaths){
    this->date = date;
    this->country = country;
    this->cases = cases;
    this->deaths = deaths;
  }
};

class CovidDB{
    public: 
        bool add(DataEntry entry);
        DataEntry get(string country);
        void remove(string country);
};

//void readFile(vector<cvsdata> & recordList);
void userInterface(int & choice);
void outcome(int & choice, seperateChaining & SC_hashTable);
int hash(string country);

int main(){
    int choice = 0;

    userInterface(choice);

    while(choice != 1){
        cout << "Initial hash table hasn't been created" << endl;
        cout << "Please enter 1 to initialize hash table: " << endl;
        cin >> choice;
        cout << endl;
    }
    
    vector<cvsdata> recordList;
    // open the file
    ifstream file(FILENAME);

    if(file.is_open()){

        cout << "Open File Success" << endl;

        string line;

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

    seperateChaining SC_hashTable(HASH_SIZE);
    cout << endl;

    while(choice >= 1 && choice <= 5){
        userInterface(choice);

        outcome(choice, SC_hashTable);
    }
    return 0;
}

void userInterface(int & choice){
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
}

void outcome(int & choice, seperateChaining & SC_hashTable){
    if(choice == 1){
        cout << "Initial hash table has already been created" << endl;
    }
    else if(choice == 2){
        cout << "NOT IMPLEMENTED" << endl;
    }   
    else if(choice == 3){
        cout << "NOT IMPLEMENTED" << endl;
    }
    else if(choice == 4){
        cout << "NOT IMPLEMENTED" << endl;
    }
    else if(choice == 5){
        SC_hashTable.display();
    }
    else{
        choice = 0;
    }
    cout << endl;
}

int hash(string country){
    int sum = 0; 
    /*
    for each character c at position i in string country{ 
        sum = ⅀(i * c) % m; // m is the hash table size, c is the ASCII code for char.
    } 
    */
    return sum; 
}