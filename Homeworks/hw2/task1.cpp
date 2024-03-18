// Alen Ovalles
// task1.cpp
// 04/24/2022
//
// Purpose: Practice recursion
// Input: An user given integer
// Process: Calculate the sum of its digits
// Output: Display the result
//
// Example: 
//          Enter a number: 123
//          The sum is: 6
//
//          Enter a number: 10
//          The sum is: 1
// 
//          Enter a number: 91
//          The sum is: 10
//

#include <iostream>
using namespace std;

int sumDigits(int n);

int main() {
    int n;

    cout << endl;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The sum is: " << sumDigits(n) << endl << endl;

    return 0;
}

int sumDigits(int n){
    if(n < 10){
        return n;
    }
    else{
        return n%10 + sumDigits(n/10); 
    }
}