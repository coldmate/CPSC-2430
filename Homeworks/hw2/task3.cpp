// Alen Ovalles
// task3.cpp
// ??/??/????
//
// Purpose: 
// Input: AM I ASSUMING THAT THE INPUTS ARE POSITIVE INTEGERS???
// Process:
// Output:
//
// Example:
//
//

#include <iostream>
using namespace std;

int egyptDivision(int dividend, int divisor);
int doubleInt(int n);
int halveInt(int dividend, int & divisor, int quotient);

int main() {
    int divisor, dividend;

    cout << endl;
    cout << "Enter a dividend and divisor: ";
    cin >> dividend >> divisor;
    cout << "The quotient of " << dividend << " and " << divisor << " is: " << egyptDivision(dividend, divisor) << endl;
    cout << endl;

    return 0;
}

//-------------------------------------------------
/*
int egyptDivision(int dividend, int divisor){
    int original = divisor, quotient = 1;
    quotient = halveInt(divisor, dividend, quotient);

    while(dividend - divisor >= original){
        divisor += original;
        quotient++;  
    }
    return quotient;
}

int doubleInt(int n){
    return (n+n);
}

int halveInt(int dividend, int & divisor, int quotient){
    if(divisor >= dividend){
        return quotient;
    }
    else{
        quotient = doubleInt(quotient);
        divisor = doubleInt(divisor);
        return halveInt(dividend, divisor, quotient);
    }
}
*/

int doubleInt(int num){
    return num+num;
}

int halveInt(int num, int x){
    if(num <= 0){
        return x;
    }
    else{
        num -= 2;
        x++;
        return halveInt(num, x);
    }
}

int egyptDivision(int dividend, int divisor){
    int a = 1;
    int b = divisor; // 56
    int c = dividend; // 1960
    int d = 0;

    while(b < c){ // 56 < 1960
        a = doubleInt(a); // 64
        b = doubleInt(b); // 3584
    }
    if(b == c){
        return a;
    }
    else{
        while(a >= 1){ // 64 >= 1
            while(b > c){ // 3584 > 1960
                a = halveInt(a, 0); // 32
                b = halveInt(b, 0); // 1792
            }
            d += a; // 1792
            c -= b; // 168
            a = halveInt(a, 0); // 32
            b = halveInt(b, 0); // 1792
        }
        return d;
    }
}