//product.h file
//Group 5- iyesha gonzalez
//2/22/20
//header file that prints product information
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product{
    
        int itemNo;
        std::string description;
        double price;
        int stockQuantity;
    
	public:
        Product(); //non-argument constructor
        Product(int, int, double,std::string); //constructor that accepts all member variables
        
        int getItemNo();
        std::string getDescription();
        double getPrice();
        int getStockQuantity();
    
    
        void setItemNo(int);
        void setDescription(std::string);
        void setPrice(double);
        void setStockQuantity(int);

	
};
#endif

