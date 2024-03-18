// Alen Ovalles
// task4.cpp
// ??/??/????
//
// Purpose: 
// Input:
// Process:
// Output:
//
// Example:
//
//

#include <iostream>
#include <math.h>
using namespace std;

double ramanujan(int depth);
double ram(int depth, int n);

int main() {
    int n;

    cout << endl;
    cout << "Enter a depth: ";
    cin >> n;   
    cout << ramanujan(n) << endl;
    cout << endl;

    return 0;
}

double ramanujan(int depth){ 
    int n = 0;
    return ram(depth, n);
}   

double ram(int depth, int n){
    if(depth < 0){
        return 0;
    }
    else{
        return (1 + n) * sqrt((6 + n) + ram(depth - 1, n + 1));
    }
}