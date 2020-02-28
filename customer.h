#include<string>
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    std::string customerNum;
    std::string customerName;
    double lineOfCredit;
    std:: string * corperateAddress;
    
    public:
    //Constructors for Customer Class
    ////Object created for storing in the products class
    
    Customer(std::string, std::string, double);
    Customer();

   
    //Get Functions
   //Return customer number
   std::string getCustomerNum();
   
   //Get Customer Name
   std::string getCustomerName();

   //Get credit
  double getLineOfCredit();
  
  //Set Functions
  void setCustomerNum(std::string);
  void setCustomerName(std::string);
  void setLineOfCredit(double);
  
  
};
#endif
