# b2b-shopping-cart-cop3330-group-5
b2b-shopping-cart-cop3330-group-5 created by GitHub Classroom

Objective
Your company is a major clothing manufacturer who sells to most major department and clothing stores throughout the US. 
Because of the size of your business, you extend a line of credit to all your customers.
When a customer places an order, one of your associates enters their names (the associate) into the system and then 
looks up the customer, and enters the selected items and quantities. The system should only allow the associate to create 
orders for existing customers, and only allow items to be added as long as they have not surpassed the maximum on their 
remaining line of credit.

Customer Class
You are provided a pipe delimited customer file, customer.dat. This file contains the following information:

Customer Number
Customer Name
Line of Credit
Address
This information should be read for the text file and loaded into a objects of class Customer, which is defined as follows:

    string customerNum;
    string customerName;
    double lineOfCredit;
    Address * corperateAddress;
This class should include a constructor that accepts 2 strings and a double variables and a no-argument constructor.

Note that the last data member of the class is a pointer to an Address object.

Address Class
Address is another class. You should create a vector of addresses as you read in the file. You should only create a new address 
element if it is not already in the vector. If the address is already in the vector then the pointer should use the address of that 
element. The Address data members are as follows:

    string streetAddress;
    string city;
    string state; 
    string zipCode;
This class should include a constructor that accepts all the member variables and a no-argument constructor.

Note that each time you add an element to the vector the address of the vector changes. You will need to record the addresses after
adding all addresses to the vector.

Product Class
A list of items is provided in the inventory.dat file. This file contains:

Item Number
Item Description
Unit Price
Quantity in Stock
The inventory items should also be loaded into Product objects as described below:

    int itemNo;
    string description;
    double price;
    int stockQuantity
This class should include a constructor that accepts all the member variables and a no-argument constructor.

Complete set and get functions for each data member in each class. Each class should also have a print function. 
The print function should print the object to match the output required by the driver. In the Address class this function 
should be called getAddress and return a string.

Driver
As the associate enters the items (using the item number) and quantities, the system should verify that you the customer 
still has available credit and the stock has not be depleted. The system should also verify that the associate is entering
accurate information. Once completed, the system will display a final order summary and update the stock of the items sold. 
The order summary should also be written to a file (the filename should be the order number). 


Use the following function to generate the order number.

#include <ctime>
#include<sstream>

string generateOrderNum(){
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}
