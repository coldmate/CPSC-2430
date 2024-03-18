// Alen Ovalles
// Task5.cpp
// ??/??/????
//
// Purpose: Sum from 1 to n using recursion vs. iteration 
// Input: User input an integer 
// Process: Calculates the sum from 1 to the given integer
// Output: The sum from 1 to the integer
//
// Example:
//
//

#include <iostream>
using namespace std;

int rec_sum(int n);
int iter_sum(int n);

int main() {
    int n;

    cout << endl;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The sum is: " << rec_sum(n) << endl;
    cout << "The sum is: " << iter_sum(n) << endl;

    cout << endl;
    return 0;
} 

int rec_sum(int n){ 
    if(n <= 0){
        return 0;
    }
    else{
        return n + rec_sum(n-1); 
    }
} // O(n) = 2^n

int iter_sum(int n){
    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    return sum;
} // O(n) = n