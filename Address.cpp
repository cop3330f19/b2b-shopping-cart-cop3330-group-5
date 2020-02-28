#include <iostream>
#include <string>
#include <iomanip>
#include "Address.h"
using namespace std;

string streetAddress;
string city;
string state;
string zipCode;

Address::Address(){
    streetAddress="";
    city="";
    state="";
    zipCode="";  
}

Address::Address(string addr, string c, string st, string zip)
{
    streetAddress = addr;
    city = c;
    state =st;
    zipCode=zip;
}

void Address::setStreetAddress(string addr)
{
    streetAddress = addr;
}

void Address::setCity(string c) 
{
    city = c;
}
void Address::setState(string st)
{
    state = st;
}

void Address::setZipCode(string zip)
{
    zipCode = zip;
}

string Address::getStreetAddress(){return streetAddress;}

string Address::getCity(){return city;}

string Address::getState(){return state;}

string Address::getZipCode(){return zipCode;}

