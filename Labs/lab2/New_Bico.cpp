// Alen Ovalles
// Bico.cpp
// 04/01/2022
//
// Purpose: Write a function bico(int x, int y) that returns the ith coefficient of the binomial (x+y)^n
// Input: Ask user for the degree of the binomial and what index of coeffcient to be returned
// Process: Uses recursion to travese through the pascal triangle function
// Output: Returns the coefficient at the targeted index
//
// Example: ./Bico.out
//          Please input the degree of the binomial: 4
//          Please input the index of the coefficient: 2
//          The result is: 6
//
//          ./Bico.out
//          Please input the degree of the binomial: -1
//          Please input the index of the coefficient: 0
//          The result is: 0
//
//          ./Bico.out
//          Please input the degree of the binomial: 5
//          Please input the index of the coefficient: 6
//          The result is: 0

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int bico(int degree, int targetIndex); 
// Uses recursion to return the previous value until the targeted coefficient

int main() {
    int degree, targetIndex;

    cout << endl;
    cout << "Please input the degree of the binomial: ";
    cin >> degree;

    cout << "Please input the index of the coefficient: ";
    cin >> targetIndex;  

    auto start = high_resolution_clock::now();
  
    cout << "The result is: " << bico(degree,targetIndex) << endl << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<< duration.count() << endl << endl;

    return 0;
}

int bico(int degree, int targetIndex){
    if(degree < 0){
        return 0;
    }
    else if(targetIndex == 0 || targetIndex == degree){
        return 1;
    }
    else{
        return bico((degree-1), targetIndex) + bico((degree-1), (targetIndex-1));
    }
}