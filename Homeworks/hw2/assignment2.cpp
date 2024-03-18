// Alen Ovalles
// assignment2.cpp
// 05/02/2022
//
// Purpose: Recursions for Mathematicians
// Input: Given the following task, user will input a number
// Process: Given the input, calculate at given tasks
// Output: Display task output
//
// Example: Enter a num: 123
//          The sum is: 6
//
//          Enter a integer: 32
//          The fifth root of 32 is 2
//
//          Enter a dividend and divisor: 1960 56
//          The quotient of 1960 and 56 is: 35
//
//          Enter a depth: 2
//          When the depth = 2, the value is 3.72428
//
//          As the depth goes to infinity (or a larger enough number), the value = 4
//          When the depth = 16, the value = 3.99999
//          When the depth = 17, the value = 4
//          When the depth = 100, the value = 4
//

#include <iostream>
#include <math.h>
using namespace std;

// Task 1 Functions
int sumDigits(int n);

// Task 2 Functions
double root5(double n, double y);

// Task 3 Functions
int egyptDivision(int dividend, int divisor);
int doubleInt(int n);
int halveInt(int dividend, int & divisor, int quotient);

// Task 4 Functions
double ramanujan(int depth);
double ram(int depth, int n);

int main(){
    int num;
    double y = 1.0;
    int dividend, divisor;

    // Task 1 | Sum of digits 
    cout << endl;
    cout << "Enter a integer: ";
    cin >> num;
    cout << "The sum is: " << sumDigits(num) << endl;

    // Task 2 | 5th root of a number
    cout << endl;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The fifth root of " << num << " is: " << root5(num, y) << endl;
    cout << endl;

    // Task 3 | Egypt Division
    cout << "Enter a dividend and divisor: ";
    cin >> dividend >> divisor;
    cout << "The quotient of " << dividend << " and " << divisor << " is: " << egyptDivision(dividend, divisor) << endl;
    cout << endl;

    // Task 4 | Ramanujan 
    cout << "Enter a depth: ";
    cin >> num;   
    cout << "When the depth = " << num << ", the value = " << ramanujan(num) << endl << endl;

    cout << "As the depth goes to infinity (or a large enough number), the value = 4" << endl;
    cout << "When the depth = 16, the value = " << ramanujan(16) << endl;
    cout << "When the depth = 17, the value = " << ramanujan(17) << endl;
    cout << "When the depth = 100, the value = " << ramanujan(100) << endl;
    cout << endl;

    return 0;
}

int sumDigits(int num){
    if(num < 10){
        return num;
    }
    else{
        return (num % 10) + sumDigits(num / 10); 
    }
}

double root5(double n, double y){
    if(abs(y * y * y * y * y) - n > 0.00001){    
        return y - 0.00001;
    }
    else{
        return(root5(n, y + 0.00001));
    }
}

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