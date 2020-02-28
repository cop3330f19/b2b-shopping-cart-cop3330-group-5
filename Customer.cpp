#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include "Customer.h"

using namespace std;

Customer::Customer(string custNum, string custName, double l_c)
{
    customerNum=custNum;
    customerName=custName;
    lineOfCredit=l_c;
}
    
Customer::Customer()
{
    customerNum=""; 
    customerName="";
    lineOfCredit=0;
}

//set functions
void Customer::setCustomerNum(string custNum)
{
    customerNum=custNum;
}

void Customer::setCustomerName(string custName)
{
    customerName=custName;
}

void Customer::setLineOfCredit(double l_c)
{
    lineOfCredit= l_c;
}


//get functions
string Customer::getCustomerNum()
{
    return customerNum;
}

string Customer::getCustomerName()
{
    return customerName;
}


double Customer::getLineOfCredit()
{
    return lineOfCredit;
}


