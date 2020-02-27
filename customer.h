#include<vector>
#include<string>
#include "Address.h"

class Customer
{
    std::string customerNum;
    std::string customerName;
    double lineOfCredit;
    Address * corperateAddress;
}

public:
//Constructors for Customer Class
//Object created for storing in the products class
Customer(std::string, std:string, double)

Customer();

//Vector

std::vector<Customer>cust;
std::vector<Address>addr;


//Get Functions

//Return cust num
std::string getcustomerNum();

//Get Customer Name
std::string getcustomerName();

//Get credit
double getlineOfCredit();

//Receive customer info for grabbing customer file for orders
void grabcustomer();
std::string getCustomer();

//Set Functions
void setcustomerNum(std::string);
void setcustomerName(std::string);
void setlineOfCredit(double);


