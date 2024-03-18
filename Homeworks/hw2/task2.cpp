// Alen Ovalles
// task2.cpp
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

double root5(double n, double y);

int main() {
    double n = 32.0;
    double y = 1.0;

    cout << endl;
    cout << pow(31, 0.2) << endl;
    cout << root5(n, y) << endl;
    cout << endl;

    return 0;
}

double root5(double n, double y){
    if(abs((pow(y, 5)) - n > 0.00001)){    
        return y - 0.00001;
    }
    else{
        return(root5(n, y + 0.00001));
    }
}