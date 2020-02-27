#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

struct Customer
    {
        string customerNum;
        string customerName;
        double lineOfCredit;
        Address * corperateAddress;
    };

struct Address
    {
         string streetAddress;
         string city;
         string state;
         string zipCode;
    };

struct Memory
    {
        int position;
        int quantity;
        double cartTotal;
        double remainFunds;
    };

struct Product
    {
        int itemNo;
        string description;
        double price;
        int stockQuantity;
    };

