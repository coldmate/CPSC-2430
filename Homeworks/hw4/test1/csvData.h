#ifndef CVSDATA_H
#define CVSDATA_H
#include <iostream> 
using namespace std;

class cvsdata{
    private:
        string newDate;
        string newCountry;
        int newCases;
        int newDeaths;
    public:
        cvsdata(string date, string country, int cases, int deaths);
        
        string getDate();
        string getCountry();
        int getCases();
        int getDeaths();
};  
#endif