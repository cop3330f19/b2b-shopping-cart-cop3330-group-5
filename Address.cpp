#include <iostream>
#include <string>
#include <iomanip>
#include "inventory.dat"
#include "Address.h"
using namespace std;

string streetAddress;
string city;
string state;
string zipCode;

Address::Address();

Address::Address(string streetAddress, string city, string state, string zipCode)
{
this->streetAddress = streetAddress;
this->city = city;
this->state = state;
this->zipCode;
}

void Address::setStreetAddress(string addr)
{
streetAddress = addr;
}

void Address setCity(string city) 
{
this->city = city;
}
void Address::setState(string state)
{
this->state = state;
}

void Address::setZipCode(string zipCode)
{
this->zipCode = zipCode;
}

string getStreetAddress(){return streetAddress;}

string getCity(){return city;}

string getState(){return state;}

string getAddress(){}
