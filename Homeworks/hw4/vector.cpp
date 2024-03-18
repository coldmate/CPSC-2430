#include <iostream>
#include <vector> 
/******************************************************************************
Do not forget to include library
*******************************************************************************/
 
using namespace std;
 
int main() 
{
    
    // two ways to initilize 
    vector<int> ve;
    vector<int> ve1 = {3, 100}; // it means you give this vector 3 integers with the value of 100
    
    
    // insert values to the vector
    ve.push_back(1);
    ve.push_back(2);
    ve.push_back(3);
    ve.push_back(4);
    ve.push_back(5);
    ve.push_back(6);
    ve.push_back(7);
    ve.push_back(8);
    
    // Enhanced for loop to print the values in the vector
    // It is the same as 
    // for (int i = 0 ; i < ve.size(); i++) {...}
    for(int i : ve) 
        cout << "i = " << i << endl;
    
    
    // delete the element in the vector - erase function
    // erase the 6th element
    ve.erase (ve.begin()+5);
 
    // erase the first 3 elements:
    ve.erase (ve.begin(),ve.begin()+3);
    
    
    for(int i : ve) 
        cout << "i = " << i << endl;
    
    // insert elements to specifc location    
    ve.insert (ve.begin()+1, 100);
    for(int i : ve) 
        cout << "i = " << i << endl;
        
    // vector size
    cout << ve.size() <<endl; 
    
    // vector empty?
    cout << ve.empty() << endl;
}