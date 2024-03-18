#include "csvData.h"
#include <iostream>
using namespace std;

cvsdata::cvsdata(string date, string country, int cases, int deaths){
    newDate = date;
    newCountry = country;
    newCases = cases;
    newDeaths = deaths;
}

// Getter Functions
string cvsdata::getDate(){
    return newDate;
}

string cvsdata::getCountry(){
    return newCountry;
}

int cvsdata::getCases(){
    return newCases;
}

int cvsdata::getDeaths(){
    return newDeaths;
}

/*
// Setter Functions
void cvsdata::setDate(string date){
    newDate = date;
}

void cvsdata::setCountry(string country){
    newCountry = country;
}

void cvsdata::setCases(int cases){
    newCases = cases;
}

void cvsdata::setDeaths(int deaths){
    newDeaths = deaths;
}
*/